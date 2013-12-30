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

int main() {

    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    rep(i, n) {
        int x, cnt = 0;
        scanf("%d", &x);
        bool vis[20];
        memset(vis, 0, sizeof(vis));
        while (x > 0) {
            int num = x%10;
            x /= 10;
            if (num <= k && !vis[num]) {
                ++cnt;
                vis[num] = true;
            }
        }
        if (cnt == k + 1) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
