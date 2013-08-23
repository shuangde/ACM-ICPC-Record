/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-10003 Cutting Sticks
 *   @type: 区间dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意：
   一根长为l的木棍，上面有n个"切点"，每个点的位置为c[i]
   要按照一定顺序把每个点都砍段，最后变成了n+1段
   每砍一次，就会有一个花费，例如长度为10,“切点”为2,那么砍完后会变成两段2,8, 那么花费为2+8=10
   如果有多个“切点”，那么不同顺序切会得到不同的花费。
   问最小花费是多少？

思路：
   注意要增加一个c[n] = l
   f(i, j) 表示(i,j)区间的最小花费
   f(i, j) = min{ f(i,k)+f(k+1,j)+c[r]-c[l-1] | l<=k<k }

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

const int MAXN = 55;
int l, n;
int c[MAXN];
int f[MAXN][MAXN];


int main(){

    while (~scanf("%d %d", &l, &n) && l) {

        for (int i = 0; i < n; ++i)
            scanf("%d", &c[i]);

        c[n] = l;

        for (int d = 2; d <= n+1; ++d) {
            for (int l = 0; l + d -1 <= n; ++l) {
                int r = l + d - 1;
                int& ans = f[l][r] = INF;
                for (int k = l; k < r; ++k) {
                    ans = min(ans, f[l][k]+f[k+1][r]+c[r]-c[l-1]);
                }
            } 
        }

        printf("The minimum cutting is %d.\n", f[0][n]);
    }
    return 0;
}
