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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);

const int MAXN = 3500005;
int f[MAXN];
int A[MAXN];
int cnt[MAXN];

int main () {

    int n, k;
    scanf("%d%d", &n, &k);
    int minx = 0x3f3f3f3f, maxx = 0;

    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        minx = min(minx, A[i]);
        maxx = max(maxx, A[i]);
        ++cnt[A[i]];
    }

    if (minx <= k+1) {
        printf("%d\n", minx);
        return 0;
    }

    for (int i = 1; i < 2*maxx+k; ++i)
        cnt[i] += cnt[i-1];

    for (int d = minx; d >= k; --d) {
        int tot=0;
        for (int i=1; i <= maxx/d; ++i) {
            tot += (cnt[i*d+k]-cnt[i*d-1]);
        }
        if (tot==n) {
            printf("%d\n", d);
            return 0;
        }
    }
    return 0;
}
