
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

const int MAXN = 110;
int n, m;
int x[MAXN], y[MAXN];
int f[110];

bool ok(int t) {
	memset(f, -1, sizeof(f));
	for (int j = 0; j <= m && j*x[0]<=t; ++j)
		f[j] = (t-j*x[0])/y[0];
	if (f[m] >= m) return m;
	for (int i = 1; i < n; ++i) {
		for (int j = m; j >= 0; --j) {
			for (int k = 0; k<=j && k*x[i]<=t; ++k) if (f[j-k]!=-1)
				f[j] = max(f[j], f[j-k]+(t-x[i]*k)/y[i]);
		}
		if (f[m] >= m) return true;
	}
	return false;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int l = INF, r = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			l = min(l, min(x[i], y[i]));
			r = max(r, max(x[i], y[i]));
		}
		r *= m;
		int ans = INF;
		while (l <= r) {
			int mid = (l+r)>>1;
			if (ok(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
