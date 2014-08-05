// dp求最长回文串
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

const int N = 1010;
char str[N];
int f[N][N];

int main() {

	gets(str+1);
	int len = strlen(str+1);
///	printf("%s %d\n", str+1, len);
	for (int i = 1; i <= len; ++i) {
			f[i][i] = 1;
	}
	for (int i = 2; i <= len; ++i) {
			f[i-1][i] = 1 + (str[i]==str[i-1]);
	}

	for (int r = 3; r <= len; ++r) {
		for (int i = 1; i <= len-r+1; ++i) {
			int j = i + r - 1;	
			f[i][j] = max(f[i+1][j], f[i][j-1]);
			if (f[i+1][j-1] == j-i-1 && str[i] == str[j])
				f[i][j] = max(f[i][j], f[i+1][j-1]+2);
		}	
	}
	printf("%d\n", f[1][len]);
    return 0;
}
