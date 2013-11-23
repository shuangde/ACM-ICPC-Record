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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 100010;

int n, m;
#define MID ((left+right)>>1)
#define NODE int left,int right,int rt
#define CALL 1, n, 1
#define LSON left, m, rt<<1
#define RSON m+1, right, rt<<1|1

struct Seg {
	int lmax, rmax, mx;
}t[N*4];
int arr[N];

void push_up(NODE) {
	int ls = rt << 1, rs = ls | 1, m = MID;
	t[rt].lmax = t[ls].lmax + ((t[ls].lmax==m-left+1&&arr[m]<arr[m+1]) ? t[rs].lmax : 0);
	t[rt].rmax = t[rs].rmax + ((t[rs].rmax==right-m&&arr[m]<arr[m+1]) ? t[ls].rmax : 0);
	t[rt].mx = arr[m]<arr[m+1] ? (t[ls].rmax+t[rs].lmax) : max(t[ls].rmax, t[rs].lmax);
	t[rt].mx = max(t[rt].mx, max(t[ls].mx, t[rs].mx));
}

void build(NODE) {
	if (left == right) {
		t[rt].lmax = t[rt].rmax = t[rt].mx = 1;
		return ;
	}
	int m = MID;
	build(LSON); build(RSON);
	push_up(left, right, rt);
}

void update(NODE, int pos, int data) {
	if (left == right) {
		arr[left] = data; return ;
	}
	int m = MID;
	if (pos <= m) update(LSON, pos, data);
	else update(RSON, pos, data);
	push_up(left, right, rt);
}

int query(NODE, int l, int r) {
	if (left == l && right == r) return t[rt].mx;
	int m = MID;
	if (r <= m) return query(LSON, l, r);
	else if (l > m) return query(RSON, l, r);
	else {
		int ret = max(query(LSON, l, m), query(RSON, m+1, r));
		if (arr[m] < arr[m+1]) {
			int tmp = min(m-l+1, t[rt<<1].rmax) + min(r-m, t[rt<<1|1].lmax);
			return max(ret, tmp);
		} 
		return ret;
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
			char cmd[5];
			int a, b;
			scanf("%s%d%d", cmd, &a, &b);
			if (cmd[0] == 'U') {
				update(CALL, a+1, b);	
			} else {
				printf("%d\n", query(CALL, a+1, b+1));
			}
		}
	}
	return 0;
}
