
// 加最少的点，使原图变成强连通图
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
using namespace std;

const int N = 20010;
const int M = 50010;

namespace Adj {

    int size, head[N];

    struct Edge {
        int v, next; 
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
}using namespace Adj; 

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


bool in[N], out[N];

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);
        initAdj();
        ff(i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }

        findScc();
        // in[i]和out[i]表示点i的入度与出度是否为0，
        for (int i = 1; i <= bcnt; ++i) in[i] = out[i] = true;
        for (int u = 1; u <= n; ++u) {
            for (int e = head[u]; e != -1; e = E[e].next) {
                int v = E[e].v;
                if (belong[u] != belong[v]) in[belong[v]] = out[belong[u]] = false;
            } 
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= bcnt; ++i) {
            if (in[i]) ++cnt1;
            if (out[i]) ++cnt2;
        }
        int ans = max(cnt1, cnt2);
        if (bcnt == 1)  ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
