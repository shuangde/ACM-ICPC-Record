
// 水
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

    int n;
    char str[10];
    scanf("%d", &n);
    int cnt[10] = {0};
    rep(i, 4) {
        scanf("%s", str);
        rep(j, 4) if (str[j] != '.'){
            ++cnt[str[j]-'0'];
        }
    }
    for (int i = 1; i <= 9; ++i) 
        if (cnt[i] > n * 2) {puts("NO"); return 0; }
    puts("YES");
    return 0;
}
