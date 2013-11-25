#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 1002;
int c[N][N], n, m;

inline int lowbit(int x) {return x&(-x);}

void add(int x, int y) {
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j)) 
			c[i][j]++, c[i][j] &= 1;
}

int sum(int x, int y) {
	int ret = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			ret += c[i][j];
	return ret;
}

int main(){

	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < m; ++i) {
			char cmd[3];
			scanf("%s", cmd);
			if (cmd[0] == 'C') {
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				add(x1, y1); 
				add(x1, y2+1);
				add(x2+1, y1); 
				add(x2+1, y2+1);
			} else {
				int x, y;
				scanf("%d%d", &x, &y);
				printf("%d\n", sum(x, y)&1);
			}
		}
		puts("");
	}
	return 0;
}
