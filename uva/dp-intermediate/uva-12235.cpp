/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-12235
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *   Copyright (C) 2013/08/22 22:33 All rights reserved. 
 *======================================================*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 110;

int n, k;
int f[MAXN][MAXN];
int h[MAXN];
bool vis[35];


int main(){

    h[0] = -1;
    while (~scanf("%d%d", &n, &k) && n + k) {
        
        for (int i = 1; i <= n; ++i)
            scanf("%d", &h[i]);

        f[0][0] = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            if (h[i] == h[i-1]) f[i][0] = f[i-1][0];
            else f[i][0] = f[i-1][0] + 1;

            for (int j = 1; j <= k; ++j) {
                f[i][j] = f[i-1][j-1] + !vis[h[i]]; 
            }
            vis[h[i]] = true;
        }
        for (int i = 1; i <= n; ++i) {
            printf("%d:\n", i);
            for (int j = 0; j <= k; ++j) 
                printf("%d ", f[i][j]);
            puts("");
        }
        printf("%d\n", f[n][k]);
        puts("");
    }
    return 0;
}
