
// 题意： 汉堡由三种材料B、S、C组成, 给出制作一个汉堡的食谱，即分别需要B,S,C的个数，
// 还有他们的价格。 目前已经分别拥有了这些材料的数量为nb,ns,nc, 还拥有钱r, 可以用钱再去
// 买材料。问用这些已经拥有的材料，以及钱，最多可以制作多少个汉堡？

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
const int64 INF = 1e18;

template <class T>
inline void rd(T &ret) {
    char c;  ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9') ret = ret * 10 + (c - '0'), c = getchar();
}
char s[110];
int idx(char ch) {
    if (ch == 'B') return 0;
    if (ch == 'S') return 1;
    return 2;
}

int main() {

    while (~scanf("%s", s)) {

        int len = strlen(s);

        int64 num[3], price[3], pat[3] = {0}, own, unitPrice = 0;

        rep(i, 3) rd(num[i]); rep(i, 3) rd(price[i]);

        rep(i, len) pat[idx(s[i])]++, unitPrice += price[idx(s[i])];
        rep(i, 3) if (!pat[i]) price[i] = 0;

        rd(own);

        // rep(i, 3) printf("%lld ", pat[i]); puts(""); continue;
        int64 cnt = 0, tmp = INF;
        rep(i, 3) if (pat[i]) cmin(tmp, num[i]/pat[i]);

        cnt = tmp;

        int64 maxx = 1;
        rep(i, 3) if(pat[i]) num[i] -= pat[i] * cnt, cmax(maxx, (num[i]/pat[i]) + (num[i]%pat[i]!=0));
        //rep(i, 3) printf("%lld ", num[i]); puts(""); continue;
        //cout << "maxx = " << maxx << endl;

        int64 l = 0, r = maxx;
        while (l <= r) {
            int64 mid = (l+r)>>1;
            int64 sum = 0;
            rep(i, 3) if (pat[i]) {
                int use = min(num[i], mid * pat[i]);
                sum += min(pat[i]*mid*price[i], use * price[i]);
            }
            int64 req = mid * unitPrice;
            if (req - sum <= own) l = mid + 1;
            else r = mid - 1;
        }
       // cout << "r = " << r << endl;
        if (r == maxx) {
            cnt += r;
            //rep(i, 3) printf("%lld ", num[i]); puts("");
            own -= r * unitPrice;
            rep(i, 3) if (pat[i]) own += num[i] * price[i];
            cout << cnt + own/unitPrice << endl;
        } else {
            cout << cnt + r << endl;
        }
    }
    return 0;
}
