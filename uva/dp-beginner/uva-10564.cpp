/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10564 Paths through the Hourglass
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:23 All rights reserved. 
 *======================================================*/

/*
题意:
   (题目给的图) 要求从第一层走到最下面一层，只能往左下或右下走，经过的数字之和为sum。
   问有多少条路径之和刚好等于S？ 如果有的话，输出字典序最小的路径。

思路:
   f[i][j][k] 代表从(i,j)点往下走到最后一层和为k的方案数
   那么，显然可以得到状态转移：
   f[i][j][k] = f[i+1][left][k-val] + f[i+1][right][k-val],  val=(i,j)格上的数字，left是往坐下走的坐标，right往右下走的坐标

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

int n, s;
int hourGlass[50][22];
int64 f[50][22][510];


void input(){
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n-i+1; ++j) 
            scanf("%d", &hourGlass[i][j]);

    for(int i=n+1; i<=2*n-1; ++i)
        for(int j=1; j<=i+1-n; ++j)
            scanf("%d", &hourGlass[i][j]); 

}

void print_path(int i, int j, int sum){
    if(i >= 2*n-1) return;
    int val = hourGlass[i][j];
    if(i<n){ 
        if(j>1 && f[i+1][j-1][sum-val]){
            printf("L");
            print_path(i+1, j-1, sum-val);
            return ;
        } 
        printf("R");
        print_path(i+1, j, sum-val);

    }else{
        if(f[i+1][j][sum-val]){
            printf("L"); 
            print_path(i+1, j, sum-val);
            return;
        } 
        printf("R"); 
        print_path(i+1, j+1, sum-val);
    }
}

int main(){

    while(~scanf("%d%d", &n, &s) && n+s){

        input();
        memset(f, 0, sizeof(f));

        // 初始化最下面一行
        for(int i=1; i<=n; ++i)
            f[2*n-1][i][hourGlass[2*n-1][i]] = 1;

        // 下半部分dp
        for(int i=2*n-2; i>=n; --i){
            for(int j=1; j<=i+1-n; ++j){
                for(int v=hourGlass[i][j]; v<=s; ++v){
                    int w = hourGlass[i][j];
                    f[i][j][v] = f[i+1][j][v-w] + f[i+1][j+1][v-w]; 
                }
            } 
        }

        // 上半部分dp
        int64 ans = 0;
        for(int i=n-1; i>=1; --i){
            for(int j=1; j<=n-i+1; ++j){
                for(int v=hourGlass[i][j]; v<=s; ++v){
                    int w = hourGlass[i][j];
                    if(j>1) f[i][j][v] += f[i+1][j-1][v-w];
                    if(j<n-i+1) f[i][j][v] += f[i+1][j][v-w];
                }
                if(i==1) ans += f[1][j][s];
            } 
        }

        cout << ans << endl;
        for(int i=1; i<=n; ++i){
            if(f[1][i][s]){
                printf("%d ", i-1); 
                print_path(1, i, s);
                break;
            }
        }
        puts("");

    }
    return 0;
}

