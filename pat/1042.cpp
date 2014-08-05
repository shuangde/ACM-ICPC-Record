
// 简单模拟
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

const int N = 54;
int a[N];
int s[N];
int k;

void input() {
	scanf("%d", &k);
	for (int i = 0; i < N; ++i)
		a[i] = i;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &s[i]);
		s[i]--;
	}
}

void solve() {
	int tmp[N+1];
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < N; ++j)
			tmp[s[j]] = a[j];
		for (int j = 0; j < N; ++j)
			a[j] = tmp[j];
	}
}

void output() {
	for (int i = 0; i < N; ++i) {
		if (a[i] ==	52)	printf("J1");
		else if (a[i] == 53) printf("J2");
		else {
			int t = a[i] / 13;
			if (t==0) putchar('S');
			else if (t==1) putchar('H');
			else if (t==2) putchar('C');
			else putchar('D');
			printf("%d", a[i]%13+1);
		}
		if (i!=N-1) putchar(' ');
	}
}

int main() {

	input();
	solve();
	output();
    return 0;
}
