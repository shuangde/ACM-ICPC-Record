
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
int64 sum[120];
bool vis[120][120];
vector<PII>vt;

void output() {
    ff (i, n) {
        if (i) printf(" %d", arr[i]);
        else printf("%d", arr[i]);
    }
    puts("");
}

void solve() {
    /*
    sort(vt.begin(), vt.end());

    for (int i = 0; i < vt.size(); ++i)
        printf("%d %d\n", vt[i].first, vt[i].second);

    for (int i = 0; i < vt.size(); ++i) {
        if (arr[vt[i].first] > arr[vt[i].second]) {
            swap(arr[vt[i].first], arr[vt[i].second]); 
            output();
            return;
        }
    } */
}

int main() {

    int T, cas=1;
    scanf("%d", &T);
    while (T--) {
        printf("Case %d:\n", cas++);
        scanf("%d", &n);

        ff(i, n) scanf("%d", &arr[i]);

        int64 sum = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i+len-1 <= n; ++i) {
                for (int j = i; j <= i+len-1; ++j)  {
                    sum += arr[j];
                    cnt[j]++;
                }
            }
        }
        ff(i, n)printf("%d ", cnt[i]);
        puts("");
        continue;

        /*
        memset(vis, 0, sizeof(vis));
        int maxx = 0;

        vt.clear();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) if (i!=j){

                int tmp;

                if (i < j) {
                    int64 tot = sum[j] - sum[i];
                    tmp = tot*2 + arr[i] * 2 * (j-i); 
                } else {
                    int64 tot = sum[i] - sum[j];
                    //tmp = tot*2 
                }

                if (tmp > maxx) {
                    maxx = tmp;
                    vt.clear();
                    vt.push_back(MP(i, j)); 
                } else if (tmp == maxx) {
                    vt.push_back(MP(i, j)); 
                }
            }
        }
        */
        solve();
    }
    return 0;
}
