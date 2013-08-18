/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：hdu-3496
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

const int MAXN = 110;

int n, m, l;

struct Node{
    int t, val;
}A[MAXN];

int f[1010][MAXN];

/*
f(i, j, k):前i个，花j时间，看k片的最大值
f(i, j, k) = max{ f(i-1, j, k), f(i-1, j-t[i], k-1)+val[i] }
*/

int main(){

    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {

        scanf("%d%d%d", &n, &m, &l);
        
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &A[i].t, &A[i].val); 
        }

        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            for (int v = l; v >= A[i].t; --v) {
                for (int j = m; j >0; --j) {
                    if(j==1 || f[v-A[i].t][j-1]) {
                        f[v][j] = max(f[v][j], f[v-A[i].t][j-1]+A[i].val); 
                    }
                } 
            }
        }
        printf("%d\n", f[l][m]);

    }

    return 0;
}
