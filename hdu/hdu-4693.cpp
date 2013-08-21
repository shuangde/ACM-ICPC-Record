/**==========================================
 *   This is a solution for ACM/ICPC problem
 *   
 *   @source: HDU 4649 Professor Tian
 *   @description: 反状态压缩dp，概率
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题目大意
   初始有一个数字A0， 然后给出A1,A2..An共n个数字，这n个数字每个数字分别有一个操作符，&，|，^
   且每个数字出现的概率是pi
   如果某个数字出现了，那么就和前面的数字用它的操作符进行位运算。
   问最终的期望值是多少？

思路
   这题官方题解说是反状态压缩，还是第一次做这种题。
   知道了怎么表示状态这题就觉得不难做了，赛后1A。

   题解官方的已经很详细了，不再累赘：
   反状态压缩——把数据转换成20位的01来进行运算
   因为只有20位，而且&,|,^都不会进位，那么一位一位地看，每一位不是0就是1，这样求出每一位是1的概率，
   再乘以该位的十进制数，累加，就得到了总体的期望。
   对于每一位，状态转移方程如下：
   f[i][j]表示该位取前i个数，运算得到j(0或1)的概率是多少。
   f[i][1]=f[i-1][1]*p[i]+根据不同运算符和第i位的值运算得到1的概率。
   f[i][0]同理。
   初始状态：f[0][0~1]=0或1（根据第一个数的该位来设置）
   每一位为1的期望 f[n][1]
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 210;

int n, m;
double f[MAXN][2];
int A[MAXN];
char O[MAXN];
double p[MAXN];

int main(){

    char op[10];
    int cas = 1;
    while(~scanf("%d", &n)){

        for(int i=0; i<=n; ++i)
            scanf("%d", &A[i]);

        for(int i=1; i<=n; ++i){
            scanf("%s", op);
            O[i] = op[0];
        }

        for(int i=1; i<=n; ++i)
            scanf("%lf", &p[i]); 

        for(int i=0; i<20; ++i)
            f[0][0] = (A[i]>>i)&1;

        double ans = 0;
        for(int i=0; i<20; ++i){
            f[0][1] = (A[0]>>i)&1;
            f[0][0] = !f[0][1];

            for(int j=1; j<=n; ++j){

                // 第j个数字不出先，0和1的概率
                f[j][0] = f[j-1][0] * p[j];
                f[j][1] = f[j-1][1] * p[j];


                // 加上出现第j个数字，0和1的概率
                if(O[j] == '^'){
                    if( (A[j]>>i) & 1 ){
                        f[j][0] += f[j-1][1]*(1-p[j]);
                        f[j][1] += f[j-1][0]*(1-p[j]);
                    } else{
                        f[j][0] += f[j-1][0]*(1-p[j]);
                        f[j][1] += f[j-1][1]*(1-p[j]);
                    }

                } else if(O[j] == '&'){
                    if( (A[j]>>i) & 1 ){
                        f[j][0] += f[j-1][0]*(1-p[j]);
                        f[j][1] += f[j-1][1]*(1-p[j]);
                    } else{
                        f[j][0] += (f[j-1][0] + f[j-1][1]) * (1-p[j]);
                        // f[j][1]: 如果用了第j个数，这里不能出现1
                    }
                } else if(O[j] == '|'){
                    if( (A[j]>>i) & 1){
                        // f[j][0]: 不能出现这种情况
                        f[j][1] += (f[j-1][0] + f[j-1][1]) * (1-p[j]);
                    } else{
                        f[j][0] += f[j-1][0] * (1-p[j]); 
                        f[j][1] += f[j-1][1] * (1-p[j]);
                    }
                }
            }
            ans = ans + f[n][1] * (1<<i);
        }

        printf("Case %d:\n%.6f\n", cas++, ans);

    }
    return 0;
}
