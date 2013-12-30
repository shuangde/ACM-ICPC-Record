
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

const int N = 100010;
int n, m;
int f[N];
int mark[N];

struct Edge {
	int v, w, next;
}E[N*2];
int head[N], size;
vector<int>ans;

void init () {
	size = 0;
	memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w) {
	E[size].v = v;
	E[size].w = w;
	E[size].next = head[u];
	head[u] = size++;
}

void dfs(int u, int fa) {

	f[u] = 0;
	for (int e = head[u]; e != -1; e = E[e].next) {
		int v = E[e].v;
		if (v == fa) continue;
		dfs(v, u);
	}
	for (int e = head[u]; e != -1; e = E[e].next) {
		int v = E[e].v;
		if (v == fa) continue;
		f[u] += f[v];
		if (E[e].w == 2) {
			if (f[v]) {
				mark[v] = 0;
			} else {
				mark[v] = 1;
				f[u]++;
			}
		} else {
			mark[v] = 0;
		}
	}
}

void dfs2(int u, int fa) {
	for (int e = head[u]; e != -1; e = E[e].next) {
		int v = E[e].v;
		if (v == fa) continue;
		if (mark[v]) ans.push_back(v);
	}
	for (int e = head[u]; e != -1; e = E[e].next) {
		int v = E[e].v;
		if (v == fa) continue;
		dfs2(v, u);
	}
}

int main() {

	int n;
	while (~scanf("%d", &n)) {
		init();
		rep(i, n-1) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addEdge(u, v, w);
			addEdge(v, u, w);
		}
		dfs(1, -1);
		ans.clear();
		dfs2(1, -1);

		printf("%d\n", f[1]);
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}
