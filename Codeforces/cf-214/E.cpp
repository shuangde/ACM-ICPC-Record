
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
#define cmax(a,b) a = max(a, (b))
#define cmin(a,b) a = min(a, (b))
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n, m, k, s;
int Max[10][4], Min[10][4];
int q[100010];


int main() {

	while (~scanf("%d%d%d%d", &n, &m, &k, &s)) {

		rep(i, 10) rep(j, 4) Max[i][j] = -INF, Min[i][j] = INF;
		
		rep(i, n) rep(j, m) {
			int x; scanf("%d", &x);
			cmax(Max[x][0], -i-j); cmax(Max[x][1], -i+j); cmax(Max[x][2], i-j); cmax(Max[x][3], i+j);
			cmin(Min[x][0], -i-j); cmin(Min[x][1], -i+j); cmin(Min[x][2], i-j); cmin(Min[x][3], i+j);
		}

		int ans = 0;
		rep(i, s) {
			scanf("%d", &q[i]);
			if (!i) continue;
			int tmp = 0;
			for (int k = 0; k < 4; ++k) {
				if (q[i] == q[i-1]) {
					cmax(tmp, Max[q[i]][k]-Min[q[i]][k]);
				} else {
					cmax(tmp, Max[q[i-1]][k]-Min[q[i]][k]);
					cmax(tmp, Max[q[i]][k] - Min[q[i-1]][k]);
				}
			}
			cmax(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
