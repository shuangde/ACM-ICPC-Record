
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

int arr[100010];
int f[100010];

int main() {
    int n;
    scanf("%d", &n);
    ff(i, n) scanf("%d", &arr[i]);
    int ans = min(2, n);
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; ++i) {
        if (arr[i] == arr[i-1] + arr[i-2]) f[i] = f[i-1] + 1;
        else f[i] = 2;
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
    return 0;
}
