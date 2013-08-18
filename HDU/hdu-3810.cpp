/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：hdu-3810
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

const int MAXN = 55;
int n, m;

struct Node {
    int t, val;
}A[MAXN];

bool g[MAXN][MAXN];
int f[MAXN];

int main(){

    int nCase;
    scanf("%d", &nCase);
    while(nCase--) {
          
        memset(g, 0, sizeof(g));
        for(int i = 1, k; i <= n; ++i) {
            scanf("%d%d%d", &A[i].t, &A[i].val, &k); 
            for(int j = 0, v; j < k; ++j) {
                scanf("%d", &v); 
                g[i][v] = true;
            }
        }
    }
	return 0;
}
