#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 100010;

int N, T, f[22][12][5];

int dfs(int x, int t, int y) {
    int& ans = f[x][t][y];
    if (ans != -1) return ans;
    if (x==N && t==T) return ans = 1;
    if (x==N && t<T) return ans = 0;
    if (t > T) return ans = 0;

    ans = 0;
    if (t%2 == 0) {
        for (int i = y+1; i <= 4; ++i)
            ans += dfs(x+1, t, i);
        if (x!=1) {
            for (int i = y - 1;  i >= 1; --i)
                ans += dfs(x+1, t+1, i);
        }
    } else {
        for (int i = y+1; i <= 4; ++i)
            ans += dfs(x+1, t+1, i);
        for (int i = y-1; i >= 1; --i)
            ans += dfs(x+1, t, i);
    }
    return ans;
}

int main () {

    while (cin >> N >> T) {

        memset(f, -1, sizeof(f));
        int64 ans = 0;
        T = 2 * T - 1;
        for (int i = 1; i <= 4; ++i)
            ans += dfs(1, 0, i);
        cout << ans << endl;
    }
    return 0;
}
