
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
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 1000000;
const int64 Max = 1e18;
const int MAXN = 1442251;
int64 sum[MAXN + 2], lineSum[MAXN*2];
int64 n;

void init() {

    int64 val = 0;
    int64 i;
    int lineNum = -1;
    for (i = 1; i <= MAXN; ++i) {
        lineNum += 2;
        val += i + i - 1;
        sum[i] = sum[i-1] + val;
    }
    lineSum[1] = 1;
    for (int i = 2; i <= lineNum; ++i) {
        lineSum[i] = lineSum[i-1] + i;
    }
}

void solve() {
    int64 lineNo = lower_bound(sum+1, sum+1+MAXN, n) - sum;

    if (n == sum[lineNo]) {
        cout << lineNo*lineNo << endl;
        return ;
    }

    int64 reps = (lineNo-1)*(lineNo-1);
    int64 rest = n - sum[lineNo-1];

    if (lineSum[lineNo] >= rest) { // 前部分
        cout << reps + (lower_bound(lineSum+1, lineSum+1+lineNo, rest) - lineSum) << endl; 

    } else {
        rest -= lineSum[lineNo];
        int64 x = lineSum[lineNo-1] - rest;
        int64 *p = lower_bound(lineSum+1, lineSum+lineNo, x);
        while (lineSum[lineNo-1] - *p < rest) --p;
        cout << reps + lineNo + (lineNo-1-(p-lineSum)) << endl;
     //   cout << reps +  (p-lineSum) << endl;
    }
}

int main() {

    freopen("army.in", "r", stdin);
    //freopen("стандартный вывод", "w", stdout);
    init();
    int T, cas = 1;
    scanf("%d", &T);
    while (T--) {
        cin >> n;
        printf("Case %d: ", cas++);
        solve();
    }
    return 0;
}
