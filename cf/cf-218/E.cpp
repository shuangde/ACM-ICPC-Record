
// 题意：n个站点，去掉一些，剩下k个站点。使得k个站点两两的距离和最小。

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
const LL INF_LL = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 3000010;
LL sum[MAXN];
vector<pair<LL, int> >vt;

template <class T>
inline void rd(T &ret) {
    char c;  int sgn;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
}

int main() {

    int n, k;
    rd(n);
    vt.PB(MP(-INF_LL, 0));
    ff(i, n) {
        LL x;
        rd(x);
        vt.PB(MP(x, i));
    }

    sort(vt.begin(), vt.end());
    ff(i, n) sum[i] = sum[i-1] + vt[i].first;

    LL tot = 0;
    int l, r;

    rd(k);
    ff(i, k) {
        if (i > 1) tot += vt[i].first * (i-1) - (sum[i-1]);
        tot += (sum[k] - sum[i]) - vt[i].first * (k - i);
    }

    LL ans = tot;
    l = 1, r = k;

    for (int i = k+1; i <= n; ++i) {
        tot += (vt[i].first * (k-1) - (sum[i-1] - sum[i-k]))*2; 
        tot -= (sum[i-1] - sum[i-k] - (vt[i-k].first * (k-1)))*2;
        if (tot < ans) { ans = tot; l = i - k + 1; r = i; }
    }
    for (int i = l; i <= r; ++i) printf("%d ", vt[i].second);
    return 0;
}
