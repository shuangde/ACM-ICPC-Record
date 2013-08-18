/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：poj-1155
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *   Copyright (C) 2013/08/18 19:29 All rights reserved. 
 *======================================================*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 3010;

namespace Adj{
    int size, head[MAXN];
    struct Node {int v, next, w; }E[MAXN];
    void initAdj() { size = 0; memset(head, -1, sizeof(head)); }
    void addEdge(int u, int v, int w) {
        E[size].v = v;
        E[size].w = w;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;
/////////////////////////////

int n, m;
int val[MAXN];
int f[MAXN][MAXN];

// 返回的是有几个叶子节点
int dfs(int u) {
    // init
    for (int i = 1; i <= m; ++i)
        f[u][i] = -INF; 

    if (head[u] == -1) {
        f[u][1] = val[u]; 
        return 1;
    }

    int sum = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v, w = E[e].w;

        int numLeaf = dfs(v);
        sum += numLeaf;
        // 做分组背包
        for (int s = sum; s >= 1; --s) {
            for (int k = 0; k <= numLeaf;  ++k)
                f[u][s] = max(f[u][s], f[u][s-k] + f[v][k] + w);
        }
    }
    return sum;
}

int main(){

    while (~scanf("%d%d", &n, &m)) {
        
        initAdj();
        for (int i = 1; i <= n - m; ++i) {
            int x, v, w;
            scanf("%d", &x);
            while (x--) {
                scanf("%d%d", &v, &w);
                addEdge(i, v, -w);
            }
        }

        for (int i = n - m + 1; i <= n; ++i) {
            scanf("%d", &val[i]); 
        }
        dfs(1);
        for (int i = m; i >= 0; --i) {
            if (f[1][i] >= 0) {
                printf("%d\n", i); 
                break;
            } 
        }
    }
    return 0;
}
