// 线段树
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 200010;
#define NODE int left, int right, int rt  
#define MID ((left+right)>>1)
#define LSON left,m,rt<<1
#define RSON m+1, right, rt<<1|1

struct Seg {
    int val;
}t[N*4];

inline void push_up(int rt) {
	t[rt].val = max(t[rt<<1].val, t[rt<<1|1].val);
}

void build(NODE){
	if (left == right) {
		scanf("%d", &t[rt].val);
		return ;
	}
	int m = MID;
	build(LSON); build(RSON);
	push_up(rt);
}

void update(NODE, int id, int val) {
	if (left == right) {
		t[rt].val = val;	
		return ;
	}
	int m = MID;
	if (id <= m) update(LSON, id, val);
	else update(RSON, id, val);
	push_up(rt);
}

int query(NODE, int l, int r) {
	if (left==l && right==r) return t[rt].val;	
	int m = MID;
	if (r <= m) return query(LSON, l, r);
	else if (l > m) return query(RSON, l, r);
	else return max(query(LSON, l, m), query(RSON, m+1, r));
}


int n, m;

int main() {

	while (~scanf("%d%d", &n, &m)) {

		build(1, n, 1);	
		for(int i = 0; i < m; ++i) {
			char cmd[5];
			int a, b;
			scanf("%s%d%d", cmd, &a, &b);
			if (cmd[0] == 'Q') {
				printf("%d\n", query(1, n, 1, a, b));	
			} else {
				update(1,n,1,a,b);	
			}
		}
	}
	return 0;
}
