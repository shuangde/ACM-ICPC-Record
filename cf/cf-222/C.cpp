
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
int n, m, k;
char mat[510][510];
bool choose[510][510];
int cnt, tot;

void dfs(int x, int y) {
	if (cnt == tot-k) return;
	++cnt; choose[x][y] = true;
	rep(i, 4) {
		int dx = x + dir4[i][0];	
		int dy = y + dir4[i][1];
		if (dx>=0 && dx<n && dy>=0 && dy<m && mat[dx][dy]=='.' && !choose[dx][dy]) {
			dfs(dx, dy);
		}
	}
}

int main() {

	scanf("%d%d%d", &n, &m, &k);
	rep(i, n) scanf("%s", mat[i]);
	int x, y;
	rep(i, n) {
		rep(j, m) if (mat[i][j] == '.'){
			x = i, y = j;
			++tot;
		}
	}

	cnt = 0;
	dfs(x, y);

	rep(i, n) {
		rep(j, m) 
			putchar(choose[i][j]||mat[i][j]=='#'?mat[i][j]:'X');
		putchar('\n');
	}
	return 0;
}


