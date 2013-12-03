
// 强连通分量
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

const int N = 10010;
const int M = 200010;

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

int dfn[N], low[N], sta[N], belong[N], idx, top, bcnt;
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
        int v;
        do {
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


int main() {

    while (~scanf("%d%d", &n, &m) && n + m) {
        initAdj();
        rep(i, m) {
            int u, v;scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        findScc();
        if (bcnt == 1) puts("Yes");
        else puts("No");
    }
    return 0;
}
