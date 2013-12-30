
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
#include <ext/rope>
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
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;
using namespace __gnu_cxx;

typedef pair<int, int >PII;
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

const int dir4[4][2]={1,0,-1,0,0,1,0,-1};
const int dir8[8][2]={1,0,-1,0,0,1,0,-1,1,-1,1,1,-1,1,-1,-1};
int n, m, k;
char mat[510][510];

inline int id(int i, int j) {return i*m+j;}
inline bool isout(int i, int j) {return i<0||i>=n||j<0||j>=m;}

int deg[502*502];
bool vis[502*502];

int main() {

	scanf("%d%d%d", &n, &m, &k);
	rep(i, n) scanf("%s", mat[i]);
	priority_queue<PII, vector<PII>, greater<PII> >Q;
	rep(i, n) {
		rep(j, m) if (mat[i][j] == '.'){
			int cc = 0;
			for (int k = 0; k < 4; ++k) {
				int dx = i + dir[k][0];	
				int dy = j + dir[k][1];
				if (!isout(dx,dy) && mat[dx][dy]=='.') {
					++cc;
				}
			}
			deg[id(i,j)] = cc;
			Q.push(MP(deg[id(i,j)], id(i,j)));
		}
	}

	vector<int>ans;
	while (ans.size() < k) {
		PII x = Q.top(); Q.pop();
		int u = x.second;
		if (vis[u]) continue;
		vis[u] = true;
		ans.PB(u);
		int i = u/m, j=u%m;
		for (int k = 0; k < 4; ++k) {
			int dx = i + dir[k][0];	
			int dy = j + dir[k][1];
			int v = dx * m + dy;
			if (!isout(dx,dy) && mat[dx][dy]=='.' && !vis[v]) {
				--deg[v];
				Q.push(MP(deg[v], v));
			}
		}
	} 

	for (int i = 0; i < ans.size(); ++i) {
		int p = ans[i];	
		mat[p/m][p%m] = 'X';
	}
	rep(i, n) puts(mat[i]);
	return 0;
}


