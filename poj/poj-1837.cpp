/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：poj-1837 Balance
 *   @type: dp背包
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
/*
题意：
   有一个天平，天平左右两边的手臂长度都是15，手臂上面有些位置会有挂钩。还有G个砝码 (1 <= G <= 20)，它们重量各不相同，在1~25中取值。
   给出C个挂钩，它们的位置在【-15..15】，不会重叠。负号的代表在左边臂，正号的在右边。
   要求把所有砝码都放在挂钩上，多个砝码可以挂在同一个挂钩上，问有多少种不同的方案使天平能够平衡？

思路：
   天平左臂的力矩和是负数，右边的力矩和是正数，那么左边+右边的力矩之和，如果是正数，代表天平平衡倾向右边，
   负数代表倾向左边，为0的时候天平是平衡的。我们把 “左边力矩和+右边力矩和”叫做平衡系数

   状态f[i][j]代表用前i个砝码，放置成平衡系数为j的时候共有多少种方案。
   那么，f[i][j] += f[i-1][j-C[k]*G[i]],  {0<=k=<c};

   因为平衡系数中有负数的，所以要所有平衡系数往右平移，即加上一个足够大的正数。可以计算出力矩之和最小负数
   的是把所有砝码都挂在天平-15的位置上，砝码最多20个，取值最大的情况是6...25，那么砝码之和最终为 
   (6+25)*20/2 = 310, 力矩之和为 -15*310 = 4650
   所以加上4650即可，这是位置4650代表的是原来天平的中间位置，
   初始化 f[0][4650] = 1, 表示一个砝码都不挂，这是一种平衡的方案。
   最终，f[G][4650]就是答案。

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

const int MID = 11000;
int C, G; 
int pos[30];
int weight[30];

int f[2][MID*2];

int main(){

    scanf("%d%d", &C, &G);

    for(int i = 0; i < C; ++i)
        scanf("%d", &pos[i]);

    int sum = 0;
    for(int i = 0; i < G; ++i) {
        scanf("%d", &weight[i]);
        sum += weight[i];
    }

    memset(f, 0, sizeof(f));
    f[0][MID] = 1;

    int p  = 0;
    int ans = 0;
    for(int i = 0; i < G; ++i) {
        p = !p;
        memset(f[p], 0, sizeof(f[p]));
        for(int j = 0; j < C; ++j) {
            int w = weight[i] * pos[j]; 

            for(int v = -15 * sum; v <= 15 * sum; ++v) {
                int now = v + MID;
                if(f[!p][now] && now+w>=0 && now+w<MID*2){
                    f[p][now+w] += f[!p][now];
                }
            }
        }
    }
    printf("%d\n", f[p][MID]);
    return 0;
}
