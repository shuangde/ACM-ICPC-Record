
// ZOJ Monthly, December 2013
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

const int MAXN = 5000000;
LL cnt[MAXN];

int main() {

	int n, m;
	while (~scanf("%d%d", &n, &m)) {

		memset(cnt, 0, sizeof(cnt));

		LL ans = 0;

		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);	
			++cnt[x];
			ans += x;
		}
		
		for (int i = 0; i < m; ++i) {
			int l, r, c; scanf("%d%d%d", &l, &r, &c);
			for (int j = l; j <= r; ++j) if (cnt[j]) {
				ans += (cnt[j] * (LL)c);
			} 
			for (int j = l; j <= r; ++j){
				if (j + c > r) cnt[j+c] += cnt[j];
			} 
		} 
		cout << ans << endl;
	}
    return 0;
}
