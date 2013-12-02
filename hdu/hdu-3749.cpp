
// 点双连通分量（重连通分量，块）
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
#include <stack>
#include <set>
#define MP make_pair
#define SQ ((x)*(x))
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
using namespace std;

typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int MAXN = 5010;
const int M = 20010;
int n, m, q;
namespace Adj {
    int size, head[MAXN];
    struct Edge {
        int v, next; 
    }E[M];
    inline void initAdj() {
        size = 0;
        memset(head, -1, sizeof(head));
    } 
    inline void addEdge (int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
} using namespace Adj;

int f[MAXN];

int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}

inline void merge(int x, int y) {
    int a=find(x),b=find(y);
    if (a!=b) f[a] = b;
}


typedef pair<int,int>PII;
int dfn[MAXN], low[MAXN], bccno[MAXN], idx, bcnt; // bccno主要使用来判重的
vector<int>bcc[MAXN];    // bcc是存每个块拥有的所有顶点
vector<int>belong[MAXN]; // belong[u]是存点u属于哪些块（割点可以属于多个块）
stack<PII>st;  // 存边

void tarjan(int u, int fa) {
    low[u] = dfn[u] = idx++;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (dfn[v] < 0) {
            st.push(make_pair(u, v));
            tarjan(v, u); 
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                ++bcnt; 
                bcc[bcnt].clear();
                while ( true ) {
                    PII x = st.top(); st.pop();
                    if (bccno[x.first] != bcnt) {
                        bcc[bcnt].push_back(x.first);
                        bccno[x.first] = bcnt;
                        belong[x.first].push_back(bcnt);
                    }
                    if (bccno[x.second] != bcnt) {
                        bcc[bcnt].push_back(x.second);
                        bccno[x.second] = bcnt;
                        belong[x.second].push_back(bcnt);
                    }
                    if (x.first == u && x.second == v) break;
                }
            }
        } else if (v != fa && dfn[v] < dfn[u]) {
            st.push(make_pair(u, v));
            low[u] = min(low[u], dfn[v]);
        }
    }
}
void findBcc() {
    idx = bcnt = 0;
    while (!st.empty()) st.pop();
    memset(dfn, -1, sizeof(dfn));
    memset(bccno, 0, sizeof(bccno));
    for (int i = 0; i < n; ++i)
        if (dfn[i] < 0) tarjan(i, -1);
}


void init () {
    initAdj();
    for (int i = 0; i < n; ++i) {
        f[i] = i;
        belong[i].clear();
    }
}

int main() {

    int cas = 1;
    while (~scanf("%d%d%d", &n, &m, &q) && n+m+q) {

        printf("Case %d:\n", cas++);

        init();
        rep(i, m) {
            int u, v; scanf("%d%d", &u, &v);
            merge(u, v);
            addEdge(u, v);
            addEdge(v, u);
        }

        findBcc();

        rep(i, q) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (find(u) != find(v))
                puts("zero");

            else {
                bool ok = false;
                int bc;

                for (int i = 0; i < belong[u].size(); ++i) {
                    if (binary_search(belong[v].begin(), belong[v].end(), belong[u][i]))  {
                        bc = belong[u][i];
                        ok = true;
                        break;
                    }
                }
                if (ok && bcc[bc].size() > 2) puts("two or more");
                else puts("one");
            }
        }
    }
    return 0;
}
