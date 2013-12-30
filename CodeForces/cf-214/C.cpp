
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

int n, k;
int a[110], b[110];
int f[2][1000010], g[1000010];

int main() {


	while (~scanf("%d%d", &n, &k)) {

		rep(i, n) scanf("%d", &a[i]);
		int l = 0, r = 0;
		rep(i, n) {
			int x; scanf("%d", &x);
			b[i] = a[i] - x*k;
			if (b[i] < 0) l += b[i];
			else r += b[i];
		}

		memset(f, -1, sizeof(f));
		f[0][-l] = 0;
		int pt = 0;

		for (int i = 0; i < n; ++i) {
			pt = !pt;
			for (int j = r-l; j-l >= 0; --j) {
				f[pt][j] = f[!pt][j];
				if (j-l>=b[i] && f[!pt][j-b[i]] != -1) 
					f[pt][j] = max(f[pt][j], f[!pt][j-b[i]]+a[i]);
			}
		}
		printf("%d\n", f[pt][-l]==-1||f[pt][-l]==0 ? -1 : f[pt][-l]);

		/*
		solution 2:

		vector<PII>pos, neg;
		int sumPos=0, sumNeg=0, ans = 0;

		rep(i, n) scanf("%d", &a[i]);
		rep(i, n) {
			scanf("%d", &b[i]), b[i] *= k;
			int tmp = a[i] - b[i];
			if (tmp == 0) ans += a[i];
			else if (tmp < 0) {
				neg.push_back(MP(-tmp, a[i]));
				sumNeg += (-tmp);
			} else {
				sumPos += tmp;
				pos.push_back(MP(tmp, a[i]));
			}
		}

		for (int i = 0; i <= sumPos; ++i) f[i] = -INF; f[0] = 0;
		for (int i = 0; i <= sumNeg; ++i) g[i] = -INF; g[0] = 0;

		for (int i = 0; i < pos.size(); ++i) 
			for (int j = sumPos; j >= pos[i].first; --j) 
				if (f[j-pos[i].first] >= 0)
					f[j] = max(f[j], f[j-pos[i].first]+pos[i].second);

		for (int i = 0; i < neg.size(); ++i)
			for (int j = sumNeg; j >= neg[i].first; --j)
				if (g[j-neg[i].first] >= 0)
					g[j] = max(g[j], g[j-neg[i].first]+neg[i].second);

		int maxx = 0;
		for (int i = 0; i <= sumNeg && i <= sumPos; ++i) 
			if (f[i]>=0 && g[i]>=0) maxx = max(maxx, f[i]+g[i]);
		ans += maxx;

		if (ans == 0) puts("-1");
		else printf("%d\n", ans);
		*/
	}
	return 0;
}
