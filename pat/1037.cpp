// 简单贪心排序
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

int main() {

	int n, m;
	vector<int>pos1, pos2;
	vector<int>neg1, neg2;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (a > 0) pos1.PB(a);
		else if (a < 0) neg1.PB(-a);
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (a > 0) pos2.PB(a);
		else if (a < 0) neg2.PB(-a);
	}

	sort(pos1.begin(), pos1.end(), greater<int>());
	sort(pos2.begin(), pos2.end(), greater<int>());
	sort(neg1.begin(), neg1.end(), greater<int>());
	sort(neg2.begin(), neg2.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < pos1.size()&&i<pos2.size(); ++i) {
		ans += pos1[i] * pos2[i];
	} 
	for (int i = 0; i < neg1.size()&&i<neg2.size(); ++i) {
		ans += neg1[i] * neg2[i];
	} 

	cout << ans << endl;

    return 0;
}
