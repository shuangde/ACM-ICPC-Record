// poj-3207
// 2-SAT
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define PB push_back
#define SQ ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define asc(a,b) if(a>b)swap(a,b)
#define des(a,b) if(a<b)swap(a,b)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;


const int N = 2010;
const int M = 2000000;
int size, head[N];
struct Edge{int v, next; }E[M];
void init() { size=0; clr(head,-1); }
void addEdge(int u, int v) { E[size].v = v; E[size].next = head[u]; head[u] = size++; }

int low[N], dfn[N], sta[N], belong[N], idx, top, bcnt;
bool instack[N];

void tarjan(int u) {
    dfn[u] = low[u] = idx++;
    sta[top++] = u; instack[u] = true;
    ra(e, u) {
        int v = E[e].v;
        if (dfn[v] < 0) tarjan(v), cmin(low[u], low[v]);
        else if (instack[v]) cmin(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        int v; ++bcnt;
        do {v=sta[--top]; belong[v]=bcnt; instack[v]=false; } while (u!=v);
    }
}
void findScc(int n) {
    idx = top = bcnt = 0;
    clr(dfn, -1); clr(instack, 0);
    rep(i, n) if (dfn[i]<0) tarjan(i);
}
bool check(int n) {
    findScc(2*n);
    rep(i, n) if (belong[i*2] == belong[i*2+1]) return false;
    return true;
}

int a[510], b[510];
bool isCross(int a1, int a2, int b1, int b2) {
    if (a1<b1 && a2>b1 && a2<b2) return true;
    if (a2>b2 && a1>b1 && a1<b2) return true;
    return false;
}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, m) { scanf("%d%d", &a[i], &b[i]); asc(a[i],b[i]);};
    init();
    rep(i, m) for (int j=i+1; j < m; ++j) if (isCross(a[i],b[i],a[j],b[j])){
        addEdge(2*i, 2*j+1); addEdge(2*i+1, 2*j);
        addEdge(2*j, 2*i+1); addEdge(2*j+1, 2*i);
    }
    if (check(m)) puts("panda is telling the truth...");
    else puts("the evil panda is lying again");
    return 0;
}
