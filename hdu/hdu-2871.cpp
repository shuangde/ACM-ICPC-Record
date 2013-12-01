
// Memory Control
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
#include <ctime>
#define MP make_pair
#define SQ ((x)*(x))
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
#define random(x) (rand()%x)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

#define NODE int left, int right, int rt
#define CALL 1, n, 1
#define MID  ((left+right)>>1)
#define LSON left, m, rt<<1
#define RSON m+1, right, rt<<1|1

const int N = 50010;
PII info[N];

struct Seg {
	int val, lmx, rmx, mx;
	bool lazy;
}t[N*4];

void pushUp(NODE) {
	int ls = rt<<1, rs = ls|1, m = MID;
	t[rt].lmx = t[ls].lmx + (t[ls].lmx==m-left+1 ? t[rs].lmx : 0);
	t[rt].rmx = t[rs].rmx + (t[rs].rmx==right-m ? t[ls].rmx : 0);
	t[rt].mx = max(t[ls].mx, t[rs].mx);
	cmax(t[rt].mx, t[ls].rmx+t[rs].lmx);
}

void pushDown(NODE) {
	if (t[rt].lazy) {
		int ls = rt<<1, rs=ls|1, m = MID;
		t[ls].lmx = t[ls].rmx = t[ls].mx = (!t[rt].val) * (m-left+1);
		t[rs].lmx = t[rs].rmx = t[rs].mx = (!t[rt].val) * (right-m);
		t[ls].val = t[rs].val = t[rt].val;
		t[ls].lazy = t[rs].lazy = true;	
		t[rt].lazy = false;
	}
}

void build(NODE) {
	t[rt].lmx = t[rt].rmx = t[rt].mx = right-left+1;
	t[rt].val = 0;
	t[rt].lazy = false;
	if (left == right) return ;
	int m = MID;
	build(LSON); build(RSON);
}

void update(NODE, int l, int r, int data) {
	if (left == l && right == r) {
		t[rt].lazy = true;
		t[rt].lmx = t[rt].rmx = t[rt].mx = (!data)*(right-left+1);
		t[rt].val = data;
		return ;
	}
	pushDown(left, right, rt);
	int m = MID;
	if (r <= m) update(LSON, l, r, data);
	else if (l > m) update(RSON, l, r, data);
	else update(LSON, l, m, data), update(RSON, m+1, r, data);
	pushUp(left, right, rt);
}

int findLen(NODE, int x) {
	int ls = rt<<1, rs = ls|1, m = MID;
	pushDown(left, right, rt);
	if (t[rt].lmx >= x) return left;
	if (t[ls].mx >= x) return findLen(LSON, x);
	int midSum = t[ls].rmx + t[rs].lmx;
	if (midSum >= x) return m-t[ls].rmx+1;
	return findLen(RSON, x);
}

int query(NODE, int pos) {
	if (left == right) return t[rt].val;	
	pushDown(left, right, rt);
	int m = MID;
	if (pos <= m) return query(LSON, pos);
	else return query(RSON, pos);
}


int n, m;
int c[N];
inline int lowbit(int x) {return x&(-x);}
void add(int x, int data) {
	while (x <= n) { c[x] += data; x += lowbit(x); }
}
int sum(int x) {
	int ret = 0;
	while (x > 0) { ret += c[x]; x -= lowbit(x); }
	return ret;
}

int main() {

	while (~scanf("%d%d", &n, &m)) {

		build(1, n, 1);	
		memset(c, 0, sizeof(c));

		rep(i, m) {
			char cmd[10]; int x;
			scanf("%s", cmd);
			if (cmd[0]=='R') {
				// reset
				update(CALL, 1, n, 0);
				memset(c, 0, sizeof(c));
				puts("Reset Now");

			} else if (cmd[0] == 'N') {
				// new
				scanf("%d", &x);
				if (t[1].mx < x) {
					puts("Reject New");	
				} else {
					int s = findLen(CALL, x);
					update(CALL, s, s+x-1, s);
					info[s] = MP(s, s+x-1);
					add(s, 1);
					printf("New at %d\n", s);
				}

			} else if (cmd[0] == 'F') {
				// free		
				scanf("%d", &x);
				int s = query(CALL, x);
				if (s == 0) {
					puts("Reject Free");	
				} else {
					printf("Free from %d to %d\n", info[s].first, info[s].second);
					add(s, -1);
					update(CALL, info[s].first, info[s].second, 0);
				}

			} else if (cmd[0] == 'G') {
				// get	
				scanf("%d", &x);
				int tot = sum(n);
				if (tot < x) {
					puts("Reject Get");	
				} else {
					int l = 1, r = n, ans;
					while (l <= r) {
						int mid =  (l+r)/2;
						int tmp = sum(mid);
						if (tmp >= x) { r = mid - 1; ans=mid;}
						else l = mid + 1;
					} 
					printf("Get at %d\n", ans);
				}
			}
		}
		puts("");
	} 
	return 0;
}
