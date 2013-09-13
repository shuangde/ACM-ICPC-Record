/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10688 The Poor Giant
 *   @description : 区间dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/13 12:23 All rights reserved. 
 *======================================================*/
/*
题意：
有n个苹果，和一个数k，第i个苹果的重量是k+i(1<=i<=n). 已知其中只有一个苹果是甜的，
所有比它重量轻的都是苦的，比它重的都是酸的。

为了要找出甜的苹果，就要去一个一个地吃它，且吃了咬了苹果就必须把它吃完，不管苹果是苦的还是酸的。
我们可以选择一个最佳策略，为了找到甜苹果吃总重量最少。
假设n=4, k=0,那么4个苹果的重量为1,2,3,4，假设先吃 #2个苹果，
如果#1是甜的，那么吃了2时就是酸的，那么就可以确定1是甜的了，共吃重量=2
如果#2是甜的，那么吃的重量=2
如果#3是甜的，那么2是酸的，可以推测甜的在（3,4）中的一个，然后吃3, 就可以确定哪个是甜的，共吃重量=2+3=5
如果#4是甜的，那么方案和上面一样，共吃重量=5
其实就类似二分法。
总共重量 = 2+2+5+5 = 14

(下面这一段原题题目描述有误，下面是正确的)
但这不是最佳方案，因为还可以有总重量更少的。

例如，先吃#1, 
如果#1是甜的，花费1
如果#2是甜的，那么选择吃#3，不管#3是什么味道，都可以推测出#2和#4的味道，那么花费1+3
如果#3是甜的，第二次选择吃#3, 共花费1+3 = 4
如果#5是甜的，方案和上面一样, 共花费1+3 = 4
总共1+4+4+4 = 13，这方案更好。

给出n和k，问最少的吃的总重量是多少？

思路：
明显的区间dp，不过因为题目描述有错误的地方（也怪自己没仔细看），结果很久没搞懂题意。
f(i, j)表示第i个到第j个的最佳方案下的总重量。
对于f(i, j)，可以选择i~j之间的其中一个mid先吃，然后确定mid的左右区间(i, mid-1)和(mid+1, j)的区间。
如果先吃了mid，那么确定左右区间的每一个苹果，都要增加第mid个苹果的重量，所以:
f(i, j) = min{ f(i, mid-1)+f(mid+1, j) + weight[mid]*(j-i+1) | i<=mid<=j}

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MAXN = 610;

int f[MAXN][MAXN];
int val[MAXN];
int n, k;


int main(){

    int nCase, cas=1;
    scanf("%d", &nCase);

    while (nCase--) {
    
        scanf("%d%d", &n, &k);

        for (int i = 1; i <= n; ++i)
            val[i] = k + i;

        memset(f, 0, sizeof(f));

        for (int d = 2; d <= n; ++d) {
            for (int l = 1; l + d -1 <= n; ++l) {
                int r = l + d - 1;
                int& ans = f[l][r] = INF;
                for (int mid = l; mid <= r; ++mid) {
                    ans = min(ans, f[l][mid-1] + val[mid] * d + f[mid+1][r]);
                }
            } 
        }
        printf("Case %d: %d\n", cas++, f[1][n]);
    }

	return 0;
}
