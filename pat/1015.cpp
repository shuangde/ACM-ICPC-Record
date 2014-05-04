
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
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

vector<int>num;

void getDigit(int x, int d) {
	num.clear();
	int ret = 0, r = 1;
	while (x > 0) {
		num.push_back(x%d);
		x/=d;
	}
}

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= n/2; ++i)
		if (n%i==0) return false;
	return true;
}

bool solve(int n, int d) {
	getDigit(n, d);
	int ret = 0;
	for (int i = 0; i < num.size(); ++i)  {
		ret = ret * d + num[i];	
	}
	if (!isPrime(ret)) return false;
	ret = 0;
	for (int i = num.size()-1; i >= 0; --i)
		ret = ret * d + num[i];	
	return isPrime(ret);
}

int main() {

	int n, d;
	while(~scanf("%d", &n) && n >= 0) {
		scanf("%d", &d);
		printf("%s\n", solve(n, d) ? "Yes" : "No");
	}
    return 0;
}
