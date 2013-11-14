
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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define FF(i,n) for(int i = 1; i <= n; ++i) 
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 5010;
int n;
int64 f[2][MAXN];
int a[MAXN], b[MAXN];

int main(){

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), b[i] = a[i];

    sort(b+1, b+1+n);

    memset(f, INF, sizeof(f));
    f[0][0] = f[1][0] = 0;

    int64 ans = INF;
    int pt = 0;
    for (int i = 1; i <= n; ++i) {
        pt = !pt;
        for (int j = 1; j <= n; ++j) {
            f[pt][j] = min(f[!pt][j], min(f[!pt][j-1], f[pt][j-1])+abs(a[j]-b[i]));
        }
    }
    cout << f[pt][n] << endl;;
    return 0;
}
