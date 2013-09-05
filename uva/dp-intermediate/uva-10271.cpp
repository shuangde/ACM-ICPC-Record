/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-10271 Chopsticks
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *   Copyright (C) 2013/09/02 23:45 All rights reserved. 
 *======================================================*/
/*
题意：

思路：

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 5100;
int n, m;
int len[MAXN];
// 前i个筷子，j个人使用
int f[MAXN][60];

int main(){
    
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
    
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &len[i]);
        m += 8;

        sort(len+1, len+1+n, less<int>());

        memset(f, INF, sizeof(f));
        for (int i = 0; i <= n; ++i)
            f[i][0] = 0;

        int ans = INF;
        for (int i = 3; i <= n; ++i) {
            for (int j = m; j >= 1; --j) {
                f[i][j] = f[i-1][j];
                if (f[i-2][j-1] != INF)
                    f[i][j] = min(f[i][j], f[i-2][j-1] + SQ(len[i-2]-len[i-1]));
            }
            ans = min(ans, f[i][m]);
            for (int j = 1; j <= m; ++j)
                printf("%d ", f[i][j]);
            puts("");
        }
        printf("%d\n", ans);
    }
    return 0;
}
