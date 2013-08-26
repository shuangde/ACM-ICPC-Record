/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : zoj-3626 Treasure Hunt I
 *   @description : 树形dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/26 16:23 All rights reserved. 
 *======================================================*/
/*
题意：
   给一棵n个节点的树, 节点编号1~n, 每个节点有权值val[i],经过这个节点就可以获取这个价值（不能重复获得）
   每一条边有一个花费值w(i,j), 表示走完i和j点的边要花费w(i,j)
   现在要从k点出发，总花费值为m，问总花费不超过m的情况下并且最终要回到出发点，最多可以获取多少价值？

思路：
   简单树形dp。
   f(i,j)表示子树i, 用花费j最多可以获得的价值
   对与i的每个儿子，可以选择分配花费2*w, 2*w+1, 2*w+2,...j给它，可以看作是一组物品
   对所有儿子做分组背包
   f(i, j) = max{ max{ f(i, j-k) + f(v, k-2*w) | 2*w<=k<=i }  | v是i的儿子节点}
   ans = f(k, m);
 */
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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 110;
int n, k, m;
vector<PII>adj[MAXN];
int val[MAXN];
bool vis[MAXN];
int f[MAXN][2*MAXN];

void dfs(int u) {

    vis[u] = true;

    for (int i = 0; i <= m; ++i)
        f[u][i] = val[u]; 

    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e].first;
        int w = adj[u][e].second;
        if (vis[v]) continue;
        dfs(v);
        for (int i = m; i >= 0; --i) {
            for (int j = 2*w; j <= i; ++j) {
                f[u][i] = max(f[u][i], f[u][i-j] + f[v][j-2*w]);
            }
        }
    }
}

int main(){

    while (~scanf("%d", &n)) {

        // init
        for (int i = 0; i <= n; ++i)
            adj[i].clear();

        for (int i = 1; i <= n; ++i)
            scanf("%d", &val[i]);

        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(MP(v, w));
            adj[v].push_back(MP(u, w));
        }

        scanf("%d %d", &k, &m);
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
        dfs(k);
        printf("%d\n", f[k][m]);
    }
    return 0;
}
