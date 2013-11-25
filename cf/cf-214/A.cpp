
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

const int N = 1000010;

int n, m;

int main() {

	while (~scanf("%d", &n)) {
		bool ok = false;
		for (int i = 1; i <= 4; ++i) {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if (ok) continue;
			int tmp1 = min(a, b), tmp2 = min(c,d);
			if (tmp1 + tmp2 <= n) {
				ok = true;
				printf("%d %d %d\n", i, tmp1, n-tmp1);
			}
		}
		if (!ok) puts("-1");
	}
    return 0;
}
