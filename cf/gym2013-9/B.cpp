
// 最长公共子串dp
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
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 1200;
char str1[MAXN], str2[MAXN];
int n, d[MAXN][MAXN];
bool solve() {
    memset(d, 0, sizeof(d));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ( abs(str1[i] - str2[j]) <= 1) {
                d[i][j] = d[i-1][j-1] + 1; 
                if (d[i][j] * 2 >= n) return true;
            }
        } 
    }
    return false;
}

int main(){

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s%s", &n, str1 + 1, str2 + 1);
        if (solve()) puts("POSITIVE");
        else puts("NEGATIVE");
    }
    return 0;
}
