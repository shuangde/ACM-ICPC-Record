/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : zoj-3201 Tree of Tree
 *   @description : 树形背包dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/31 20:16 All rights reserved. 
 *======================================================*/

/*
题意：
   给一棵节点带权的树，找到一个有k个节点的子树，求这个子树的最大权值

思路：
   树形dp+背包。
   f(i, j) 表示以i为根节点的有j个节点子树的最大权值
   然后对i的每个子节点做分组背包，因为对于i的每个儿子，可以选择分配
   1,2,3...j-1个节点给它

   f(i, j) = max{ max{f(i, j-p) + f(v, p) | 1<=p<j} | v是i的儿子节点}

   ans = max{ f[i][k] | 0<=i<n && i子树节点个数>=k }

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
int n, m;
int weight[MAXN];
int tot[MAXN];
vector<int>adj[MAXN];
int f[MAXN][MAXN];
int ans;

int dfs(int u, int fa) {
    tot[u] = 1;
    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e];
        if (v == fa) continue;
        tot[u] += dfs(v, u);
    }

    f[u][1] = weight[u];

    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e];
        if (v == fa) continue;
        for (int i = tot[u]; i >= 1; --i) {
            for (int j = 0; j < i && j <= tot[v]; ++j) {
                f[u][i] = max(f[u][i], f[u][i-j] + f[v][j]); 
            } 
        }
    }
    if (tot[u] >= m)
        ans = max(ans, f[u][m]);
    return tot[u];
}

int main(){

    while (~scanf("%d%d", &n, &m)) {

        for (int i = 0; i < n; ++i) {
            scanf("%d", &weight[i]);
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(f, 0, sizeof(f));
        ans = 0;
        dfs(0, -1);
        printf("%d\n", ans);
    }
    return 0;
}
