/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10163 Storage Keepers
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:33 All rights reserved. 
 *======================================================*/

/*
题意:
   有n个仓库，让m个人来看管。一个仓库只能由一个人来看管，一个人可以看管多个仓库。
   每个人有一个能力值pi，如果他看管k个仓库，那么所看管的每个仓库的安全值为 pi/k（向下取整）
   如果某个仓库没有人看管，那么它的安全值为0。所有仓库的安全值L = min{ 每个仓库的安全值 }
   如果雇佣一个人的工资等于他的能力值pi。
   从m个人中选择一些人雇佣，问所有仓库的安全值最高是多少，在安全值最高的情况下，求雇佣的最少价钱。


思路:
   f[i][j]表示前i个人，管理j个仓库的最大安全值。
   f[i][j] = max{ min{f[i-1][j-k], p[i]/k},  0<=k<=j && k是第i个人管理的仓库个数 }
   然后求最少价钱，
   g[i][j]表示前i个人，管理j个仓库的最大安全值下所用的最少价钱
   g[i][j] = min{ g[i-1][j-k]+p[i], p[i]/k>=f[m][n] && 0<=k<=j }
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

int n, m;
int f[110][110], g[110][110];
int p[110];

int main(){

    while(~scanf("%d%d", &n, &m) && n+m){

        for(int i=1; i<=m; ++i)
            scanf("%d", &p[i]);

        memset(f, 0, sizeof(f));

        for(int i=1; i<=m; ++i){
            f[i-1][0] = INF;
            for(int j=1; j<=n; ++j){
                f[i][j] = f[i-1][j];
                for(int k=1; k<=j; ++k){
                    f[i][j] = max(f[i][j], min(f[i-1][j-k], p[i]/k));
                }
            } 
        }

        memset(g, INF, sizeof(g));

        for(int i=1; i<=m; ++i){
            g[i-1][0] = 0;
            for(int j=1; j<=n; ++j){
                g[i][j] = g[i-1][j];
                for(int k=1; k<=j; ++k){
                    int s = p[i]/k;
                    if(s >= f[m][n]){
                        g[i][j] = min(g[i][j], g[i-1][j-k]+p[i]);
                    }
                }
            } 
        }

        printf("%d %d\n", f[m][n], f[m][n]==0?0:g[m][n]);
    }
    return 0;
}
