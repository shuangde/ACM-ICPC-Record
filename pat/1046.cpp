
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
const int N   = 100010;
int sum[N];

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &sum[i]);	
		sum[i] += sum[i-1];
	}
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		int tmp = sum[b-1] - sum[a-1];
		printf("%d\n", min(tmp, sum[n]-tmp));
	}

    return 0;
}
