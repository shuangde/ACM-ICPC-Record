// 27分
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <bitset>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define asc(a,b) if(a>b)swap(a,b)
#define des(a,b) if(a<b)swap(a,b)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;

const int INF = 0x3f3f3f3f;

const int N = 510;
vector<PII>adj[N];
int d[N], f[N], back[N], pre[N];
bool vis[N];
int cmax, n, sp, m, c[N];

int dij(int src) {
	clr(d, INF); 
	clr(f, INF); 
	clr(vis, 0); 
	clr(back, 0);
	d[src] = 0; 
	f[src] = 0; 
	pre[src] = -1;
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	Q.push(MP(0, src));
	while (!Q.empty()) {
		PII x = Q.top(); Q.pop();
		int u = x.second;
		if (vis[u]) continue;
		vis[u] = true;
		for (int e = 0; e < adj[u].size(); ++e) {
			int v = adj[u][e].first;
			int w = d[u] + adj[u][e].second;
			int send, bac;
			if (c[v] >= cmax/2) {
				send = f[u];
				bac  = back[u] + c[v] - cmax/2;
			} else {
				int req = cmax/2 - c[v];
				if (back[u] >= req) {
					send = f[u];
					bac  = back[u] - req;
				} else {
					send = f[u] + req - back[u];	
					bac  = 0;
				}
			}
			if (w < d[v] || w==d[v]&&send<f[v] || w==d[v]&&send==f[v]&&bac<back[v] ) {
				d[v] = w;
				f[v] = send;
				back[v] = bac;
				pre[v] = u;
				Q.push(MP(d[v], v));
			}
		}
	}
	return f[sp];
}

void print_path(int u) {
	if (pre[u] != -1) {
		print_path(pre[u]);
		printf("->");
	}
	printf("%d", u);
}

int main() {

	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].PB(MP(v, w));
		adj[v].PB(MP(u, w));
	}

	int res = dij(0);
	printf("%d ", res < 0 ? 0 : res);
	print_path(sp);
	printf(" %d\n", back[sp]);
	return 0;
}

