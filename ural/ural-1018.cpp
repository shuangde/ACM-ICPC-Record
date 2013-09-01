/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : ural-1018 Binary Apple Tree
 *   @description : 树形dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/01 18:43 All rights reserved. 
 *======================================================*/
/*
题意：
   给一棵边有权值的二叉树，节点编号为1～n，1是根节点。求砍掉一些边，只保留q条边，这q条边构成的子树
   的根节点要求是1，问这颗子树的最大权值是多少？


思路：
   非常经典的一道树形dp题，根据我目前做过的题来看，有多道都是由这题衍生出来的。
   f(i, j) 表示子树i，保留j个节点（注意是节点）的最大权值。每条边的权值，把它看作是连接的两个节点中的儿子节点的权值。
   那么，就可以对所有i的子树做分组背包，即每个子树可以选择1,2,...j-1条边分配给它。
   状态转移为：
   f(i, j) = max{ max{f(i, j-k) + f(v, k) | 1<=k<j} | v是i的儿子} 
   ans = f(1, q+1)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int>PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 110;
vector<PII>adj[MAXN];
int n, q;
int tot[MAXN]; 
int f[MAXN][MAXN];


int dfs(int u, int fa) {
    tot[u] = 1;
    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e].first;
        if (v == fa) continue;
        tot[u] += dfs(v, u);
    }

    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e].first;
        int w = adj[u][e].second;
        if (v == fa) continue;
        for (int i = tot[u]; i > 0; --i) {
            for (int j = 1; j < i && j <= tot[v]; ++j) {
                f[u][i] = max(f[u][i], f[u][i-j] + f[v][j] + w); 
            } 
        }
    }
    return tot[u];
}


int main(){

    while (~scanf("%d%d", &n, &q)) {

        for (int i = 0; i <= n; ++i)
            adj[i].clear();

        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(MP(v, w));
            adj[v].push_back(MP(u, w));
        }
        memset(f, 0, sizeof(f));
        dfs(1, -1);
        printf("%d\n", f[1][q+1]);
    }

    return 0;
}
