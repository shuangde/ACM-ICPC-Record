
// B.  I.O.U
// 题意：给出n个人的欠钱关系，例如a欠b10元，b欠c 10元，如果还完，共流通20元
// 但是可以转换关系，让a直接还给c 10元，那么流通10元。
// 问最少的流通总量是多少？

// 思路：可以发现，每个人收到的钱总和-支出的钱总和，之和，就是答案
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#define MP make_pair
#define PB push_back
#define clr(a,b) memset(a, (b), sizeof(a))
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

int n, m;
int w[110][110];

int main() {

	scanf("%d%d", &n, &m);

	vector<PII>adj[110];
	int cnt[110] = {0};
	clr(w, 0);
	for (int i = 0; i <m; ++i) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		w[u][v] = x;
	}
	int ans = 0;
	for (int u = 1; u <= n; ++u) {
		int in = 0, out = 0, tot = 0;
		for (int v = 1; v <= n; ++v) if (u!=v) {
			in += w[u][v];	
			tot -= w[u][v];
			tot += w[v][u];
		}
		if (tot > 0)  ans += tot;
	}
	cout << ans << endl;
	return 0;
}
