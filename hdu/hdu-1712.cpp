/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：hdu-1712 ACboy needs your help
 *   @type: 分组背包水题
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
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

int n, m;
int A[110][110];
int f[110];

int main(){

    while (~scanf("%d%d", &n, &m) && n+m) {
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &A[i][j]);

        memset(f, 0, sizeof(f));

        for (int i = 1; i <= n; ++i) {
            for (int v = m; v >= 1; --v) {
                for (int j = 1; j <= m && j<=v; ++j) {
                    f[v] = max(f[v], f[v-j] + A[i][j]); 
                }
            } 
        }
        printf("%d\n", f[m]); 
    }
	return 0;
}
