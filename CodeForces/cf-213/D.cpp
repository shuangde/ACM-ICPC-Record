
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

typedef pair<bool, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 10010;
int n, d;
bool f[N*55];
int c[55];

int main () {

	while (~scanf("%d%d", &n, &d)) {
		int sum = 0;
		rep(i, n) {
			scanf("%d", &c[i]);
			sum += c[i];
		}
		memset(f, 0, sizeof(f));
		f[0] = 1;

		for (int i = 0; i < n; ++i)
			for (int j = sum; j >= c[i]; --j)
				f[j] |= f[j-c[i]];

		int own = 0, cnt = 0;
		while (true) {
			bool ok = true;
			int tmp = own + d;
			for ( ; tmp>own; --tmp)
				if (tmp<=sum && f[tmp]) {
					ok = false;
					++cnt;
					break;
				}
			if (ok || tmp==own) break;
			own = tmp;
		}
		printf("%d %d\n", own, cnt);
	}
	return 0;
}
