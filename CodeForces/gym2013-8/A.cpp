
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
const int INF = 0x3f3f3f3f;

int val[15];
int num[40];
int n, m;

int main(){

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        vector<int>cost[15];
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < x; ++j)  {
                int v; scanf("%d", &v);
                cost[i].push_back(v);
            }
            scanf("%d", &val[i]);
        }
        for (int i = 1; i <= m; ++i)
            scanf("%d", &num[i]);

        int64 ans = 0;
        for (int i = 0; i < n; ++i) {
            int minx = INF;
            for (int j = 0; j < cost[i].size(); ++j) {
                minx = min(minx, num[cost[i][j]]);
            }
            ans += (int64)minx*(int64)val[i];
        }
        cout << ans << endl;
    }
    return 0;
}
