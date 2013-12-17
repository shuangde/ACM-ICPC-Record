
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

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int main() {

    int n, m; scanf("%d%d", &n, &m);
    int cnt[102] = {0};
    int c[n];

    rep(i, n) {
        scanf("%d", &c[i]); 
    }
    PII ans[n];
    sort(c, c+n);
    int cc = 0;
    rep(i, n) {
        ans[i].first=c[i], ans[i].second=c[n-1-i];
        if (ans[i].first != ans[i].second) ++cc;
    }

    rep(i, n) if (ans[i].first == ans[i].second) {
        rep(j, n) if (i!=j && ans[j].second!=ans[i].second && ans[j].first != ans[i].second) {
            ++cc;
            swap(ans[j].second, ans[i].second);
            break;
        }
    }

    printf("%d\n", cc);
    rep(i, n) printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
