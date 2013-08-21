/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-1366 Martian Mining 
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:17 All rights reserved. 
 *======================================================*/

/*
题意:
   给出n*m网格中每个格子的A矿和B矿数量，A矿必须由右向左运输，B矿必须由下向上运输，
   管子不能拐弯或者间断。要求收集到的A，B矿总量尽量大。

思路:
   由题意可知，如果格子（i，j）上选择运输A矿的话，那么i行的1~j就要全部选择A矿。
   同理，如果选择B矿，那么第j列上的1～i行要全部选择B矿

   所以推出下面的状态转移方程式：

   f[i][j][0]表示第i行第j列为右下角顶点的矩形区域内，格子(i,j)上选择运输A矿情况下的最大总和
   f[i][j][1]表示第i行第j列为右下角顶点的矩形区域内，格子(i,j)上选择运输B矿情况下的最大总和

   那么
   f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]) + sum{第i行的1～j列的A矿之和}
   f[i][j][1] = max(f[i][j-1][0], f[i][j-1][1]) + sum{第j列的1～j行的B矿之和};
   最终答案是max{f[n][m][0], f[n][m][1]}

 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 130;


int m, n;
int A[510][510], B[510][510];
int sum_row[510][510], sum_col[510][510];
int f[510][510][2];

int main(){

    while(~scanf("%d%d", &n, &m) && n+m){
        
        memset(sum_row, 0, sizeof(sum_row));
        memset(sum_col, 0, sizeof(sum_col));

        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j){
                scanf("%d", &A[i][j]);
                sum_row[i][j] = sum_row[i][j-1]+A[i][j];
            }

        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j){
                scanf("%d", &B[i][j]);
                sum_col[i][j] = sum_col[i-1][j]+B[i][j];
            }

        memset(f, 0, sizeof(f));

        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j){
                f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]) + sum_row[i][j];
                f[i][j][1] = max(f[i][j-1][0], f[i][j-1][1]) + sum_col[i][j];
            }

        printf("%d\n", max(f[n][m][0], f[n][m][1]));

    }
    return 0;
}
