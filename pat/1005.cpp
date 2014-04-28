
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

const char *digit[] = {"zero","one","two","three","four",
				"five","six","seven","eight","nine"};

const int N = 1100;
char str[N];
int num[N];

void add(int a) {
	num[N-1] += a;
	for (int i = N - 1; i > 0; --i) {
		num[i-1] += num[i]/10;
		num[i] %= 10;
	}
}

int main() {

	gets(str);
	for (int i = 0; str[i]; ++i) {
		add(str[i]-'0');	
	}

	int i = 0;
	while (num[i] == 0 && i < N-1) ++i;
	printf("%s", digit[num[i++]]);
	for (; i < N; ++i) 
		printf(" %s", digit[num[i]]);
    return 0;
}
