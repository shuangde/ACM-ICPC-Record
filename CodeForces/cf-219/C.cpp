
// 有n只袋鼠，每只的尺寸为si，一只袋鼠可以进入另一只袋鼠当且仅当另一只袋鼠的尺寸大于等于它的两倍。
// 每只袋鼠最多只能装一只袋鼠，也就是说，不能嵌套，即如果一只袋鼠已经在另一只袋鼠里面了，那么它就不能
// 再装一只袋鼠。 当袋鼠装进另一只袋鼠里面后，就看不到它了，问最少还有几只袋鼠可以看到？

// 思路：排序后，让后n/2的袋鼠去装前n/2只袋鼠, 贪心的做法, O(n)。

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
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

const int MAXN = 500010;
int n, s[MAXN];

void outArr(int* arr, int len) { rep(i, len) printf("%d ", arr[i]); puts(""); }

int main() {

    while (~scanf("%d", &n)) {
        ff(i, n) scanf("%d", &s[i]);
        sort(s+1, s+1+n);
        //outArr(s, n);
        int r = n, l = n / 2, cnt = 0;
        while (r >= n/2 && l >= 1) {
            while (l >= 1 && s[l]*2>s[r]) --l;
            if (l < 1) break;
            ++cnt;
            --r; --l;
        }
        cout << n - cnt << endl;
    }
    return 0;
}
