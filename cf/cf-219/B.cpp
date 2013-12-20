
// 题意： 定义S(x)为x的位数，求一个序列m, m+1, m+2 ..., 从m开始按顺序增加这个序列，
// 每增加一个数mi, 就要花费S(mi)*k，问最多花费不超过w，序列可以多长？

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
#include <bitset>
#include <ext/rope>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
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
using namespace __gnu_cxx;

typedef pair<int, int >PII;
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

LL x[18], y[18], num[18], sum[18];
LL w, m, k;

inline int S(LL x) {
    int cnt = 0;
    while (x > 0) ++cnt, x/=10;
    return cnt;
}

void init () {
    x[1] = 1, y[1] = 9, num[1] = 9, sum[1] = 9;
    for (int i = 2; i <= 17; ++i) {
        x[i] = x[i-1] * 10;
        y[i] = y[i-1] * 10 + 9;
        num[i] = y[i] - x[i] + 1;
        sum[i] = sum[i-1]  + num[i] * i;
    }
}

inline LL getSum(LL x) {
    int len = S(x);
    LL ret = sum[len-1];
    LL base = 1;
    rep(i, len-1) base *= 10;
    ret += (x-base+1)*len;
    return ret;
}

inline bool ok (LL m, LL n) {
    LL tmp = getSum(n) - getSum(m-1);
    return tmp * k >= 0 && tmp * k <= w;
}

int main() {

    init();
    while (cin >> w >> m >> k) {

        LL l = 0, r = w/S(m), ans = 0;
        while (l <= r) {
            LL mid = (l + r) >> 1;
            if (ok(m, m+mid-1)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
