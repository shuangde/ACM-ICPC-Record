
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

char str[30];
vector<int>num;
int cnt[12];

bool check() {
	for (int i = strlen(str)-1; i >= 0; --i) {
		cnt[str[i]-'0']++;
		int tmp = (str[i]-'0') * 2;
		num.push_back(tmp);
	}
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] >= 10) {
			if (i+1==num.size()) num.push_back(num[i]/10);
			else num[i+1] += num[i]/10;
			num[i] %= 10;
		}
	}
	for (int i = 0; i < num.size(); ++i) {
		if (--cnt[num[i]] < 0) return false;	
	}
	return true;
}

int main() {

	gets(str);
	puts(check()?"Yes":"No");
	for (int i = num.size()-1; i >= 0; --i) printf("%d",num[i]);
	puts("");
    return 0;
}
