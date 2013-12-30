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
#define SQ ((x)*(x))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n;
int64 A[1010][3];
int64 f[1010][8];

int main() {

    int cas = 1;
    while (~scanf("%d", &n) && n) {
        rep(i, 3) ff(j, n) {
            cin >> A[j][i];
        }

        memset(f, 0, sizeof(f));

        // 0 : 000
        // 1 : 001
        // 2 : 010
        // 3 : 011
        // 4 : 100
        // 5 : 101
        // 6 : 110
        // 7 : 111
        f[1][3] = A[1][1] * A[1][2];
        f[1][6] = A[1][0] * A[1][1];
        
        for (int i = 2; i <= n; ++i) {
            
            // 0
            for (int j = 0; j < 8; ++j)
                f[i][0] = max(f[i][0], f[i-1][j]);

            // 1
            for (int s = 0; s < 8; ++s) if (s%2==0){
                f[i][1] = max(f[i][1], f[i-1][s] + A[i][2] * A[i-1][2]);
            }

            // 2
            for (int s = 0; s < 8; ++s) if (!((s>>1)&1)) 
                f[i][2] = max(f[i][2], f[i-1][s] + A[i][1] * A[i-1][1]);
            

            // 3
            f[i][3] = max(f[i][3], f[i-1][4] + A[i-1][1] * A[i][1] + A[i-1][2] * A[i][2]);
            f[i][3] = max(f[i][3], f[i-1][0] + A[i-1][1] * A[i][1] + A[i-1][2] * A[i][2]);
            for (int s = 0; s < 8; ++s)
                f[i][3] = max(f[i][3], f[i-1][s] + A[i][2] * A[i][1]);

            // 4
            for (int s = 0; s < 8; ++s) if (!((s>>2)&1)) {
                f[i][4] = max(f[i][4], f[i-1][s] + A[i][0] * A[i-1][0]);
            }

            // 5
            f[i][5] = max(f[i][5], f[i-1][0] + A[i-1][0]*A[i][0] + A[i-1][2]*A[i][2]);
            f[i][5] = max(f[i][5], f[i-1][2] + A[i-1][0]*A[i][0] + A[i-1][2]*A[i][2]);

            // 6
            f[i][6] = max(f[i][6], f[i-1][0] + A[i-1][0]*A[i][0] + A[i-1][1]*A[i][1]);
            f[i][6] = max(f[i][6], f[i-1][1] + A[i-1][0]*A[i][0] + A[i-1][1]*A[i][1]);
            for (int s = 0; s < 8; ++s)
                f[i][6] = max(f[i][6], f[i-1][s] + A[i][0]*A[i][1]);

            // 7
            f[i][7] = max(f[i][7], f[i-1][0] + A[i-1][0]*A[i][0] + A[i-1][1]*A[i][1] + A[i-1][2]*A[i][2]);
            for (int s = 0; s < 8; ++s) if (!(s&1)) {
                f[i][7] = max(f[i][7], f[i-1][s] + A[i][0]*A[i][1] + A[i][2]*A[i-1][2]);
            }
            for (int s = 0; s < 8; ++s) if (!((s>>2)&1)) {
                f[i][7] = max(f[i][7], f[i-1][s] + A[i][1]*A[i][2] + A[i][0]*A[i-1][0]);
            }
        }

        printf("Case %d: ", cas++);
        int64 ans = -INF;
        for (int s = 0; s < 8; ++s)
            ans = max(ans, f[n][s]);
        cout << ans << endl;
    }
    return 0;
}
