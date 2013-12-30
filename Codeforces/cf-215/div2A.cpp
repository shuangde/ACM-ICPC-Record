
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

int sum[110];
int a[110];

int main() {

	int n, d;
	scanf("%d%d", &n, &d);
	int tot = 0;
	rep(i, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	rep(i, n) {
		sum[i+1] = sum[i] +	a[i];
	}
	int m;
	scanf("%d", &m);
	if (m <= n) printf("%d\n", sum[m]);
	else printf("%d\n", sum[n]-d*(m-n));

    return 0;
}
