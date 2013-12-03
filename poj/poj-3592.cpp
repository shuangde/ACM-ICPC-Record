
// 强连通分量缩点，DAG最长路
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
#define PB push_back
#define SQ ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, i) for(int i=0;i<adj[u].size();++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 2010;
const int M = N*4;

template <class T>
inline void rd(T &ret) {
    char c;  ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9') ret = ret * 10 + (c - '0'), c = getchar();
}


namespace Adj {
    int size, head[N];
    struct Edge {
        int v, next; // 可根据题目需求变化，例如增加权值w
    }E[M*2];
    void init() {
        size = 0;
        memset(head, -1, sizeof(head));
    }
    void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
} using namespace Adj; 

int dfn[N], low[N], sta[N], belong[N], val[N], tot[N], idx, top, bcnt;
bool instack[N];

void tarjan(int u) {
    low[u] = dfn[u] = idx++;
    sta[top++] = u; instack[u] = true;
    ra(e, u) {
        int v = E[e].v;
        if (dfn[v] < 0) {
            tarjan(v);
            cmin(low[u], low[v]);
        } else if (instack[v]) {
            cmin(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++bcnt;  int v;
        tot[bcnt] = 0;
        do {
            v = sta[--top];
            tot[bcnt] += val[v];
            instack[v] = false;
            belong[v] = bcnt;
        } while ( u != v);
    }
} 

void findScc(int n) {
    idx = top = bcnt = 0;
    clr(instack, 0);
    clr(dfn, -1);
    rep(i, n) if (dfn[i]<0) tarjan(i);
}

char mat[50][50];
vector<int>adj[N];
bool in[N];
int f[N];

int dfs(int u) {
    if (f[u] != -1) return f[u];
    f[u] = tot[u];
    int tmp = 0;
    rv(u,i) {
        int v = adj[u][i];
        cmax(tmp, dfs(v));
    }
    return f[u]+=tmp;
}

int main() {

    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        rep(i, n) {
           scanf("%s", mat[i]);
        }
        init();
        clr(val, 0);
        vector<int>pos;
        rep(i, n) rep(j, m) if (mat[i][j] != '#') {
            if (mat[i][j] == '*') {
                pos.PB(i*m+j);
            }
            if (mat[i][j] != '*')val[i*m+j] = mat[i][j] - '0';
            if (i+1 < n && mat[i+1][j] != '#') {
                addEdge(i*m+j, (i+1)*m+j);
            }
            if (j+1 < m && mat[i][j+1] != '#') {
                addEdge(i*m+j, i*m+j+1);
            }
        }

        rep(i, pos.size()) {
            int x, y; scanf("%d%d", &x, &y);
            if (mat[x][y] != '#') addEdge(pos[i], x*m+y);
        }

        findScc(n*m);

        ff(i, bcnt) {
            in[i] = true;
            adj[i].clear();
        }

        rep(u, n*m) ra(e, u) {
            int v = E[e].v;
            if (belong[u] != belong[v]) {
                adj[belong[u]].push_back(belong[v]);
                in[belong[v]] = false;
            }
        }
        clr(f, -1);
        printf("%d\n", dfs(belong[0]));
    }
    return 0;
}
