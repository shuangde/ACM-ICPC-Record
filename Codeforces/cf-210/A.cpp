
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
    while (~scanf("%d%d", &n, &k)) {
        int A[n];
        for (int i = 0; i < n-1; ++i)
            A[i] = 1;
        A[n-1] = k - (n-1);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < i+n; ++j)
                printf("%d ", A[j%n]);
            puts("");
        }
    }
    return 0;
}
