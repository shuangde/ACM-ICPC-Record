#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define N 510
#define MP make_pair
#define PB push_back
using namespace std;

typedef pair<int,int>PII;
const int INF = 0x3f3f3f3f;
int n, m, c1,c2;
int d[N], f[N], team[N], num[N];
bool vis[N];
int w[N][N];


void dij(int src) {

	memset(d, INF, sizeof(d));
	memset(f, 0, sizeof(f));
	memset(vis, 0, sizeof(vis));
	memset(team, 0, sizeof(team));
	d[src] = 0;
	f[src] = 1;
	int i;
	for (i = 0; i < n; ++i)
		team[i] = num[i];


	for (i = 0; i < n; ++i) {
		int u = -1;
		for (int j = 0; j < n; ++j) if (!vis[j]) {
			if (u == -1 || d[j] < d[u]) u = j;
		}
		vis[u] = true;
		for (int v = 0; v < n; ++v) if (!vis[v] && w[u][v] != -1) {
			int sum = d[u] + w[u][v];
			if (sum < d[v]) {
				d[v] = sum;
				f[v] = f[u];
				team[v] = num[v] + team[u];
			} else if (sum == d[v]) {
				f[v] += f[u];
				if (team[u] + num[v] > team[v]) {
					team[v] = team[u] + num[v];
				}
			}
		}
	}
 
}

int main () {
 
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	int i, j;
	for (i = 0; i < n; ++i)
		scanf("%d", &num[i]);
	memset(w, -1, sizeof(w));
	for (i = 0; i < m; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		w[u][v] = w[v][u] = c;
	}
	dij(c2);
	printf("%d %d\n", f[c1], team[c1]);
	return 0;
}
