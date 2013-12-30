

// 题意：有n个操作，还有m个数a1,a2..am
// 维护一个队列w,开始时是空的，然后每个操作可能是0,1,-1,如果是0和1,则直接添加到队列w的后面
// 如果是-1,则要把队列w中的第a1,a2,ak(ak<=len(w))个数删除掉。
// 最后输出w中的所有数

// 思路：用一个树状数组来维护，如果第i个数还在队列中的话，那么sum(i)-sum(i-1)==1
// 如果要删除掉第i个数，只需要update(i, -1).  查找队列长度用二分

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
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 1000010;
int a[N], C[N], op[N], s[N];
int n, m;

inline int lowbit(int x) {return x&(-x);}

void update(int x, int data) {
    while (x <= n) { C[x] += data; x += lowbit(x); }
}

int sum(int x) {
    int ret = 0;
    while (x > 0) { ret += C[x]; x -= lowbit(x); } 
    return ret;
}

int main() {

    scanf("%d%d", &n, &m);
    rep(i, m) scanf("%d", &a[i]);

    clr(C, 0);
    clr(s, 0);

    ff(i, n) {
        scanf("%d", &op[i]);
        if (op[i] == -1) {
            int len = sum(n);
           // if (i==2)printf("len = %d\n", len);
            for (int j = 0; a[j] <= len && j < m; ++j) {
                int l = 1, r = n, t;
                while (l <= r) {
                    int mid = (l+r)>>1;
                    int tot = sum(mid);
                    if (tot < a[j]-j) l = mid + 1;
                    else if (tot > a[j]-j) r = mid - 1;
                    else {t = mid; r = mid-1;}
                }
                update(t, -1);
           //     printf("%d: %d\n", i, t);
            }
        } else {
            update(i, 1);
            s[i] = op[i];
        }
    }
    bool ok = true;
    ff(i, n) if (op[i] != -1){
        int res = sum(i)-sum(i-1);
        if (res) ok=false, printf("%d", s[i]);
    }
    if (ok) printf("Poor stack!");
    puts("");
    return 0;
}
