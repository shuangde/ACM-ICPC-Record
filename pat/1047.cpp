// 简单排序索引
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int cnt[2510];
vector<int>vt[2600];


inline int Hash(char *str) {
	return (str[0]-'A')*26*26*26+(str[1]-'A')*26*26
		+(str[2]-'A')*26+str[3]-'0';
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		char str[5]; int c;
		scanf("%s%d", str, &c);
		int pp = Hash(str);
		for (int j = 0; j < c; ++j) {
			int x; 
			scanf("%d", &x);
			cnt[x]++;
			vt[x].PB(pp);
		}
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d %d\n", i, vt[i].size());
		sort(vt[i].begin(), vt[i].end());
		for (int j = 0; j < vt[i].size(); ++j) {
			int x = vt[i][j];
			printf("%c%c%c%d\n", x/26/26/26+'A', (x/26/26)%26+'A', 
					(x/26)%26+'A', x%26);
		}
	}
	return 0;
}
