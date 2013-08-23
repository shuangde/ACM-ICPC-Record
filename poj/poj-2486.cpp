/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      ：poj-2486 Apple Tree
 *   @description : 树形背包dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/23 22:17 All rights reserved. 
 *======================================================*/

/*
题意：
   给一个n个节点的树，节点编号为1~n, 根节点为1, 每个节点有一个权值。
   从根节点出发，走不超过k步，问最多可以获取多少权值？

思路：
   因为和uva-1407 caves有点相似,所以没想很久就AC了，但因为初始化问题WA了两次
   f(i, j, 0): 表示子树i，走j次，最终不用回到i点获取的最大总权值
   f(i, j, 1): 表示子树i，走j次，最终一定要回到i点获取的最大总权值

   f(i, j, 1) = min{ min{ f(i, j-k, 1) + f(v, k-2, 1) | 2<=k<j }  | v是i的儿子节点}

   if(j==1)
       f(i, j, 0) = min{ min{f(i,j-k,1)+f(v,k,0) | 1<=k<=j } | v是i的儿子节点 }
   else
       f(i, j, 0) = min{ min{ min{f(i,j-k,1)+f(v,k-1,0), f(i,j-k,0)+f(v,k-2,1)} | 1<=k<=j } | v是i的儿子节点 }

   状态转移可能有点复杂， 还是看代码更好理解。

 */
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

const int MAXN = 110;
vector<int>adj[MAXN];
int val[MAXN];
bool vis[MAXN];
int f[MAXN][MAXN*2][2];
int n, k;
int ans;

void dfs(int u) {
    vis[u] = true;

    // init
    for (int i = 0; i <= k; ++i)
        f[u][i][0] =  f[u][i][1] = val[u];

    // dp
    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e];
        if (vis[v]) continue;
        dfs(v);
        for (int i = k;  i >= 1; --i) {
            for (int j = 1; j <= i; ++j) {
                if (j == 1) {
                    int tmp1 = f[u][i-j][1] + f[v][j-1][0];
                    f[u][i][0] = max(f[u][i][0], tmp1);
                } else {
                    int tmp1 = f[u][i-j][1] + f[v][j-1][0];
                    int tmp2 = f[u][i-j][0] + f[v][j-2][1];
                    f[u][i][0] = max(f[u][i][0], max(tmp1, tmp2));
                    f[u][i][1] = max(f[u][i][1], f[u][i-j][1] + f[v][j-2][1]);
                }
            } 
        }
    }
}

int main(){

    while (~scanf("%d %d", &n, &k)) {

        for (int i = 0; i <= n; ++i)
            adj[i].clear();

        for (int i = 1; i <= n; ++i)
            scanf("%d", &val[i]);

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(vis, 0, sizeof(vis));
        memset(f, 0, sizeof(f));
        dfs(1);
        printf("%d\n", f[1][k][0]);
    }
    return 0;
}
