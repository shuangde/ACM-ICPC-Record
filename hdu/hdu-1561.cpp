/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : hdu-1561
 *   @description :
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/20 11:27 All rights reserved. 
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
