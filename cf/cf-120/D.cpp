
// two pointer
// 题意：给n个数字，问有几个子串，使得这些字串至少有k个相同的数字？
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define SQ ((x)*(x))
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 400010;
int arr[N], bin[N];

#define NODE int left, int right, int rt
#define MID (left+right)>>1
#define LSON left,m,rt<<1
#define RSON m+1,right,rt<<1|1

struct Seg { int64 val; }t[N*4];

void pushUp(int rt) {
	t[rt].val = max(t[rt<<1].val, t[rt<<1|1].val);
}

void build(NODE) {
	t[rt].val = 0;
	if (left == right) return;
	int m = MID;
	build(LSON); build(RSON);
}
void update(NODE, int pos, int data) {
	if (left == right) {
		t[rt].val += data;
		return ;
	}
	int m = MID;
	if (pos <= m) update(LSON, pos, data);
	else update(RSON, pos, data);
	pushUp(rt);
}
int query(NODE, int l, int r) {
	if (left == l && right == r) {
		return t[rt].val;	
	}
	int m = MID;
	if (r <= m) return query(LSON, l, r);
	else if (l > m) return query(RSON, l, r);
	else return max(query(LSON, l, m), query(RSON, m+1, r));
}

int main () {

	int n, k;
	scanf("%d%d", &n, &k);
	rep(i, n) {
		scanf("%d", &arr[i]);
		bin[i] = arr[i];
	}
	sort(bin, bin+n);
	int size = unique(bin, bin+n) - bin;
	rep(i, n) {
		arr[i] = lower_bound(bin, bin+size, arr[i])	- bin + 1;
	}

	build(1, size, 1);
	int pt = 0;
	int64 ans = 0;
	rep(i, n) {
		while (pt < n && query(1,size,1,1,size)<k) {
			update(1, size, 1, arr[pt], 1);
			++pt;
		}	
		if (query(1, size, 1, 1, size) >= k) {
			ans += n - pt + 1;	
		}
		update(1, size, 1, arr[i], -1);
	}
	cout << ans << endl;
	return 0;
}
