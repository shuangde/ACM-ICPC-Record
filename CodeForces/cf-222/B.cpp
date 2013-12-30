
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

const int N = 100010;
int a[N],rank1[N],rank2[N],b[N];

struct Node {
	int val, pos, sem;
	bool operator<(const Node&rhs) const{
		return val < rhs.val;	
	}
};

vector<Node>vt;


int main() {

	int n;
	scanf("%d", &n);

	rep(i, n) {
		scanf("%d", &a[i]);
		vt.PB((Node){a[i], i, 1});

		scanf("%d", &b[i]);
		vt.PB((Node){b[i], i, 2});
	}

	sort(vt.begin(), vt.end());

	for (int i = 0; i < vt.size(); ++i) {
		if (vt[i].sem == 1) rank1[vt[i].pos] = i+1;
		else rank2[vt[i].pos] = i + 1;
	}

	int maxA=n/2, maxB = n/2;
	int *p;
	p = lower_bound(rank1, rank1+n, n);
	if (*p > n) --p;
	cmax(maxA, p-rank1+1);

	p = lower_bound(rank2, rank2+n, n);
	if (*p > n) --p;
	cmax(maxB, p-rank2+1);


	for (int i = 0; i < n; ++i)
		putchar(i<maxA ? '1' : '0');
	puts("");
	for (int i = 0; i < n; ++i)
		putchar(i<maxB ? '1' : '0');
	puts("");

	return 0;
}
