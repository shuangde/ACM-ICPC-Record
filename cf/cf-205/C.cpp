
// 题意：
// 给数组a: a0, a1, ..., an-1 (0 ≤ ai ≤ 10^4) 
// 和一个长度为n的二进制数s，从左往右分别对应a0, a1...an-1
// f(x) = sum{ ai*s(i), 0<=i<n }
// 问取一个二进制值小于等于s的值，f(x)的最大值是多少？

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
#define MP make_pair
#define PB push_back
#define SQ ((x)*(x))
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

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int MAXN = 100010;

int64 a[MAXN];
char s[MAXN];

int main () {

    int n;
    while (~scanf("%d", &n)) {
        int64 sum = 0, ori = 0;
        rep(i, n) {
            scanf("%lld", &a[i]); 
            sum += a[i];
        }
        scanf("%s", s);
        int64 res = 0, ans = 0;
        for (int i = n-1; i >= 0; --i) {
            sum -= a[i];
            if (s[i] == '1') {
                cmax(ans, sum+res);
            }
            if (s[i]=='1') {
                res += (s[i] - '0')*a[i];
                ori += a[i];
            }
        }
        cout << max(ans, ori) << endl;
    }
    return 0;
}
