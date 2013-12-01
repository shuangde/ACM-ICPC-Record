
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
map<string, double>mp;

int n;

int main() {

	mp["A"] = 4.0; mp["A-"] = 3.7;
	mp["B+"] = 3.3; mp["B"] = 3.0; mp["B-"] = 2.7;
	mp["C+"] = 2.3; mp["C"] = 2.0; mp["C-"] = 1.7;
	mp["D"] = 1.3; mp["D-"] = 1.0;
	mp["F"] = 0;

	while (~scanf("%d", &n)) {
		double c1 = 0, c2 = 0;
		rep(i, n) {
			double a; char str[10];
			scanf("%lf%s", &a, str);
			if (strcmp(str, "N")==0 || strcmp(str, "P")==0) {
				continue;
			}
			c1 += a*mp[str];
			c2 += a;
		}
		if (c2 == 0) puts("0.00");
		else printf("%.2f\n", c1/c2);
	}
	return 0;
}
