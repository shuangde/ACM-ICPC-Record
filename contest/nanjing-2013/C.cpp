
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

int fib[15];
int mat[110], n, m, c,d ;

void init() {
	fib[0] = 0; fib[1] = 1; fib[2] = 2;
	for (int i = 3; i < 15; ++i)
		fib[i] = fib[i-1] + fib[i-2];
}


int main() {
	init();
	while (~scanf("%d%d%d%d", &n, &m, &c, &d)) {

		for (int i = 0; i < 31; ++i) {
		
		}
	}
    return 0;
}
