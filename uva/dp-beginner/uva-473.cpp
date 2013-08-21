/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-473 Raucous Rockers
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:38 All rights reserved. 
 *======================================================*/

/*
题意:
   有n首歌，每首时长Ti，要把这n首歌装进m个光盘里面，每个光盘最多能存的时长为t
   要求这些歌在光盘里面要按照所给歌的先后顺序存入，不能改变前后顺序。
   例如有4首歌，按顺序给出他们的时长：1，2，3，4.
   装入一个容量时长为10的光盘里， 可以是1，2，3或者1，3，4等，但是不能2，1，3
   问最多能存几首歌？


思路：
   用f[i][j][k]表示前i首歌，用j个光盘，且第j个光盘用了k的时间，可存的最多首歌
   当枚举到第i首歌，用到第j个光盘时，有决策以及状态转移：


   1. 选择不要存这首歌，那么有
   f[i][j][k] = max(f[i][j][k], f[i-1][j][k]);

   2. 这首歌是第j个光盘的第一首歌时，有
   f[i][j][k] = max(f[i][j][k], f[i-1][j-1][t]+1);

   3. 不是第j个光盘的第一首歌时
   f[i][j][k] = max(f[i][j][k], f[i-1][j][k-T[i]]+1);
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
const int MOD = 10007;

int n, t, m;
int T[MAXN];
int f[900][120][120];


int main(){

    int nCase;
    scanf("%d", &nCase);

    while(nCase--){
        
        scanf("%d%d%d", &n, &t, &m);
        int idx = 0, x;
        for(int i=1; i<=n; ++i){
            if(i==1) scanf("%d", &x);
            else scanf(", %d", &x);
            if(x <= t) T[++idx] = x; 
        }

        n = idx;

        memset(f, 0, sizeof(f));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                for(int k=0; k<=t; ++k){
                    f[i][j][k] = f[i-1][j][k];
                    if(k >= T[i]){
                        f[i][j][k] = max(f[i][j][k], f[i-1][j][k-T[i]]+1);
                        f[i][j][k] = max(f[i][j][k], f[i-1][j-1][t]+1);
                    }
                } 
            } 
        }
        printf("%d\n", f[n][m][t]);
        if(nCase) puts("");
    }

    return 0;
}
