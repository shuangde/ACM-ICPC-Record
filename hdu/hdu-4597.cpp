/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : hdu-4597 Play Game
 *   @description : 区间dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/24 17:12 All rights reserved. 
 *======================================================*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[22], b[22];
int f[22][22][22][22];
int sum[22][22][22][22], sum1[22], sum2[22];


int dfs(int a1, int a2, int b1, int b2) {
    int& ans = f[a1][a2][b1][b2];
    int now = sum[a1][a2][b1][b2];
    if (a1 > a2 && b1==b2 || b1 > b2 && a1 == a2)
        ans = now;
    if (ans != -1) return ans;
    ans = 0;
    if (a1 <= a2) {
        ans = max(ans, now - min(dfs(a1+1, a2, b1, b2), dfs(a1, a2-1, b1, b2)));
    }
    if (b1 <= b2) {
        ans = max(ans, now - min(dfs(a1, a2, b1+1, b2), dfs(a1, a2, b1, b2-1)));
    }
    return ans;
}

int main() {

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum1[i] = sum1[i-1] + a[i];
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
            sum2[i] = sum2[i-1] + b[i];
        }

        memset(sum, 0, sizeof(sum));

        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = j; k <= n; ++k){
                    int tmp = sum2[k] - sum2[j-1];
                    sum[i+1][i][j][k] = tmp;
                    tmp = sum1[k] - sum1[j-1];
                    sum[j][k][i+1][i] = tmp;
                }
            } 
        }

        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                    for (int l = k; l <= n; ++l)
                        sum[i][j][k][l] = sum1[j]-sum1[i-1]+sum2[l]-sum2[k-1];

        memset(f, -1, sizeof(f));
        cout << dfs(1, n, 1, n) << endl;
    }
    return 0;
}
