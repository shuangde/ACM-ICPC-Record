
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


int main() {

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int sum[3]; sum[1] = sum[2] = 0;
	rep(i, n) {
		int x;
		scanf("%d", &x);
		sum[x]++;
	}
	int ans = 0;
	if (sum[1] > m) {
		ans += sum[1] - m;
	} else {
		sum[2] -= m - sum[1];
	}
	if (sum[2] > k) ans += sum[2] - k;
	printf("%d\n", ans);
    return 0;
}
