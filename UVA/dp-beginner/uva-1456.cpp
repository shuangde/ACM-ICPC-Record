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
f[i][j]表示: 前i个,分成j组的最小期望值
f[i][j] = min{ f[k-1][j] + i*sum[k~i],  0<k<=i}
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
