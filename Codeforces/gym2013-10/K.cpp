
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

int n;
int arr[120];
int cnt[120];
int ans[120];

int main() {

    int T, cas=1;
    scanf("%d", &T);
    while (T--) {
        printf("Case %d:\n", cas++);
        scanf("%d", &n);
        vector<PII>vt;
        rep(i, n) {
            scanf("%d", &arr[i]); 
            //cnt[i] = i*(n-i);
            vt.push_back(MP(-(i+1)*(n-i), i));
        }
        sort(arr, arr+n);
        sort(vt.begin(), vt.end());
        rep(i, n) ans[vt[i].second] = arr[i];
        rep(i, n) printf("%s%d", i?" ":"", ans[i]);
        puts("");
    }
    return 0;
}
