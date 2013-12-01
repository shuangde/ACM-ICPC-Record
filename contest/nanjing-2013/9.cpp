
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

const int N = 1010;
int arr[N];
int f[2][1010][2];
int ans[N];

const int MOD = 1000000+3;


int main() {

	int n;
	while (~scanf("%d", &n)) {

		for (int i = 1; i <= n; ++i) 
			scanf("%d", &arr[i]);

		memset(ans, 0, sizeof(ans));
		int pt = 0;

		for (int k = 0; k < 31; ++k) {
			memset(f[0], 0, sizeof(f[0]));
			f[0][0][0] = 1;
			pt = 0;
			for (int i = 1; i <= n; ++i) {
				pt = !pt;
				memset(f[pt], 0, sizeof(f[pt]));
				f[pt][0][0] = 1;
				int val = (arr[i]>>k) & 1;
				for (int j = 1; j <= i; ++j) {
					f[pt][j][0] = f[!pt][j][0];
					f[pt][j][1] = f[!pt][j][1];
					if (val) {
						f[pt][j][0] += f[!pt][j-1][1];
						f[pt][j][1] += f[!pt][j-1][0];
					} else {
						f[pt][j][0] += f[!pt][j-1][0];
						f[pt][j][1] += f[!pt][j-1][1];
					}
					f[pt][j][0] %= MOD; f[pt][j][1] %= MOD;
				}
			}
			for (int i = 1; i <= n; ++i) {
				int tmp = (((int64)f[pt][i][1])%MOD * (int64)((1<<k)%MOD))%MOD;
				ans[i] += tmp;
				ans[i] %= MOD;
			}
		}
		printf("%d", ans[1]);
		for (int i = 2; i <= n; ++i) printf(" %d", ans[i]);
		puts("");
	}
	return 0;
}
