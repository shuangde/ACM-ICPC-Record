
// 题意：给长度为n的数组a0,a1..an-1，1<=ai<=2, 和一个数k, n%k==0
// 问变化数组a最少个数，使这个数组有子串[0, k-1]重复n/k次构成的？

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

int main() {

    int n, k, a[110];
    scanf("%d%d", &n, &k);
    int cnt[110][2] = {0};
    rep(i, n) {
        scanf("%d", &a[i]);
        cnt[i%k][a[i]]++;
    }
    int ans = 0;
    rep(i, k) {
        if (cnt[i][1]==0 || cnt[i][2] == 0) continue;
        ans += min(cnt[i][1], cnt[i][2]);
    }
    cout << ans << endl;
    return 0;
}
