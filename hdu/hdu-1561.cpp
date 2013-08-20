/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : hdu-1561 The more, The Better
 *   @description : 树形背包dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/20 11:27 All rights reserved. 
 *======================================================*/
/*
题目:
ACboy很喜欢玩一种战略游戏，在一个地图上，有N座城堡，每座城堡都有一定的宝物，
在每次游戏中ACboy允许攻克M个城堡并获得里面的宝物。但由于地理位置原因，有些
城堡不能直接攻克，要攻克这些城堡必须先攻克其他某一个特定的城堡。你能帮ACboy
算出要获得尽量多的宝物应该攻克哪M个城堡吗？

思路:
简单树形背包dp
题目给的是森林,那么给增加一个"根节点",指向森林中的每个树的根节点f(i, j)表示子树i,取j个的时候的最大值
i的每个子节点表示的子树是一组物品,在这个子树上可以选择取1,2,3...j-1个
那么就是对每个子节点做分组背包.

f(i, j) = max{ max{f(i, j-k)+f(v, k) | 1<=k<j && v是i的子树 } }

有个优化, 对于某个子树,它取的个数不可能超过这个子树的节点数,优化了可以到0MS

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
const double PI  = acos(-1.0);

const int MAXN = 210;
vector<int>adj[MAXN];
int val[MAXN];
int tot[MAXN];
int f[MAXN][MAXN];
int n, m;

int dfs(int u) {

    f[u][1] = val[u];

    tot[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        tot[u] += dfs(v);
    }

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        for (int s = tot[u]>m?m:tot[u]; s >= 1; --s) {
            for (int j = 1; j < s && j <= tot[v]; ++j) {
                f[u][s] = max(f[u][s], f[u][s-j] + f[v][j]); 
            }
        }
    }
    return tot[u];
}
int main(){

    while (~scanf("%d %d", &n, &m) && n + m) {

        // init
        for (int i = 0; i <= n; ++i)
            adj[i].clear();

        val[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int a;
            scanf("%d %d", &a, &val[i]);
            if (a) {
                adj[a].push_back(i); 
            } else {
                adj[0].push_back(i); 
            }
        }
        memset(f, 0, sizeof(f));
        ++m;
        dfs(0);
        printf("%d\n", f[0][m]);
    }
    return 0;
}
