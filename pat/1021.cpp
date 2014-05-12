#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 10010;
typedef pair<int,int>PII;
vector<int>adj[N];

int n, d[N];
bool vis[N], isDR[N];

void dfs(int u)  {
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (vis[v]) continue;
		dfs(v);
	}
}

bool check() {
	memset(vis, 0, sizeof(vis));
	int bcnt = 0;
	for (int i = 1; i <= n; ++i) if (!vis[i]){
		dfs(i); ++bcnt;
	}
	if (bcnt > 1) {
		printf("Error: %d components\n", bcnt);
		return false;
	}
	return true;
}

int bfs(int src) {
	memset(vis, 0, sizeof(vis));
	vis[src] = 1;
	queue<PII>Q;
	Q.push(make_pair(src, 1));
	d[src] = 1;
	int ret = src;
	while (!Q.empty()) {
		PII x = Q.front(); Q.pop();
		int u = x.first;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (vis[v]) continue;
			vis[v] = true;
			d[v] = x.second+1;
			if (d[v] > d[ret]) ret = v;
			Q.push(make_pair(v, d[v]));
		}
	}
	return ret;
}

void getDeepestRoot() {
	int dr = bfs(1);
	for (int i = 1; i <= n; ++i) 
		isDR[i] = d[i]==d[dr];
	dr = bfs(dr);
	for (int i = 1; i <= n; ++i) {
		if (isDR[i] || d[i] == d[dr]) {
			printf("%d\n", i);
		}
	}
}

int main () {

	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (check()) {
		getDeepestRoot();
	}
 
	return 0;
}
