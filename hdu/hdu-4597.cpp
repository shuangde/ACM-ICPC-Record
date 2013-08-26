/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : hdu-4597 Play Game
 *   @description : 区间dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/24 15:12 All rights reserved. 
 *======================================================*/

/*
题意:
   Alice和Bob玩一个游戏，有两个长度为N的正整数数字序列，每次他们两个
   只能从其中一个序列，选择两端中的一个拿走。他们都希望可以拿到尽量大
   的数字之和，并且他们都足够聪明，每次都选择最优策略。Alice先选择，问
   最终Alice拿到的数字总和是多少？

思路：
   这题应该算是区间dp吧，可以看一下这题的原型：
   其他规则都一样，但是只有一个数字序列，也是每次只能拿左右两端的一个数字，问最终Alice拿多少？ (这个可以去做uva-10891)
   只有一行数字序列可以用f(i, j)表示数字序列还剩下区间[i,j]段时开始拿，最多可以拿多少数字

   而这题只是变成了两行数字序列， 那么可以在上面的基础上，再增加两维
   变成f(i, j, k, l), 表示第一个序列剩下区间[i,j]，第二个序列剩下区间[k,l]的情况下开始拿,最多可以拿多少？
   当面临状态f(i, j, k, l) 时，你有四种选择：
   1. 选择第一行的最左边数字
   2. 选择第一行的最右边数字
   3. 选择第二行的最左边数字
   4. 选择第二行的最右边数字
   所以， f(i, j, k, l)可以由：
   f(i+1, j, k, l)
   f(i, j-1, k, l)
   f(i, j, k+1, l)
   f(i, j, k, l-1)
   这四种状态转移而来, 
   假设当前状态是Alice要选择，那么上一个状态就是Bob选择的最大值，
   为了要让Alice的最终和最大，那么就要选择上面四种状态最小的一个转，
   因为这样的话, 设sum(i, j, k, l) 表示地一个序列[i,j]段之和与第二个序列的[k,l]段之和的和。
    
   f(i, j, k, l) = sum(i, j, k, l) -
       min{
           f(i+1, j, k, l)
           f(i, j-1, k, l)
           f(i, j, k+1, l)
           f(i, j, k, l-1)
         }

 */
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


        // init
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
