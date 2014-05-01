//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <cstring>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int dir4[4][2]={1,0,-1,0,0,1,0,-1};
const int dir8[8][2]={1,0,-1,0,0,1,0,-1,1,-1,1,1,-1,1,-1,-1};
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 1010;
vector<int>adj[N];

int dfn[N], low[N], cut[N], idx;

void dfs(int u, int fa) {
	dfn[u] = low[u] = idx++;
	int son = 0;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (dfn[v] == -1) {
			++son;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (fa<0&&son>1 || fa>0&&dfn[u]<=low[v]) 
				++cut[u];
		} else if (v != fa)
			low[u] = min(low[u], dfn[v]);
	}
}

int main() {

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	int conn = 0;
	idx = 0;
	memset(dfn, -1, sizeof(dfn));
	for (int i = 0; i <= n; ++i) cut[i] = 1;

	for (int i = 1; i <= n; ++i) 
		if (dfn[i] == -1) {
			idx = 0;
			dfs(i, -1);
			++conn;
		}

	for (int i = 0; i < k; ++i) {
		int u;
		scanf("%d", &u);
		printf("%d\n", adj[u].size()?cut[u]-1:0+(conn?conn-1-!adj[u].size():0));
	}
	return 0;
}

