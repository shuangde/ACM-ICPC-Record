
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

const int N = 210;
int n, m, l;
int Rank[N];
int col[N];
int str[N];
//int f[10010][N];
int f[N];

int main() {

	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) { 
		scanf("%d", &col[i]); 
		Rank[col[i]] = i;
	}
	scanf("%d", &l);

	int ans = 0;
	for(int i = 1; i <= l; ++i) {
		scanf("%d", &str[i]);
		int  p = Rank[str[i]];
		int tmp = 0;
		for (int j = 1; j <= p; ++j)
			tmp = max(tmp, f[j]+1);
		ans = max(ans, f[p] = tmp);
		//printf("%d %d: %d\n", i,p, f[p]);
	}
	cout << ans << endl;
/*
	for(int i = 1; i <= l; ++i) {
		scanf("%d", &str[i]);
		for (int j = 1; j <= m; ++j) {
			f[i][j] = max(f[i][j-1], f[i-1][j] + (str[i]==col[j]));
			printf("%d ", f[i][j]);
		}
		puts("");
	}
	printf("%d\n", f[l][m]);
	*/
	return 0;
}
