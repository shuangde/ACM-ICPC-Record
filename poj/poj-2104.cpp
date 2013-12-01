
// 函数式线段树, 区间第k大
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

const int N = 200010;

int arr[N], bin[N];

#define NODE int left, int right, int& rt
#define MID ((left+right)>>1)
#define LSON left, m, t[rt].ls
#define RSON m+1, right, t[rt].rs

struct Seg {
	int ls, rs, val;
}t[N*20];

int tot, root[N];

void build(NODE) {
	rt = tot++;
	t[rt].val = 0;
	if (left == right) return ;
	int m = MID;
	build(LSON); build(RSON);
}
void update(NODE, int ort, int pos) {
	rt = tot++;
	t[rt] = t[ort]; 
	t[rt].val = t[ort].val + 1;
	if (left == right) return;
	int m = MID;
	if (pos <= m) update(LSON, t[ort].ls, pos);
	else update(RSON, t[ort].rs, pos);
}

int query(int left, int right, int xrt, int yrt, int k) {
	if (left == right) return left;
	int cnt = t[t[yrt].ls].val - t[t[xrt].ls].val;
	int m = MID;
	if (cnt >= k) return query(left, m, t[xrt].ls, t[yrt].ls, k);
	else return query(m+1, right, t[xrt].rs, t[yrt].rs, k - cnt);
}

int main () {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
		bin[i-1] = arr[i];
	}
	// 离散化
	sort(bin, bin+n);
	int size = unique(bin, bin+n) - bin;

	// 建立空树
	tot = 0;
	build(1, size, root[0]);

	for (int i = 1; i <= n; ++i) {
		int x = lower_bound(bin, bin+size, arr[i]) - bin + 1;
		update(1, size, root[i], root[i-1], x);
	}

	for (int i = 0; i < m; ++i) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		printf("%d\n", bin[query(1, size, root[a-1], root[b], k) - 1]);
	}
	return 0;
}
