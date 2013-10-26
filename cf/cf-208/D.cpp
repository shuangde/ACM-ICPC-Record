
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

const int MAXN = 3010;
int a[MAXN], b[MAXN], c[MAXN];

int f[MAXN][4];

int dfs(int l, int r, int cnt1, int cnt2) {

}

int main(){
    
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) 
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &c[i]);
        memset(f, 0, sizeof(f));
        // f[0]两边没
        // f[1]左边有
        // f[2]右边有
        // f[3]两边都有
        f[1][0] = a[i]; f[1][1] = -INF; f[1][2] = b[i]; f[1][3] = INF;
        for (int i = 2; i < n; ++i) {
            f[i][0] =  1;
        }
    }
    return 0;
}
