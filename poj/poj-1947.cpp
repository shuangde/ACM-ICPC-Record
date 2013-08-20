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

const int MAXN = 160;
vector<int>adj[MAXN];
int n, p;
int f[MAXN][MAXN], tot[MAXN];
bool vis[MAXN];

// 计算子树节点
int dfs1(int u) {
    vis[u] = true;
    int& sum = tot[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (vis[v]) continue;
        sum += dfs1(v);
    }
    return sum;
}

void dp(int u) {
    vis[u] = true;
    f[u][tot[u]] = 0;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (vis[v]) continue;
        dp(v);
        f[u][tot[v]] = f[u][tot[u]-tot[v]] = 1;
        for (int s = 1; s <= tot[v]; ++s) {
            f[u][s] = min(f[u][s], f[v][s] + 1);      
        }
    }
    printf("%d:\n", u);
    for (int s = 1; s <= tot[u]; ++s) {
        printf("%d ", f[u][s]);
    }
    puts("\n==============");
}


int main(){

    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    dfs1(1);

    memset(f, INF, sizeof(f));
    memset(vis, 0, sizeof(vis));
    dp(1);
    
    for (int i = 1; i <= p; ++i)
        printf("%d ", f[1][i]);
    printf("%d\n", f[1][p]);
    return 0;
}
