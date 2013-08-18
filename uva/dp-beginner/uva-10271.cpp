/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-10271 Chopsticks
 *   @type:  dp
 *   @author: shuangde *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#define POW(x) ((x)*(x))
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

int f[1010][5010];
int L[5010];
int k, n;


int main(){

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        
        scanf("%d%d", &k, &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &L[i]);
    
        memset(f[0], 0, sizeof(f[0]));

        for(int i = 1; i <= k+8; ++i) {
            for(int j = 3*i; j <= n; ++j) {
                int& ans = f[i][j] = INF;
                for(int k = j - 1; k-2 >= (i-1)*2; --k) {
                    ans = min(ans, f[i-1][k-2] + POW(L[k]-L[k-1]));
                }
                printf("(%d,%d)%d ",i,j, f[i][j]);
            } 
            puts("");
        }
        printf("%d\n", f[k+8][n]);
    }

	return 0;
}
