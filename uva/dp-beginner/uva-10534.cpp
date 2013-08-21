/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10534 Wavio Sequence
 *   @description : nlgn复杂度LIS
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:07 All rights reserved. 
 *======================================================*/

/*
题目大意：
   Wavio Sequence是这样的一种数字序列：
   它的长度为2*n+1, 前n+1个数字是严格递增的，后n+1个数字是严格递减的。
   然后任意给一个序列，问它的Wavio Sequence子序列最长可以是多少？

分析：
   对于第i个字符，如果我们知道0～i的最长递增序列， 并且知道i～n的最长递减序列，
   那么我们就可以知道以i为中心点的最长的Wavio Sequence。
   所以, left_up[i]表示以i为结束点的最长递增序列长度， right_down[i]表示以i为起点的最长递减序列。
   接下来就是求最长递增子序列了，用nlgn的复杂度求出这两个数组，然后枚举中点i就可以计算出答案了。
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
const int MAXN = 10010;

int n, arr[MAXN];
int left_up[MAXN], right_down[MAXN];
vector<int>vt;


int main(){

    while(~scanf("%d", &n)){

        for(int i=0; i<n; ++i)
            scanf("%d", &arr[i]);

        vt.clear();
        for(int i=0; i<n; ++i){
            if(vt.empty() || vt.back()<arr[i]){
                vt.push_back(arr[i]);
            }else{
                int pt = lower_bound(vt.begin(), vt.end(), arr[i])-vt.begin();
                vt[pt] = arr[i];
            }
            left_up[i] = vt.size();
        }

        vt.clear();
        for(int i=n-1; i>=0; --i){
            if(vt.empty() || vt.back() < arr[i]){
                vt.push_back(arr[i]);
            }else{
                int pt = lower_bound(vt.begin(), vt.end(), arr[i])-vt.begin();
                vt[pt] = arr[i];
            }
            right_down[i] = vt.size();
        }

        int ans = 0;
        for(int i=0; i<n; ++i){
            ans = max(ans, min(left_up[i], right_down[i])*2-1); 
        }
        printf("%d\n", ans);
    }

    return 0;
}
