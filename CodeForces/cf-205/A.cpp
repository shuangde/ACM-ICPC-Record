
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

int arr[110];

int main() {
    
    int n;
    while (~scanf("%d", &n) && n) {
        int sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        rep(i, n) {
            int a, b; scanf("%d%d", &a, &b);
            sum1 += a; sum2 += b;
            if (a%2==1&&b%2==0) ++cnt1;
            if (a%2==0&&b%2==1) ++cnt2;
        } 
        if (n==1 && (sum1%2==1 || sum2%2==1)) {
            puts("-1"); continue; 
        }
        if (sum1%2==0 && sum2%2==0) {
            puts("0");
        } else if (sum1%2==1 && sum2%2==0){
            puts("-1");
        } else if (sum1%2==0 && sum2%2==1) {
            puts("-1");
        } else {
            if (cnt1 || cnt2) puts("1");
            else puts("-1");
        }
    }
    return 0;
}
