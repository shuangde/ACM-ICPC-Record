
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define SQ ((x)*(x))
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n, m;
char str[100010];
int cnt[100010][3];

int main() {

	gets(str+1);
	int len = strlen(str+1);
	CLR(cnt[0], 0);
	for (int i = 1; i <= len; ++i) {
		rep(j, 3) cnt[i][j] = cnt[i-1][j];
		cnt[i][str[i]-'x']++;
	}
	scanf("%d", &m);
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int c[3]; 
		rep(i, 3) c[i] = cnt[r][i]-cnt[l-1][i];

		int len = r - l + 1;
		if (len < 3) {
			puts("YES"); continue;
		}
		if (len % 3 == 0) {
			if (c[0]==c[1]&&c[1]==c[2]) puts("YES");
			else puts("NO");
		} else if (len%3==1) {
			if (c[0]==c[1] && c[1]==c[2]-1 || 
				c[0]==c[2] && c[2]==c[1]-1 ||
				c[1]==c[2] && c[2]==c[0]-1) puts("YES");
			else puts("NO");
		} else if (len%3==2) {
			if (c[0]+1==c[1] && c[1]==c[2] ||
				c[1]+1==c[2] && c[2]==c[0] ||
				c[2]+1==c[0] && c[0]==c[1]) puts("YES");
			else puts("NO");
		}
	}
    return 0;
}
