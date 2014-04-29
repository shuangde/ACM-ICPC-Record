
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
#define FIN(x) freopen(x,"r",stdin)
#define FOUT(x) freopen(x,"w",stdout)
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
const int dir4[4][2]={1,0,-1,0,0,1,0,-1};
const int dir8[8][2]={1,0,-1,0,0,1,0,-1,1,-1,1,1,-1,1,-1,-1};
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 10010;
double a[N], b[N], c[N];

int main() {

	int n, m, p = 0;
	scanf("%d", &n);
	rep(i, n) {
		int x; double y;
		scanf("%d%lf", &x, &y);
		cmax(p, x);
		a[x] = y;
	}
	scanf("%d", &m);
	rep(i, m) {
		int x; double y;
		scanf("%d%lf", &x, &y);
		cmax(p, x);
		b[x] = y;
	}
	int pp = p;
	for (int i = 0; i <= p; ++i) if (a[i] != 0){
		for (int j = 0; j <= p; ++j) if (b[j] != 0){
			c[i+j] += a[i]*b[j];
			cmax(pp, i+j);
		}	
	}
	int cnt = 0;
	for (int i = 0; i <= pp; ++i)  {
		cnt += (c[i] != 0);
	}
	printf("%d", cnt);
	for (int i = pp; i >= 0; --i) if(c[i]!=0) {
		printf(" %d %.1f", i, c[i]);
	}
    return 0;
}
