// 题意：给一个n*m矩阵，里面有D,I,M,A四个字母，从某个D开始走，按照DIMA的顺序，
// 即D->I->M->A->D->I...。问最多可以数出几个完整的"DIMA"？ 注意有环的情况。
// 思路：按照那个路径进行建图，边的权值，如果是D->I则是1,其他的为0,然后再添加一个
// 虚拟节点，加边连接虚拟节点到所有的D，然后直接记忆化搜索DAG最长路。
// 注意只要有环，就直接返回INF.有环的判断方法：用vis标记走过的路，如果发现下一个点是走过的，则有环
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
#define SQ(x) ((x)*(x))
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
const double eps = 1e-8;

const int N = 1010;
const int M = 8000000;
const int INF = N*N;
int n, m;
char mat[N][N];

namespace Adj {
    struct Edge {
        int v, w, next;
    } E[M];
    int size, head[N*N];

    void init() {
        size = 0;
        memset(head, -1, sizeof (head));
    }

    void addEdge(int u, int v, int w) {
        E[size] = (Edge){v, w, head[u]};
        head[u] = size++;
    }
}using namespace Adj;

inline int idx(int i, int j) {return i*m+j;}

inline bool ok(const char a, const char b) {
    return (a=='D' && b=='I' || a=='I'&&b=='M' || 
            a=='M'&&b=='A' || a=='A' && b=='D');
}

int d[N*N];
bool vis[N*N];

int dfs(int u) {
    if (d[u] != -1) return d[u];
//    printf("%d\n", u);
    vis[u] = true;
//    if (d[u] == -1)d[u] = 0;
    d[u] = 0;
    int maxx = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v, w = E[e].w; 
        if (vis[v]) return INF;
        cmax(maxx, dfs(v)+w);
    }
    vis[u] = false;
    return d[u] += maxx;
}

int main() {

    while (~scanf("%d%d", &n, &m)) {
        init();
        rep(i, n) scanf("%s", mat[i]);

        vector<int>vt;
        rep(i, n) rep(j, m) {
            if (mat[i][j] == 'D') vt.PB(idx(i, j));
            if (i-1>=0 && ok(mat[i][j], mat[i-1][j])) 
                addEdge(idx(i,j), idx(i-1, j), (mat[i-1][j]=='A'));
            if (i+1<n && ok(mat[i][j], mat[i+1][j])) 
                addEdge(idx(i,j), idx(i+1, j), (mat[i+1][j]=='A'));
            if (j-1>=0 && ok(mat[i][j], mat[i][j-1])) 
                addEdge(idx(i,j), idx(i,j-1), (mat[i][j-1]=='A'));
            if (j+1<m && ok(mat[i][j], mat[i][j+1])) 
                addEdge(idx(i,j), idx(i, j+1), (mat[i][j+1]=='A'));
        }

        int size = vt.size();
        rep(i, size) {
            addEdge(n*m, vt[i], 0);
        }

        clr(d, -1); clr(vis, 0);
        int res = dfs(n*m);
   //     rep(i, n*m+1) printf("%d\n", d[i]);
        if ( res >= INF) puts("Poor Inna!");
        else if (res==0) puts("Poor Dima!");
        else printf("%d\n", res);
    }
    return 0;
}
