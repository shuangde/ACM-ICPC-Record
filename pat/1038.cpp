
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

bool cmp(const string& a, const string& b) {
	string tmp1 = a + b, tmp2 = b + a;
	return tmp1 < tmp2;
}

int main() {

	vector<string>num;
	int n;
	scanf("%d", &n);
	rep(i, n) {
		string tmp;
		cin >> tmp;
		num.PB(tmp);
	}
	sort(num.begin(), num.end(), cmp);
	bool flag = true;
	for (int i = 0; i < num.size(); ++i) {
		for (int j = 0; j < num[i].size(); ++j) {
			if (flag && num[i][j] != '0') {
				flag = false;
			}
			if (flag && i==num.size()-1 && j==num[i].size()-1)
				flag = false;
			if (!flag) 
				printf("%c", num[i][j]);
		}
	}
	return 0;
}
