
// 2-SAT + 二分
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

const int N = 5110;
const int M = 2000000;

namespace Adj {
    int size, head[N];
    struct Edge{int v, next; }E[M];
    void init() {size=0; clr(head,-1);}
    void addEdge(int u, int v) {E[size].v=v;E[size].next=head[u];head[u]=size++;}
}using namespace Adj;

int dfn[N], low[N], sta[N], belong[N], idx, top, bcnt;
bool instack[N];

void tarjan(int u) {
    low[u] = dfn[u] = idx++;
    sta[top++] = u; instack[u] = true;
    ra(e, u) {
        int v = E[e].v;
        if (dfn[v] == -1) tarjan(v), cmin(low[u], low[v]);
        else if (instack[v]) cmin(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])  {
        ++bcnt; int v;
        do {v=sta[--top]; instack[v]=false; belong[v]=bcnt; } while(u!=v);
    }
}

void findScc(int n) {
    idx = top = bcnt = 0;
    clr(instack, 0);
    clr(dfn, -1);
    rep(i, n) if (dfn[i]==-1) tarjan(i);
}

bool check(int n) {
    findScc(2*n);
    rep(i, n) if(belong[2*i]==belong[2*i+1]) return false;
    return true;
}

int bl[N], p[N][2], door[N][2], id[N];

int main() {

    int n, m;
    while (~scanf("%d%d", &n, &m) && n+m) {

        rep(i, n) {
            scanf("%d%d",&p[i][0], &p[i][1]); 
            bl[p[i][0]] = i;
            bl[p[i][1]] = i;
            id[p[i][0]] = 2*i;
            id[p[i][1]] = 2*i + 1;
        } 

        rep(i, m) scanf("%d%d", &door[i][0], &door[i][1]);
        int l = 0, r = m, ans=1;

        while (l <= r) {
            int mid = (l+r)>>1;
            init();
            rep(i, mid) {
                int p1 = bl[door[i][0]], p2 = bl[door[i][1]];
                if (door[i][0] == door[i][1]) {
                    addEdge(id[door[i][0]]^1, id[door[i][0]]);
                    continue;
                }
                if (p1 == p2) continue;
                addEdge(id[door[i][1]], id[door[i][0]]^1); addEdge(id[door[i][0]], id[door[i][1]]^1);
            }
            if (check(n)) l = mid + 1, ans = mid;
            else r = mid - 1;
        } 
        printf("%d\n", ans);
    }
    return 0;
}
