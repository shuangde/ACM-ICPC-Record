/**==========================================
 *   This is a solution for ACM/ICPC problem
 *   
 *   @source: HDU 4649 Professor Tian
 *   @type:  dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

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
