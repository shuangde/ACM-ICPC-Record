
// 题意：给两个数a, b， 为了让a=b, 每次可以把用2,3,5除它们的一个（只有可以被整除时），
// 问最少需要除几次？
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

typedef pair<int, int >PII;
typedef long long int64;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

int gao(int& x) {
    int cnt = 0;
    while (x % 2 == 0) x /= 2, ++cnt;
    while (x % 3 == 0) x /= 3, ++cnt;
    while (x % 5 == 0) x /= 5, ++cnt;
    return cnt;
}

int main() {

    int n, a, b;
    while (~scanf("%d%d", &a, &b)) {
        int t = __gcd(a, b);
        int x = a / t, y = b / t;
        int t1 = gao(x), t2 = gao(y);
        if (x == 1 && y == 1) printf("%d\n", t1+t2);
        else puts("-1");
    }
    return 0;
}
