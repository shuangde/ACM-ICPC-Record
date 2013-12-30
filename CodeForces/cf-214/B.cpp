
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

const int MAXN = 100010;
int n, k;
int sum[MAXN];

int main() {

	while (~scanf("%d%d", &n, &k)) {
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			sum[i%k] += x;
		}
		int minx = INF, pos;
		for (int i = 0; i < k; ++i) {
			if (sum[i] < minx) {
				minx = sum[i];
				pos = i;
			}
		}
		printf("%d\n", pos+1);
	}
    return 0;
}
