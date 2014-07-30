// 贪心+模拟
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Node {
	double p;
	int d;
	bool operator<(const Node&rhs) const {
		return p < rhs.p;
	}
};
bool cmp(const Node& a, const Node& b) {
	return a.d < b.d;
}

Node a[510];
int vis[30010];

int main () {

	int cap, dis, avg, n;
	scanf("%d%d%d%d", &cap, &dis, &avg, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%d", &a[i].p, &a[i].d);
	}

	sort(a, a+n);
	memset(vis, 0, sizeof(vis));

	int len = avg * cap;
	double pp = 0;
	double dd = 0;

	int tot = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = a[i].d+1; j<=a[i].d+len && j<=dis; ++j) {
			if (vis[j] == 0) ++cnt;	
			vis[j] += 1;
		}
		pp += cnt*1.0/avg*a[i].p;
		tot += cnt;
	}

	if (tot == dis)
		printf("%.2f\n", pp);
	else { 
		sort(a, a+n, cmp);
		a[n].d = dis;
		if (a[0].d) {
			printf("The maximum travel distance = %.2f\n", 0.0);
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			if (a[i+1].d - a[i].d > len) {
				printf("The maximum travel distance = %.2f\n", (a[i].d+len)*1.0);
			}
		}
	}
	return 0;
}
