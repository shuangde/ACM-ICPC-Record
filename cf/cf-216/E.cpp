
// E. Valera and Queries
// 题意： 给n条线段，和m次询问，每次询问有cnt个数:p1,p2..pm(1<=p1<p2<..<pcnt),
// 输出有多少条线段，至少包含cnt个点中的一个点？

//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define SQ ((x)*(x))
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 1000010;
inline int lowbit(int x) {return x&(-x);}

int arr[300010];
int c[N], leftCnt[N], n, m, maxx;
vector<int>R[N], p[300010], point[N];
int64 ans[300010];

void add(int x, int data) {
    for ( ; x <= maxx; x += lowbit(x)) c[x] += data;
}

int sum(int x) {
    int ret = 0;
    for ( ; x > 0 ; x -= lowbit(x)) ret += c[x];
    return ret;
}


int main() {

    scanf("%d%d", &n, &m);
    maxx = -1;
    rep(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++leftCnt[x];
        maxx = max(maxx, y);
        R[y+1].push_back(x);
    }
    ++maxx;
    rep(i, m) {
        int k; scanf("%d", &k);
        p[i].push_back(0);
        rep(j, k) {
            int x; scanf("%d", &x);	
            p[i].push_back(x);
            point[x].push_back(i);
        }
    }
    ff(i, maxx) {
        add(i, leftCnt[i]);
        for (int j = 0; j < R[i].size(); ++j) 
            add(R[i][j], -1);
        for (int j = 0; j < point[i].size(); ++j) {
            int a = point[i][j];
            ans[a] += sum(i) - sum(*(--lower_bound(p[a].begin(), p[a].end(), i)));
        }
    }
    rep(i, m) cout << ans[i] << "\n";
    return 0;
}
