
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
LL sum[N], arr[N];

int main() {

	int n;
	scanf("%d", &n);
	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] >= 0) flag = true;
		sum[i] = sum[i-1] + arr[i];
	}

	if (!flag) {
		cout << 0 << " " << arr[1] << " " << arr[n];
		return 0;
	}

	int minx = 0;
	LL maxx = -INF64, l, r;
	for (int i = 1; i <= n; ++i) {
		LL tmp = sum[i] - sum[minx];
		if (tmp > maxx) {
			maxx = tmp;
			l = arr[minx+1];
			r = arr[i];
		}
		if (sum[i] < sum[minx]) minx = i;
	}
	cout << maxx << " " << l << " " << r;
    return 0;
}
