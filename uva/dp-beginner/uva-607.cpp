/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-607 Scheduling Lectures
 *   @description : 线性dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:41 All rights reserved. 
 *======================================================*/

/*
题目大意：
   你在一所学校教书，每节课时长L，你有n个主题必须要讲完，每个主题时常为ti。
   有两个限制：1，每个主题只能在一节课内讲完，不能分开在多节课；2，必须按主题顺序讲，不能打乱。
   对于每节课，讲完主题的内容会剩下时间t，如果t>10，会产生不满意度(t-10)^2，如果 1<=t<=10, 
   学生很高兴，所以产生不满意度是负数的-C，如果t=0, 那么不满意度为0.
   问讲完所有主题，最少要用多少节课？如果有多种方案，要求不满意度最低。

分析：
   num[i]表示讲完第i个主题，所用的最少节课
   idx[i]表示讲完i个主题，用了num[i]节课的最低不满意度

   对num进行dp求最少节课,对数组初始化INF
   num[i] = min{num[k]+DI(k,i), 1<=k<=i}
   在根据情况保存idx数组
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

int n, L, C, t[MAXN];
int num[MAXN], idx[MAXN], sum[MAXN];


int getDI(int tt){
    if(tt==0) return 0;
    else if(tt>=1 && tt<=10) return -C;
    else return (tt-10)*(tt-10);
}

int main(){

    int cas = 1;
    while(~scanf("%d", &n) && n){

        scanf("%d%d", &L, &C);
        for(int i=1; i<=n; ++i){
            scanf("%d", &t[i]);
            sum[i] = sum[i-1] + t[i];
        }



        for(int i=1; i<=n; ++i){
            num[i] = idx[i] = INF;

            for(int j=1; j<=i; ++j){
                if(sum[i]-sum[j-1] <= L){

                    int DI = getDI(L-(sum[i]-sum[j-1]));

                    if(num[j-1]+1 < num[i]){
                        num[i] = num[j-1] + 1;
                        idx[i] = idx[j-1] + DI;
                    }else if(num[j-1]+1 == num[i]){
                        idx[i] = min(idx[i], idx[j-1]+DI); 
                    }
                }
            }
        }
        if(cas!=1) puts("");
        printf("Case %d:\n", cas++);
        printf("Minimum number of lectures: %d\n", num[n]); 
        printf("Total dissatisfaction index: %d\n", idx[n]);
    }

    return 0;
}

