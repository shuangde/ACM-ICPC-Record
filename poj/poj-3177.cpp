
// 边双连通分量
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define SQ ((x)*(x))
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 5010;
const int M = 40010;

namespace Adj {
    int size, head[N];
    struct Edge {
        int u, v, next; 
    }E[M];
    inline void initAdj() {
        size = 0;
        memset(head, -1, sizeof(head));
    } 
    inline void addEdge (int u, int v) {
        E[size].u = u;
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
} using namespace Adj;

int n, m;

int dfn[N], low[N], idx, bcnt;
bool isBridge[M];

void tarjan(int u, int fa) {
    low[u] = dfn[u] = idx++;
    // flag用来标记u是否已经有返回过它父结点f的边，如果返回超过1次，证明有重边
    bool flag = false; 
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (!flag && v == fa) {
            flag = true;  continue;
        }
        if (dfn[v] < 0) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                isBridge[e^1] = isBridge[e] = true;
            }
        } else if (flag && v==fa || v != fa) // 重边或者回边(back edge) 
            low[u] = min(low[u], dfn[v]);
    }
} 


bool vis[N];
int belong[N], deg[N];

void findBridge() {
    idx = 0;
    memset(dfn, -1, sizeof(dfn));
    memset(isBridge, 0, sizeof(isBridge));
    // 顶点编号为1～n
    for (int i = 1; i <= n; ++i)
        if (dfn[i] < 0) tarjan(i, -1); // 之前的模板
}

// 给每个定点赋予连通分量编号
void dfs(int u) {
    belong[u] = bcnt; // 属于哪个边-双连通分量
    vis[u] = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (vis[v] || isBridge[e]) continue; //在tarjan里面
        dfs(v);
    }
}

void findEdgeBcc() {
    findBridge();
    memset(vis, 0, sizeof(vis));
    bcnt = 0; // 连通分量编号从1开始
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        ++bcnt;
        dfs(i);
    }

    // 下面是求缩点后，度数为1的顶点个数
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; ++i) {
        int e = i * 2;
        int u = E[e].u, v = E[e].v;
        if (belong[u] != belong[v]) {
            ++deg[belong[u]];
            ++deg[belong[v]];
        }
    }
}

int main() {

    scanf("%d%d", &n, &m);
    initAdj();
    rep(i, m) {
        int u, v; scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    findEdgeBcc();

    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (deg[i] == 1) {
        ++cnt; 
    }
    printf("%d\n", (cnt+1)>>1);
    return 0;
}
