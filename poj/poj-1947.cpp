/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : poj-1947 Rebuilding Roads
 *   @description : 树形背包dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/19 14:30 All rights reserved. 
 *======================================================*/

/*
题意:
    给一棵树,问最少删掉几条边.使得剩下的子树中有节点个数为p个的

思路:
    之前不知道看到谁说这题水, 但是为什么我就不觉得水呢? 3天前就看了这题,
    但是没什么想法,然后每天都有去想一下, 一直到今天, 在我对自己方法还有怀疑
    的情况下,竟然AC了..

    f(i, j) 表示子树i,保留j个节点的最少删边次数, 注意,这里保留的j个节点的子树,是指根节点
    为i的且有j个节点的子树.这样理解的话, 状态转移就容易想多了.

    对于子树i, 如果只保留1个节点,那么连接它所有儿子节点的边都要删掉,
    所以可以初始化 f(i, 1) = 节点i的儿子个数

    f(i, j), 即子树i保留j个节点, 那么对于i的每个子树,可以选择保留1,2,..j-1个节点
    那么每个子树可以看作是一组物品,对所有子树做分组背包

    子树v选择保留k个点的话,那么子树i就要保留j-k个点.

    所以由状态转移:
    f(i, j) = max{ max{f(i,j-k) + f(v, k) - 1 | 1<=k<s} | v是i的儿子节点 }

    最终ans = min{ f(i, p) }

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

const int MAXN = 160;
vector<int>adj[MAXN];
int n, p;
int f[MAXN][MAXN], tot[MAXN];
int ans;

int dp(int u) {

    // 计算子树有几个节点
    tot[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        tot[u] += dp(v); 
    }

    // init
    f[u][1] = adj[u].size();
    // dp
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        for (int s = tot[u]; s >= 1; --s) {
            for (int j = 1; j < s && j <= tot[v]; ++j)
                f[u][s] = min(f[u][s], f[u][s-j] + f[v][j] - 1);
        }
    }
    if (tot[u] >= p)
        ans = min(ans, f[u][p] + (u!=1));
    return tot[u];
}

int main(){

    for (int i = 0; i <=n; ++i)
        adj[i].clear();

    scanf("%d %d", &n, &p);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }

    memset(f, INF, sizeof(f));
    ans = INF;
    dp(1);

    printf("%d\n", ans);
    return 0;
}
