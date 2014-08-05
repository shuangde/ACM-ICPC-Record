
// 二分
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
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int dir4[4][2]={1,0,-1,0,0,1,0,-1};
const int dir8[8][2]={1,0,-1,0,0,1,0,-1,1,-1,1,1,-1,1,-1,-1};
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

const int N = 100010;
int n, m;
int a[N];
int Left[N];

int bin(int x, int low, int high) {
	while (low < high) {
		int mid = low + (high-low)/2;
		if (a[mid] == x) return mid;
		else if (a[mid] < x) low = mid + 1;
		else high = mid;
	}
	if (a[low] == x) return low;
	return low - 1;
}

int findBest() {
	int ret = INF;
	for (int i = 1; i <= n; ++i) {
		int p = bin(a[i]-m, 0, i);
		Left[i] = p;
		if (p >= 0) {
			ret = min(ret, a[i]-a[p]); 
		}
	}
	return ret;
}

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] += a[i-1];
	}
	int target = findBest();
	for (int i = 1; i <= n; ++i) {
		int p = Left[i];
		if (p >= 0 && a[i]-a[p]==target) {
			printf("%d-%d\n", p+1, i);
		}
	}
    return 0;
}
