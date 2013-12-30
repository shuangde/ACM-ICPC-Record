
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

const int MAXN = 200000;
int n, k;
int64 sum[MAXN], arr[MAXN];

int solve() {
    int min_pos;
    int64 min_sum = INF*2;
    for (int i = k; i <= n; ++i) {
        int64 tmp = sum[i] - sum[i-k];
        if (tmp < min_sum) {
            min_sum = tmp;
            min_pos = i-k+1;
        }
    }
    return min_pos;
}
int main() {

    while (~scanf("%d%d", &n, &k)) {
        sum[0] = 0;
        ff(i, n) {
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }
        cout << solve() << endl;
    }
    return 0;
}
