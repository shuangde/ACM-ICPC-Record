
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define PB push_back
#define SQ ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define asc(a,b) if(a>b)swap(a,b)
#define des(a,b) if(a<b)swap(a,b)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int f[120][120];
int sum[120], arr[120];

int main() {
    int T, cas = 1;
    scanf("%d", &T);

    while (T--) {
        int n; 
        scanf("%d", &n);
        ff(i, n) {
            scanf("%d", &arr[i]);
            sum[i] = sum[i-1] + arr[i];
        }
        memset(f, 0, sizeof(f));
        ff (i, n) for (int j = i + 1; j <= n; ++j) f[i][j] = f[j][i] = INF;

        for (int d = 1; d <= n; ++d) {
            for (int l = 1; l+d-1 <= n; ++l) {
                int r = l + d - 1;
                cmin(f[l][r], f[l+1][r] + sum[r]-sum[l]);
                cmin(f[l][r], f[l+1][r] + arr[l] * (d-1));
                for (int k = 2; k < d; ++k) {
                    cmin(f[l][r], arr[l]*(k-1) + f[l+1][l+k-1] + f[l+k][r] + (sum[r]-sum[l+k-1])*k);
                }
            } 
        } 
        printf("Case #%d: %d\n", cas++, f[1][n]);
    }
    return 0;
}
