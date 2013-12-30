
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

int arr[3010];
int f[3010];

int main() {

    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        ff(i, m) scanf("%d", &arr[i]); 
        sort(arr+1, arr+1+m);
        if (arr[1]==1 || arr[m]==m) puts("NO");
        else {
            f[0] = 0;
            int maxx = 0;
            for (int i = 1; i <= m; ++i) {
                if (arr[i]-1 == arr[i-1]) 
                    f[i] = f[i-1] + 1;
                else f[i] = 1;
                maxx = max(maxx, f[i]);
            }
            if (maxx >= 3)  puts("NO");
            else puts("YES");
        }
    }
    return 0;
}
