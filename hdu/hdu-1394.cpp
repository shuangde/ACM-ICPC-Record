//shuangde 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int N = 5010;
int n;
int arr[N], tmp[N];
int ans;

#define MID ((left+right)>>1)
#define NODE int left,int right,int rt
#define CALL 1,n,1
#define LSON left,m,rt<<1
#define RSON m+1,right,rt<<1|1

int val[N*4];

void update(NODE, int id) {
	val[rt]++;
	if (left == right) return ;
	int m = MID;
	if (id <= m) update(LSON, id);
	else update(RSON, id);
}
int query(NODE, int l, int r) {
	if (left==l && right==r) {
		return val[rt];
	}
	int m = MID;
	if (r <= m) return query(LSON, l, r);
	else if (l > m) return query(RSON, l, r);
	else return query(LSON,l,m)+query(RSON,m+1,r);
}

int main() {

	while (~scanf("%d", &n)) {

		ans = 0; memset(val, 0, sizeof(val));
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]); tmp[i] = arr[i];
			++arr[i];
			if (arr[i] < n) {
				ans += query(CALL, arr[i]+1, n);
			}
			update(CALL, arr[i]);
		}
		int now =  ans;
		for (int i = 0; i < n-1; ++i) {
			now = now - tmp[i] + (n-tmp[i]-1);
			ans = min(ans, now);
		}
		printf("%d\n", ans);
	}
	return 0;
}

