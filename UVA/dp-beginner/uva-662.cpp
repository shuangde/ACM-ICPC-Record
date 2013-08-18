/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-662 Fast Food
 *   @type:  dp
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

const int MAXN = 210;
int n, k;
int d[MAXN], f[MAXN][35], sum[MAXN][MAXN];
int mark[MAXN][MAXN], mid[MAXN][MAXN];
int idx;


void print(int i, int j) {

    if (i < 1 || j < 1) return;

    print(mark[i][j] - 1, j - 1);

    printf("Depot %d at restaurant %d serves restaurant", idx++, mid[mark[i][j]][i]);

    if (mark[i][j] == i) {
        printf(" %d\n", i);
    } else {
        printf("s %d to %d\n", mark[i][j], i);

    }
}

int main() {

    int cas = 1;
    while (~scanf("%d%d", &n, &k) && n + k) {

        for (int i = 1; i <= n; ++i)
            scanf("%d", &d[i]);

        memset(sum, 0, sizeof (sum));

        for (int i = 1; i <= n; ++i) {
            mid[i][i] = i;
            for (int j = i + 1; j <= n; ++j) {
                int m = (j + i) >> 1;
                mid[i][j] = m;
                for (int k = i; k <= j; ++k) {
                    sum[i][j] += abs(d[k] - d[m]);
                }
            }
        }


        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                f[i][j] = INF;

        memset(f[0], 0, sizeof (f[0]));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j) {
                for (int k = 1; k <= i; ++k) {
                    int tmp = f[k - 1][j - 1] + sum[k][i];
                    if (tmp <= f[i][j]) {
                        mark[i][j] = k;
                        f[i][j] = tmp;
                    }
                }
            }

        printf("Chain %d\n", cas++);
        idx = 1;
        print(n, k);
        printf("Total distance sum = %d\n\n", f[n][k]);
    }

    return 0;
}
