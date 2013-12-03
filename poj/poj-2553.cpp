
// 在强联通分量缩点后，按顺序输出所有出度为0的分量内的所有顶点
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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 5010;
const int M = 1000010;
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

int low[N], dfn[N], belong[N], sta[N], top, idx, bcnt;
bool inStack[N];
vector<int>scc[N];

void tarjan(int u) {
 //   printf("u = %d\n", u);
    low[u] = dfn[u] = idx++;
    sta[top++] = u; 
    inStack[u] = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v =  E[e].v;
        if (dfn[v] < 0) {
            tarjan(v);
            cmin(low[u], low[v]);
        } else if (inStack[v])
            cmin(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
 //       printf("find = %d\n", u);
        ++bcnt; int v;
        scc[bcnt].clear();
        do {
            v = sta[--top];
            scc[bcnt].push_back(v);
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

bool out[N];

int main() {

    int n, m;
    while (~scanf("%d", &n) && n) {

        scanf("%d", &m); 
        initAdj();
        rep(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }

        findScc(n);
        ff(i, bcnt) out[i] = true;

        ff(u, n) {
           // printf("bcnt %d\n", scc[u].size());
            for (int e = head[u]; e != -1; e = E[e].next) {
                int v = E[e].v;
                if (belong[u] != belong[v]) {
                    out[belong[u]] = 0;
                }
            }
        }

        vector<int>ans;
        ff(i, bcnt) if (out[i]){
            sort(scc[i].begin(), scc[i].end());
            for (int j = 0; j < scc[i].size(); ++j) {
                ans.push_back(scc[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        rep(i, ans.size()) {
            if (i) printf(" %d", ans[i]); 
            else printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
