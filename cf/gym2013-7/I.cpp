
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MAXN = 500;
int mat[MAXN][MAXN];

int sum[MAXN][MAXN];
int sum2[MAXN][MAXN];

int n;

void fuck() {
    int ans = 0;
    for (int x = 2; x <= n; ++x) {
        for (int y = 2; y <= n; ++y) {

            int ex = x, ey = y;

            //printf("x=%d, y=%d:\n", x-1, y-1);
            while (ex <= n && ey <= n) {
                int a = sum[ex][ey] - sum[x-1][y-1] - (sum[ex][ey-1] - sum[x-1][y-2]);

                int rx = x, ry = ey, rex = ex, rey = y;
                int b = sum2[rex][rey] - sum2[rx-1][ry+1] - (sum2[rex][rey-1] - sum2[rx-1][ry]);

                //   printf("%d, %d, %d, %d\n", rx, ry, rex, rey);
                //   printf("    a=%d, b=%d\n", a,b);
                ans = max(ans, a-b);
                ++ex, ++ey;
            }
        } 
    }
    printf("%d\n", ans);
}

int main(){

    while (~scanf("%d", &n)) {

        ++n;
        for (int i = 2; i <= n; ++i) 
            for (int j = 2; j <= n; ++j)
                scanf("%d", &mat[i][j]);

        memset(sum, 0, sizeof(sum));
        memset(sum2, 0, sizeof(sum2));


        for (int i = 1; i <= n; ++i) {
            int totRow = 0;
            for (int j = 1; j <= n; ++j) {
                totRow += mat[i][j];
                sum[i][j] = sum[i-1][j-1] + totRow;
                sum2[i][j] = sum2[i-1][j+1] + totRow;
            }
        }
        fuck();
    }
    return 0;
}
