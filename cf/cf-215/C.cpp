
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
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n, m;
int64 sum[100010];

int main() {

	while (~scanf("%d%d", &n, &m)) {
		vector<PII>vt;
		rep(i, m) {
			int q, w;
			scanf("%d%d", &q, &w);	
			vt.push_back(MP(w, q));
		}

		sort(vt.begin(), vt.end(), greater<PII>());

		int64 l = 0, r = m;
		while (l <= r) {
			int64 mid = (l+r) >> 1;
			int64 tmp;
			if (mid&1) tmp = mid*(mid-1)/2+1;
			else tmp = mid*(mid-1)/2+(mid-2)/2+1;
			if (tmp <= n) l = mid + 1;
			else r = mid - 1;
		}
		int64 ans = 0;
		rep(i, r)  ans += vt[i].first;
		cout << ans << endl;
	} 
    return 0;
}
