
// zoj  3656 Bit Magic
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

const int N = 1010;
const int M = 1000000;

namespace Adj {
    int size, head[N];
    struct Edge{int v, next;}E[M];
    void init() {size=0, clr(head,-1);}
    void addEdge(int u, int v) { E[size].v = v; E[size].next = head[u]; head[u] = size++; }
} using namespace Adj;

int dfn[N], low[N], sta[N], belong[N], idx, top, bcnt;
bool instack[N];

void tarjan(int u) {
    dfn[u] = low[u] = idx++;
    sta[top++] = u; instack[u] = true;
    ra(e, u) {
        int v = E[e].v;
        if (dfn[v]<0) tarjan(v),cmin(low[u],low[v]);
        else if (instack[v]) cmin(low[u],dfn[v]);
    }
    if (low[u]==dfn[u]) {
        int v; ++bcnt;
        do {v=sta[--top]; instack[v]=false; belong[v]=bcnt;} while(u!=v);
    }
}
void findScc(int n) {
    idx = top = bcnt = 0;
    clr(instack, 0); clr(dfn, -1);
    rep(i, n)if(dfn[i]<0)tarjan(i);
}
bool check(int n) {
    findScc(2*n);
    rep(i, n)if(belong[i*2]==belong[i*2+1]) return false;
    return true;
}

int mat[502][502];

int cal(int i, int j, int a, int b) {
    if (i%2==1 && j%2==1) return a|b;
    else if (i%2==0 && j%2==0) return a&b;
    else return a^b;
}

int main() {

    int n;

    while (~scanf("%d", &n)) {

        rep(i, n) rep(j, n) scanf("%d",&mat[i][j]);
        bool flag = true;
        rep(k, 31) {
            init();
            rep(i, n) rep(j, n) {
                int val = (mat[i][j]>>k)&1;
                if (i == j) {
                    if (val!=0) {flag = false; break;} 
                    continue;
                }
                rep(a, 2) rep(b, 2) if (cal(i,j,a,b) != val) {
                    addEdge(i*2+!a, j*2+b);
                    addEdge(j*2+!b, i*2+a);
                }
            }
            if (!check(n)) {flag=false; break;}
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}
