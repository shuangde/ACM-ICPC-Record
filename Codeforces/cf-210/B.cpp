
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

int main() {

    int n, k;
    while (cin >> n >> k) {
        int m = n - k;
        if (m == 0) puts("-1");
        else {
            int i = 1;
            if (m%2==0) {
                printf("2 1 ");
                i = 3;
                m -= 2;
            } else {
                printf("1 ");
                m--, i=2;
            }
           // printf("%d\n", m);
            for ( ; i < n && m > 0; i += 2) {
                printf("%d %d ", i+1, i);
                m -= 2;
            }
            for (; i <= n; ++i) {
                printf("%d ", i);
            }
            puts("");
        }
    }
    return 0;
}
