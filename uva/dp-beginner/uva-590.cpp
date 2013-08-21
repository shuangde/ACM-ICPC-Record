/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-590 Always on the run
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:39 All rights reserved. 
 *======================================================*/

/*
思路：
   这题主要是题目比较难看懂，看懂之后就比较容易了。
   f[i][j] 表示第i天，到城市j的最少总花费
   那么可以得到状态转移：
   i=0,  f[1][j] = cost[1][j][0];
   i>0,  f[i][j] = min{f[i][j], f[i-1][k]+cost[k][j], k!=j}
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

int n, m;
int f[MAXN][12], cost[12][12][32], d[12][12];

int main(){

    int cas = 1;
    while(~scanf("%d%d", &n, &m) && n+m){

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j)if(i!=j){
                scanf("%d", &d[i][j]);
                for(int k=0; k<d[i][j]; ++k)
                    scanf("%d", &cost[i][j][k]);
            } 
        }

        memset(f, INF, sizeof(f));

        // 第一天, 只能从1出发
        for(int j=2; j<=n; ++j){
            if(cost[1][j][0])
                f[0][j] = cost[1][j][0];
        }  
        // 第一天以后
        for(int i=1; i<m; ++i){
            for(int k=1; k<=n; ++k){ 
                for(int j=1; j<=n; ++j)if(j!=k){
                    int tmp_cost = cost[j][k][i%d[j][k]];
                    if(tmp_cost) f[i][k] = min(f[i][k], f[i-1][j]+tmp_cost); 
                } 
            }
        }

        int ans = INF;
        for(int i=1; i<n; ++i)
            ans = min(ans, f[m-1][n]);

        printf("Scenario #%d\n", cas++);
        if(ans != INF){
            printf("The best flight costs %d.\n\n", ans);
        }else{
            puts("No flight possible.\n"); 
        }
    }

    return 0;
}
