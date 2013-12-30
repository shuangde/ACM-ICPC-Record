
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
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int main() {

	int n, k,l, r, all, sk;
	scanf("%d%d%d%d%d%d", &n, &k,&l, &r, &all, &sk);

	int res = sk - l * k;
	if (res > 0) {
		rep(i, res%k) printf("%d ", l+res/k+1);
		for (int i = res%k; i < k; ++i) printf("%d ", l + res/k);
	} else {
		rep(i, k) printf("%d ", l);
	}

	res = all - sk - l * (n-k);
	if (res > 0) {
		for (int i = k; i < k + res%(n-k); ++i) printf("%d ", l + res/(n-k)+1);
		for (int i = k + res%(n-k); i < n; ++i) printf("%d ", l + res/(n-k));
	} else {
		for (int i = k; i < n; ++i) printf("%d ", l);
	}

	return 0;
}
