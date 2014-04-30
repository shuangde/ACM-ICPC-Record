
// 可以用tarjan求割点，效率更高
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
bool vis[N];
int n, m, k; 
int f[N];

int find(int u) {return u==f[u]?u:f[u]=find(f[u]);}

void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int solve(int u) {
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!vis[v]) {
			dfs(v);	
			++cnt;
		}
	}
	return cnt - 1;
}

int main() {

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n; ++i) f[i] = i;

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].PB(v);
		adj[v].PB(u);
		f[find(u)] = find(v);
	}
	int conn = 0;
	set<int>ss;
	for (int i = 1; i <= n; ++i) {
		int x = find(i);
		if (ss.find(x) == ss.end()) {
			++conn;
			ss.insert(x);
		}
	}
	for (int i = 0; i < k; ++i) {
		int u;
		scanf("%d", &u);
		cout << solve(u) + (conn?conn-1:0) <<endl;
	}
    return 0;
}
