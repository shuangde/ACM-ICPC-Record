
// 题意：把一个图，添加一些边，变成一个大环
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

const int N = 60;
int n, m, deg[N], f[N];
bool vis[N];
PII E[2600];

inline void init () { for (int i = 1; i <= n; ++i) f[i] = i; }
int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}

bool merge(int x, int y) {
	int a = find(x), b = find(y);
	if (a==b) return false;
	f[a] = b;
	return true;
}


int check() {
	if (m > n) return -1;
	init();
	CLR(vis, 0);
	CLR(deg, 0);
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		if (++deg[E[i].first] > 2 || ++deg[E[i].second]>2) return -1;
		if (deg[E[i].first]  == 2 && !vis[E[i].first]) vis[E[i].first]=true, ++cnt;
		if (deg[E[i].second] == 2 && !vis[E[i].second]) vis[E[i].second]=true, ++cnt;
		if (!merge(E[i].first, E[i].second)) {
			if (cnt == n) return 1;
			else return -1;
		}
	}
	return 0;
}

int main() {

	while (~scanf("%d%d", &n, &m)) {
		rep(i, m) {
			int u, v; 
			scanf("%d%d", &u, &v);	
			E[i] = MP(u, v);
		}

		int ret = check();

		if (ret == -1) {
			puts("NO");
			continue;

		} 
		if (ret == 1) {
			puts("YES\n0");
			continue;
		}

		puts("YES");

		if (n==1 && !m) {
			puts("1\n1 1"); 
			continue;
		}

		vector<PII>ans;
		priority_queue<int, vector<int>, greater<int> >Q;
		for (int i = 1; i <= n; ++i) 
			if (deg[i] < 2) Q.push(i);

		for (int i = m+1; i <= n; ++i) {
			int a = Q.top(); Q.pop();
			if (i<n && find(a) == find(Q.top()) ) {
				int tmp = Q.top(); Q.pop();
				int b = Q.top(); Q.pop();
				ans.push_back(MP(a, b));
				merge(a, b);
				++deg[a]; ++deg[b];
				if (deg[a] < 2) Q.push(a);
				if (deg[b] < 2) Q.push(b);
				Q.push(tmp);

			} else {
				int b = Q.top(); Q.pop();
				ans.push_back(MP(a, b));
				merge(a, b);
				++deg[a]; ++deg[b];
				if (deg[a] < 2) Q.push(a);
				if (deg[b] < 2) Q.push(b);
			}
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i) 
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
