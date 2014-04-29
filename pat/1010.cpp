
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
#define FIN(x) freopen(x,"r",stdin)
#define FOUT(x) freopen(x,"w",stdout)
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

typedef pair<int, int >PII;
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int dir4[4][2]={1,0,-1,0,0,1,0,-1};
const int dir8[8][2]={1,0,-1,0,0,1,0,-1,1,-1,1,1,-1,1,-1,-1};
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;


LL toDecimal(char *str, int R) {
	LL ret = 0;
	for (int i = 0; str[i]; ++i) {
		if (isdigit(str[i])) {
			ret = ret * R + str[i] - '0'; 
		} else {
			ret = ret * R + str[i] - 'a' + 10;
		}
	}
	return ret;
}

int check(LL target, char* str) {
	int r = 0;
	for (int i = 0; str[i]; ++i) {
		if (isdigit(str[i])) cmax(r, str[i]-'0'+1);
		else cmax(r, str[i]-'a'+11);
	}
	for (int i = r; i <= target; ++i) {
		LL res = toDecimal(str, i);
		if (res > target || res < 0) break;
		if (target == res) return i;
	}
	return -1;
}

int main() {

	char N[2][20], ch[20];
	int tag, radix;

	scanf("%s%s%d%s", N[0], N[1], &tag, ch);
	radix = toDecimal(ch, 10);

	if (tag == 2) swap(N[0], N[1]);

	int r = check(toDecimal(N[0], radix), N[1]);

	if (r != -1) printf("%d", r);
	else printf("Impossible");

    return 0;
}
