//shuangde 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int N = 200010;
int h, w, n;
int val[N*4];

#define MID (left+right)>>1
#define NODE int left,int right,int rt
#define CALL 1,n,1
#define LSON left, m, rt<<1
#define RSON m+1, right, rt<<1|1

void build(NODE, int data) {
	val[rt] = data;
	if (left == right) return;
	int m = MID; 
	build(LSON, data); 
	build(RSON, data);
}

inline void push_up(int rt) {
	val[rt] = max(val[rt<<1], val[rt<<1|1]);
}

int update(NODE, int data) {
	if (left == right) {
		val[rt] -= data; 
		return left;
	}
	int m = MID;
	if (val[rt<<1] >= data) {
		int ret = update(LSON, data); 
		push_up(rt);
		return ret;
	} else if (val[rt<<1|1] >= data) {
		int ret = update(RSON, data); 
		push_up(rt);
		return ret;
	} else 
		return -1;
}

int main () {

	while (~scanf("%d%d%d", &h, &w, &n)) {
		int hh = min(h, n);
		build(1, hh, 1, w);
		rep(i, n) {
			int x; scanf("%d", &x);	
			printf("%d\n", update(1, hh, 1, x));
		}
	}
	return 0;
}
