
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

int n, m;

struct Edge{
	int u, v, l, r;
	bool operator < (const Edge& rhs) const {
		return r > rhs.r;	
	}
}E[40000];

int f[400000];

void init() {
	for (int i = 0; i <= n; ++i) f[i] = i;
}
int find(int x) {
	return x==f[x] ? x : f[x] = find(f[x]);
}

bool Union(int x, int y) {
	int a = find(x), b = find(y);
	if (a == b) return false;
	f[a] = b;
	return true;
}

int main() {

	while (~scanf("%d%d", &n, &m)) {

		for (int i = 0; i < m; ++i) 
			scanf("%d%d%d%d", &E[i].u, &E[i].v, &E[i].l, &E[i].r);	
		sort(E, E+m);
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			int l = E[i].l;
			init();
			for (int j = 0; j < m; ++j) {
				if (E[j].l <= l && Union(E[j].u, E[j].v)) {
					if (find(1) == find(n)) {
						ans = max(ans, E[j].r-l+1);
						break;
					}
				} 
			}
		}
		if (ans==0) puts("Nice work, Dima!");
		else printf("%d\n", ans);
	}
    return 0;
}
