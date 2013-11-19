
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

typedef long long int64;
typedef pair<bool, int64 >PII;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int MAXN = 100010;
int64 p[MAXN], b[MAXN], sum[MAXN], n, m, a;

bool ok (int k) {
    int64 rest = a;
    int bp = 0;
    int i;
    for (i = n-k; i < n && bp<m; ++i, ++bp) {
        if (b[i] < p[bp]) {
            int64 tmp = p[bp] - b[i];
            if (tmp <= rest) rest -= tmp;
            else {
                return  false;
            }
        } 
    }
    return i == n;
}

int main() {

    while (cin >> n >> m >> a) {

        rep(i, n) cin >> b[i];
        rep(i, m) cin >> p[i];

        sort(b, b+n);
        sort(p, p+m);

        rep(i, m) {
            if (i) sum[i] = sum[i-1] + p[i];
            else sum[i] = p[i];
        }

        int l = 0, r = min(n, m), maxNum;
        while (l <= r) {
            int m = (l+r) >> 1;
            if (ok(m)) { l = m + 1; maxNum = m;}
            else r = m - 1;
        }
        cout << maxNum << " " << max((int64)0, sum[maxNum-1]-a)<< endl; 
    }
    return 0;
}
