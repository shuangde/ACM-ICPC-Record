/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-1407 Caves
 *   @description : 树形背包dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/23 14:06 All rights reserved. 
 *======================================================*/

/*
题意:
   一棵n个节点的树,树的边有正整数权,表示两个节点之间的距离.你的任务是回答这样的询问:从跟节点出发,走不超过x单位的距离,
   最多能经过多少节点?同一个节点经过多次, 只能算一个.

思路:
这题同样是多天看的, 在今天才想出解法的. 动态规划就是这么有意思 :)
遍历n个节点, 有两种情况, 第一种是遍历完之后不回到出发点, 第二种是要回到出发点. 
两种都可能会重复经过某些边, 但是显然还是第二种遍历的花费会更大
在这一题中, 遍历之后不需要回到出发点.

f(i, j, 0): 表示遍历子树i的j个节点, 不用回到i点的最少花费
f(i, j, 1): 表示遍历子树i的j个节点, 最终又回到i点的最少花费

f(i, j, 1) = min{ min{ f(i, j-k, 1) + f(v, j, 1) + 2*w | 1<=k<j }  | v是i的儿子节点}

f(i, j, 0) = min{ min{ min{f(i,j-k,1)+f(v,k,0)+w, f(i,j-k,0)+f(v,k,1)+2*w} | 1<=k<j } | v是i的儿子节点 }

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

typedef pair<int, int> PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 510;

vector<PII >adj[MAXN];
int n, q;
int tot[MAXN];
int f[MAXN][MAXN][2];
bool vis[MAXN];

int dfs(int u) {
    vis[u] = true;

    tot[u] = 1;

    // 统计子树节点个数
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        if (vis[v]) continue;
        tot[u] += dfs(v);
        vis[v] = false;
    }

    // dp
    f[u][1][0] = f[u][1][1] = 0;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        if (vis[v]) continue;
        for (int s = tot[u]; s >= 1; --s) {
            for (int j = 1; j <= tot[v] && j < s; ++j) {
                int tmp1 = f[u][s-j][1] + f[v][j][0] + w;
                int tmp2 = f[u][s-j][0] + f[v][j][1] + 2 * w;
                f[u][s][0] = min(f[u][s][0],  min(tmp1, tmp2));
                f[u][s][1] = min(f[u][s][1], f[u][s-j][1] + f[v][j][1] + 2 * w);
            }
        }
    }
    return tot[u];
}

int main(){

    int cas = 1;
    while (~scanf("%d", &n) && n) {

        // init
        for (int i = 0; i <= n; ++i)
            adj[i].clear();

        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &v, &u, &w);
            adj[u].push_back(MP(v, w));
        }

        memset(vis, 0, sizeof(vis));
        memset(f, INF, sizeof(f));
        dfs(0);

        scanf("%d", &q);
        printf("Case %d:\n", cas++);
        while (q--) {
            int d;
            scanf("%d", &d);
            for (int i = n; i >= 1; --i) {
                if (f[0][i][0] <= d) {
                    printf("%d\n", i);
                    break;
                }
            } 
        }
    }
    return 0;
}
