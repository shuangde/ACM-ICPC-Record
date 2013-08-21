/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-1456 Cellular Network
 *   @type:  贪心 + 概率 + dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意:
   （摘自LRJ《训练指南》）
   手机在蜂窝网络中的定位是一个基本问题。假设蜂窝网络已经得知手机处于c1, c2,…,cn这些区域中的一个，
   最简单的方法是同时在这些区域中寻找手机。但这样做很浪费带宽。由于蜂窝网络中可以得知手机在这不同
   区域中的概率，因此一个折中的方法就是把这些区域分成w组，然后依次访问。比如，已知手机可能位于5个
   区域中，概率分别为0.3、0.05、0.1、0.3和0.25，w=2，则一种方法是先同时访问{c1,c2,c3}，再同时访问
   {c4,c5}，访问区域数的数学期望为3*(0.3+0.05+0.1)+(3+2)*(0.3+0.25)=4.1。另一种方法是先同时访问
   {c1,c4}，再访问{c2,c3,c5}，访问区域数的数学期望为2×(0.3+0.3)+(3+2)×(0.05+0.1+0.25)=3.2。

思路:
   由公式可以发现，为了让总期望值最小，应该让概率大的区域尽量放在前面去访问。
   所以先把所有概率从大到小排序一遍。然后分组时，就可以取连续的一段分为一组了。

   f[i][j]表示: 前i个,分成j组的最小期望值
   f[i][j] = min{ f[k-1][j] + i*sum[k~i],  1<=k<=i}
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

const int MAXN = 110;
int n, w;
int u[MAXN];
double f[MAXN][MAXN], p[MAXN], sum[MAXN];

int main(){

    int nCase;
    scanf("%d", &nCase);
    while(nCase--){

        scanf("%d%d", &n, &w);
        int tot = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &u[i]); 
            tot += u[i];
        }


        sort(u+1, u+1+n, greater<int>());

        for(int i = 1; i <= n; ++i){
            p[i] = u[i]*1.0/tot;
            sum[i] = sum[i-1] + p[i];
        }

        for(int i = 1; i <= n; ++i){
            f[i][0] = INF;
            for(int j = 1; j <= w; ++j){
                f[i][j] = INF;
                for(int k = 1; k <= i; ++k)
                    // k~i分为一组
                    f[i][j] = min(f[i][j], f[k-1][j-1] + i*(sum[i]-sum[k-1]));
            }
        }
        printf("%.4f\n", f[n][w]); 

    }

    return 0;
}
