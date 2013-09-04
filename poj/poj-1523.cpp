/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : poj-1523 SPF
 *   @description : 图的连通性-tarjan求割点
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/04 20:15 All rights reserved. 
 *======================================================*/
/*
题意：
   给一个连通的无向图，求这个图的所有割点，并且输出各个割点和相连的边去掉之后，会变成几个连通分量

思路：
   用tarjan求割点的基础题，要求对tarjan算法的原理真正搞懂，这题就水了。


 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 1010;
int n;
bool ok;
int cnt[MAXN];

namespace Adj {
    int size, head[MAXN];
    struct Node {
        int v, next; 
    }E[MAXN*2];
    inline void initAdj() {
        size = 0;
        memset(head, -1, sizeof(head));
    } 
    inline void addEdge (int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;


namespace Tarjan {
    bool vis[MAXN];
    int dfn[MAXN], low[MAXN], idx;

    inline void initTarjan() {
        idx = 1; 
        memset(vis, 0, sizeof(vis));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
    }

    void tarjan(int u) {

        vis[u] = true;
        dfn[u] = low[u] = idx++;

        for (int e = head[u]; e != -1; e = E[e].next) {
            int v = E[e].v;
            if (vis[v]) {
                low[u] = min(low[u], dfn[v]);  
            } else {
                tarjan(v);
                low[u] = min(low[u], low[v]);
                if (u == 1) { 
                    ++cnt[u];
                    if (cnt[u] == 2) ok = true;
                }
                else if (low[v] >= dfn[u]) {
                    ok = true;
                    ++cnt[u];
                }
            }
        }
    }
}
using namespace Tarjan;

int main(){

    int cas = 1;
    int u, v;
    while (~scanf("%d", &u) && u) {

        scanf("%d", &v);
        initAdj();
        n = 0;
        n = max(n, max(u, v));
        addEdge(u, v); 
        addEdge(v, u);

        while (~scanf("%d", &u) && u) {
            scanf("%d", &v);
            n = max(n, max(u, v));
            addEdge(u, v);
            addEdge(v, u);
        }

        if (cas != 1) puts("");
        printf("Network #%d\n", cas++);

        memset(cnt, 0, sizeof(cnt));
        ok = false;
        initTarjan();
        tarjan(1);

        if (!ok) puts("  No SPF nodes");
        else {
            if (cnt[1] > 1)
                printf("  SPF node %d leaves %d subnets\n", 1, cnt[1]);
            for (int i = 2; i <= n; ++i) {
                if (cnt[i])
                    printf("  SPF node %d leaves %d subnets\n", i, cnt[i] + 1);
            }
        }
    }

    return 0;
}
