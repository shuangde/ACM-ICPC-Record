
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

int coin[100010];
int cnt[1010];

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &coin[i]);
		cnt[coin[i]]++;
	}
	sort(coin, coin+n);
	for (int i = 0; i < n && coin[i]<=m/2; ++i) {
		int a = m - coin[i];
		int b = coin[i];
		if (a!=b&&cnt[a]>0 || a==b&&cnt[a]>1) {
			if (a > b) swap(a, b);
			printf("%d %d\n", a, b);
			return 0;
		}
	}
	puts("No Solution");
    return 0;
}
