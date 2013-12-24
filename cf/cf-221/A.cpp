
// A. Lever
// 题意： 用一个字符串来代表杠杆，^表示支撑点，=表示木板上是空的，数字1～9表示上面放着的重量
// 判断左臂和右臂的力矩的大小关系
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <ext/rope>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define asc(a,b) if(a>b)swap(a,b)
#define des(a,b) if(a<b)swap(a,b)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;
using namespace __gnu_cxx;

typedef long long LL;
typedef pair<LL, int >PII;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 3000010;
int arr[MAXN];
int n, m;
char str[MAXN];

int main() {

	while (~scanf("%s", str)) {
		int len = strlen(str);
		vector<PII>vt;
		int mid;
		for (int i = 0; i < len; ++i) {
			if (str[i] == '^') mid = i;
			else if (str[i] != '=') vt.PB(MP(str[i]-'0', i));
		}
		LL leftSum = 0, rightSum = 0;
		for (int i = 0; i < vt.size(); ++i) {
			if (vt[i].second < mid) {
				leftSum += vt[i].first * (mid - vt[i].second);	
			} else {
				rightSum += vt[i].first * (vt[i].second - mid);
			}	
		}
		if (leftSum == rightSum) puts("balance");
		else if (leftSum > rightSum) puts("left");
		else puts("right");
	}

	return 0;
}
