
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

const int N = 100010;
bool vis[N];
void init () {
	memset(vis, 0, sizeof(vis));
	int m = (int)sqrt(N+0.5);
	for (int i = 2; i < m; ++i) {
		for (int j = i * i; j < N; j += i)
			vis[j] = true;
	}
}
char str[300];

int main() {

	init();
	while (gets(str) && strcmp(str, "0") != 0) {
		int len = strlen(str);
		int ans = -INF;
		for (int i = 0; i < len; ++i) {
			int x = 0;
			for (int j = i; j < len; ++j) {
				x = x * 10 + str[j] - '0';
				if (x > 100000) break;
				if (x > 1 && !vis[x] && x > ans) {
					ans = x;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
