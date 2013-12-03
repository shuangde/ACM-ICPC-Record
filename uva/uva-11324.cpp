
// 强连通分量缩点后，求DAG上的最长路径
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

const int N = 1010;
const int M = 50010;

namespace Adj {

    int size, head[N];

    struct Edge {
        int v, next; // 可根据题目需求变化，例如增加权值w
    }E[M*2];

    void initAdj () {
        size = 0;
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
} using namespace Adj; 

int n, m;
int dfn[N], low[N], sta[N], belong[N], idx, top, bcnt, cnt[N];
bool inStack[N];

void tarjan(int u) {
    dfn[u] = low[u] = idx++;
    sta[top++] = u;
    inStack[u] = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (dfn[v] < 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++bcnt;
        cnt[bcnt] = 0;
        int v;
        do {
            cnt[bcnt]++;
            v = sta[--top];
            inStack[v] = false;
            belong[v] = bcnt;
        } while (u != v);
    }
}

void findScc() {
    idx = top = bcnt = 0;
    memset(dfn, -1, sizeof (dfn));
    memset(inStack, 0, sizeof (inStack));
    for (int i = 1; i <= n; ++i)
        if (dfn[i] < 0) tarjan(i);
}

vector<int>adj[N];
int indeg[N];
int64 f[N];

int64 dfs(int u) {
    if (f[u] != -1) return f[u];
    f[u] = cnt[u];
    int64 tmp = 0;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        tmp = max(tmp, dfs(v));
    }
    return f[u]+=tmp;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        initAdj();
        rep(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }

        findScc();
        // 建立缩点后的新图，是DAG
        memset(indeg, 0, sizeof(indeg));
        for (int i = 1; i <= bcnt; ++i) adj[i].clear();
        for (int u = 1; u <= n; ++u) {
            for (int e = head[u]; e != -1; e = E[e].next) {
                int v = E[e].v;
                if (belong[u] != belong[v]) {
                    ++indeg[belong[v]];
                    adj[belong[u]].push_back(belong[v]);
                }
            }
        }
        memset(f, -1, sizeof(f));
        int64 ans = 0;
        for (int i = 1; i <= bcnt; ++i) if (indeg[i] == 0) {
            ans = max(ans, dfs(i));
        }
        cout << ans << "\n";
    }
    return 0;
}
