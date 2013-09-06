/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10304 Optimal Binary Search Tree
 *   @description : 区间dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/06 16:37 All rights reserved. 
 *======================================================*/

/*
题意：
   给一个序列即可 S = (e1,e2,...,en),且e1<e2<..<en.要把这些序列构成一个二叉搜索树。
   二叉搜索树是具有递归性质的，且若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 若它
   的右子树不空，则右子树上所有结点的值均大于它的根结点的值。

   因为在实际应用中，被访问频率越高的元素，就应该越接近根节点，这样才能更加节省查找时间。
   每个元素有一个访问频率f(ei)，当元素位于深度为k的地方，那么花费cost(ei) = k.

   所有节点的花费和访问频率乘积之和为：
   sum = f(e1)*cost(e1) + f(e2)*cost(e2) + ... + f(en)*cost(en)

   我们叫sum值最小的二叉搜索树为最优二叉搜索树。

   按顺序给出集合序列S，和每个元素的频率f(ei)，求sum的最小值


思路：
   因为他题目给的序列是从小到大的，那么对于这个序列的任意一个ei,设ei为根节点，
   我们可以知道在序列中ei左边的所有数会构成ei的左子树，ei的右边的所有数会构成
   ei的右子树。
   那么我们就可以枚举根节点，然后选择值最小的一种方案。
   说到这里，再结合题目的数据范围，那么很容易可以想到就是区间dp了！

   设f(i, j)表示序列区间(i, j)的数构成的一棵最优二叉查找树的值，
   当枚举根节点ek时，它的左子树(wi,wi+1,..,wk-1)的所有节点的深度都会增加1,
   那么左子树增加sum(w1,w2,...wk-1)
   右子树(wk+1, wk+2,..wj)的值也会增加sum(wk+1,wk+2,...,wj).
   可以看出，那么总共会增加sum(i, j) - wk

   那么就可以推出状态转移了：
   f(i, j) = min{ f(i,k-1)+f(k+1,j)+sum(i, j) - wk | i<=k<=j}


 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 210;
int n;
int w[MAXN];
int sum[MAXN];
int f[MAXN][MAXN];


int main(){

    while (~scanf("%d", &n)) {

        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &w[i]);
            sum[i] = sum[i-1] + w[i];
        }

        memset(f, 0, sizeof(f));

        for (int d = 2; d <= n; ++d) {
            for (int l = 1; l + d - 1 <= n; ++l) {
                int r = l + d - 1;
                int ans = INF, tot = sum[r] - sum[l-1];
                for (int k = l; k <= r; ++k)
                    ans = min(ans, f[l][k-1] + f[k+1][r] + tot - w[k]);
                f[l][r] = ans;
            } 
        }
        printf("%d\n", f[1][n]);
    }
    return 0;
}
