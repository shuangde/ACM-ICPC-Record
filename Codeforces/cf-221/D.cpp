#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MP make_pair
#define PB push_back
using namespace std;

typedef pair<int, int >PII;
const int N = 5010;

char mat[N];
int n, m, f[N],  cnt[N], c[N+2];

inline int lowbit(int x) { return x & (-x); }

void add(int x, int data) {
	while (x <= N) { c[x] += data; x += lowbit(x); }
}
int sum(int x) {
	int ret = 0;
	while (x > 0) { ret += c[x]; x -= lowbit(x); }
	return ret;
}

int main() {

	scanf("%d%d%*c", &n, &m);
	vector<PII>vt;
	for (int i = 0; i < n; ++i) {
		gets(mat+1);
		memset(f, 0, sizeof(f));
		for (int j = 1; j <= m; ++j) {
			if (mat[j] == '1') f[j] = f[j-1] + 1;
			else { 
				if (mat[j] == '0' && f[j-1]) {
					vt.PB(MP(j-f[j-1], j-1));	
				} 
			}
		}
		if (f[m]) vt.PB(MP(m-f[m]+1, m)); 
	}
	memset(c, 0, sizeof(c));
	memset(cnt, 0, sizeof(cnt));
	sort(vt.begin(), vt.end());
	int size = vt.size();
	for (int i = 0; i < size; ++i) cnt[vt[i].second]++;
	int pt = 0, ans = 0;
	for (int i = 1; i <= m; ++i) {
		while (pt < size && vt[pt].first <= i) {
			add(vt[pt++].second, 1);	
		}
		for (int j = i; j <= m; ++j) {
			int cnt = sum(m) - sum(j-1);	
			ans = max(ans, (j-i+1) * cnt);
		}
		add(i, -cnt[i]);
	}
	cout << ans << endl;
	return 0;
}
