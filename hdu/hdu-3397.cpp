// 线段树 区间合并 
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
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
#define random(x) (rand()%x)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 100010;

#define NODE int left,int right,int rt
#define CALL 1,n,1
#define MID (left+right)>>1
#define LSON left, m, rt<<1
#define RSON m+1, right, rt<<1|1

struct Seg {
	int lmx[2], rmx[2], mx[2], sum[2];
	bool cover[2];
	int rev;
}t[N*4];

int arr[N], n, m;

inline void push_up(NODE) {
	int ls = rt<<1, rs = ls|1, m = MID;
	for (int k = 0; k <= 1; ++k) {
		t[rt].sum[k] = t[ls].sum[k]	+ t[rs].sum[k];
		t[rt].lmx[k] = t[ls].lmx[k] + (t[ls].lmx[k]==m-left+1 ? t[rs].lmx[k] : 0);
		t[rt].rmx[k] = t[rs].rmx[k] + (t[rs].rmx[k]==right-m ? t[ls].rmx[k] : 0);
		t[rt].mx[k]  = max(t[ls].rmx[k]+t[rs].lmx[k], max(t[ls].mx[k], t[rs].mx[k]));
	}
}

inline void push_down(NODE) {
	int ls = rt<<1, rs = ls|1, m = MID;

	if (t[rt].cover[0]) {
		t[ls].lmx[0] = t[ls].rmx[0] = t[ls].mx[0] = t[ls].sum[0] = m-left+1;
		t[ls].lmx[1] = t[ls].rmx[1] = t[ls].mx[1] = t[ls].sum[1] = 0;

		t[rs].lmx[0] = t[rs].rmx[0] = t[rs].mx[0] = t[rs].sum[0] = right-m;
		t[rs].lmx[1] = t[rs].rmx[1] = t[rs].mx[1] = t[rs].sum[1] = 0;

		t[ls].cover[0] = t[rs].cover[0] = true;
		t[ls].cover[1] = t[rs].cover[1] = t[ls].rev = t[rs].rev = 0;
		t[rt].cover[0] = false;
	}
	if (t[rt].cover[1]) {
		t[ls].lmx[0] = t[ls].rmx[0] = t[ls].mx[0] = t[ls].sum[0] = 0;
		t[ls].lmx[1] = t[ls].rmx[1] = t[ls].mx[1] = t[ls].sum[1] = m-left+1;

		t[rs].lmx[0] = t[rs].rmx[0] = t[rs].mx[0] = t[rs].sum[0] = 0;
		t[rs].lmx[1] = t[rs].rmx[1] = t[rs].mx[1] = t[rs].sum[1] = right-m;

		t[ls].cover[1] = t[rs].cover[1] = true;
		t[ls].cover[0] = t[rs].cover[0] = t[ls].rev = t[rs].rev = 0;
		t[rt].cover[1] = false;
	}
	if (t[rt].rev & 1) {
		swap(t[ls].lmx[0], t[ls].lmx[1]);
		swap(t[ls].rmx[0], t[ls].rmx[1]);
		swap(t[ls].sum[0], t[ls].sum[1]);
		swap(t[ls].mx[0],  t[ls].mx[1]);

		swap(t[rs].lmx[0], t[rs].lmx[1]);
		swap(t[rs].rmx[0], t[rs].rmx[1]);
		swap(t[rs].sum[0], t[rs].sum[1]);
		swap(t[rs].mx[0],  t[rs].mx[1]);

		++t[ls].rev; ++t[rs].rev;
		t[rt].rev = 0;
	}
}

void build(NODE) {
	t[rt].cover[0] = t[rt].cover[1] = t[rt].rev = 0;
	if (left == right) {
		t[rt].lmx[1] = t[rt].rmx[1] = t[rt].mx[1] = t[rt].sum[1] = arr[left];
		t[rt].lmx[0] = t[rt].rmx[0] = t[rt].mx[0] = t[rt].sum[0] = !arr[left];
		return ;
	}
	int m = MID;
	build(LSON); build(RSON);
	push_up(left, right, rt);
};

void update(NODE, int l, int r, int op) {
	if (left == l && right == r) {
		if (op < 2) {
			t[rt].lmx[1] = t[rt].rmx[1] = t[rt].mx[1] = t[rt].sum[1] = op * (right-left+1);
			t[rt].lmx[0] = t[rt].rmx[0] = t[rt].mx[0] = t[rt].sum[0] = (!op) * (right-left+1);
			t[rt].cover[op] = true; 
			t[rt].cover[!op] = t[rt].rev = 0;
		} else {
			swap(t[rt].lmx[0], t[rt].lmx[1]);
			swap(t[rt].rmx[0], t[rt].rmx[1]);
			swap(t[rt].sum[0], t[rt].sum[1]);
			swap(t[rt].mx[0],  t[rt].mx[1]);
			t[rt].rev++;
		}
		return ;
	}
	push_down(left, right, rt);
	int m = MID;
	if (r <= m) update(LSON, l, r, op);
	else if (l > m) update(RSON, l, r, op);
	else update(LSON, l, m, op), update(RSON, m+1, r, op);
	push_up(left, right, rt);
}  

int query(NODE, int l, int r, int op) {
	if (left==l && right==r) {
		if (op == 3) return t[rt].sum[1];
		return t[rt].mx[1];
	}
	push_down(left, right, rt);
	int m = MID;
	if (r <= m) return query(LSON, l, r, op);
	else if (l > m) return query(RSON, l, r, op);
	else {
		if (op == 3) return query(LSON, l, m, op) + query(RSON, m+1, r, op);
		int ret = max(query(LSON, l, m, op), query(RSON, m+1, r, op));
		int tmp = min(m-l+1, t[rt<<1].rmx[1]) + min(r-m, t[rt<<1|1].lmx[1]);
		return max(tmp, ret);
	}
}

int main () {

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);

		ff(i, n) scanf("%d", &arr[i]);

		build(CALL);

		rep(i, m) {
			int op, a, b;
			scanf("%d%d%d", &op, &a, &b);
			++a; ++b;
			if (op <= 2)  update(CALL, a, b, op);
			else printf("%d\n", query(CALL, a, b, op));
		}
	}
	return 0;
}
