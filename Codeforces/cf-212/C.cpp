
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
const int MAXN  = 5010;

int r[MAXN][MAXN];
int arr[MAXN];
int n;

int main() {

    while (~scanf("%d", &n)) {
        rep(i, n) scanf("%d", &arr[i]);
        for (int i = n-1; i >= 0; --i) {
            r[i][i] = 0;
            for (int j = i+1; j < n; ++j) {
                r[i][j] = r[i][j-1];
                if (arr[i] > arr[j])
                    r[i][j]++;
            }
        }
        int64 maxx = -INF, tot = 0;
        int64 sum = 0;

        for (int i = 1; i < n; ++i) {
            int64 cnt = 0, cnt1 = 0;
            for (int j = i-1; j >= 0; --j) {
                if (arr[j] > arr[i]) ++cnt;
                int64 tmp;
                tmp = (r[j][i-1]-cnt1)+cnt-(i-1-j-r[j][i-1]+(arr[i]>arr[j]));
                if (tmp > maxx) {
                    maxx = tmp;
                    tot = 1;
                } else if (tmp == maxx) {
                    ++tot;
                }
                if (arr[j] < arr[i]) ++cnt1;
            }
            sum += cnt;
        }
        cout << sum - maxx << " " << tot << endl;
    }
    return 0;
}
