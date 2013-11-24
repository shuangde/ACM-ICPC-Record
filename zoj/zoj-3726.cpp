#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
typedef long long int64;
int64 s[N], p[N];
int n, m;

struct Node {
	int id;
	int64 w;
	bool operator < (const Node& rhs) const {
		return w > rhs.w;	
	}
}Q[N];
int64 ans[N];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			cin >> s[i] >> p[i];
		for (int i = 0; i < m; ++i) {
			int q; scanf("%d", &q);
			Q[i].id = i;
			Q[i].w = q;
		}
		sort(Q, Q+m);
		int64 minx = 1e18+100000;
		int pt = n - 1;
		for (int i = 0; i < m; ++i) {
			if (Q[i].w == 0) {
				ans[Q[i].id] = 0;
				continue;	
			}
			while (pt>=0 && s[pt]>=Q[i].w) {
				int64 tmp = s[pt] * p[pt]; --pt;
				if (tmp < minx) minx = tmp;
			}
			int64 tmp = Q[i].w * p[pt];
			ans[Q[i].id] = min(tmp, minx);
		}
		for (int i = 0; i < m; ++i)cout<<ans[i]<<"\n";  
	}
	return 0;
}
