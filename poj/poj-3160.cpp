
// 强联通分量缩点, DAG最长路
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
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for (int e=head[u]; e!=-1; e=E[e].next)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 30010;
const int M = 150010;
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

int low[N], dfn[N], sta[N], belong[N], idx, top, bcnt;
int val[N];
int a[N];
bool inStack[N];

void tarjan(int u) {
    low[u] = dfn[u] = idx++;
    sta[top++] = u; inStack[u] = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (dfn[v] < 0) {
            tarjan(v);
            cmin(low[u], low[v]);
        } else if (inStack[v])
            cmin(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++bcnt; val[bcnt] = 0; int v;
        do {
            v = sta[--top];
            if (a[v] > 0) val[bcnt] += a[v];
            inStack[v] = false;
            belong[v] = bcnt;
        } while ( u != v );
    }
}

void findScc(int n) {
    idx = top = bcnt = 0;
    CLR(inStack, 0);
    CLR(dfn, -1);
    ff(i, n) if (dfn[i] < 0) tarjan(i);
}

vector<int>adj[N];
bool in[N];
int f[N];

int dfs(int u) {
    if (f[u] != -1) return f[u];
    f[u] = val[u];
    int tmp = 0;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        cmax(tmp, dfs(v));
    }
    return f[u]+=tmp;
}

int main() {

    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        initAdj();
        ff(i, n) {
            scanf("%d", &a[i]);
            cmax(a[i], 0);
        }
        rep(i, m) {
            int u, v; scanf("%d%d", &u, &v);
            ++u, ++v;
            addEdge(u, v);
        }
        findScc(n);
        ff(i, bcnt) {
            in[i] = true;
            adj[i].clear();
        }
        for (int u = 1; u <= n; ++u) {
            for (int e = head[u]; e!=-1; e = E[e].next) {
                int v = E[e].v;
                if (belong[u] != belong[v]) {
                    adj[belong[u]].push_back(belong[v]);
                    in[belong[v]] = false; 
                }
            }
        }
        CLR(f, -1);
        int ans = 0;
        ff(i, bcnt) if (in[i]){
            cmax(ans, dfs(i));
        }
        printf("%d\n", ans);
        return 0;
    }
}
