
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


        // f[0], f[1], f[2], f[3]表示状态:
        // 状态为: 010, 110, 011, 111
        // x1x,中间的1表示当前要喂的兔子,
        // 两边的x,如果是1表示再喂当前兔子之前已经喂过了
        // 0表示还没喂过
        // 那么可以知道:
        // f[i][010] = max(f[i-1][011], f[i-1][111]) + a[i];
        // ....
        // 注意最后一个i==n时,没有状态011和111
        f[1][0] = a[1]; f[1][1] = -INF; f[1][2] = b[1]; f[1][3] = -INF;
        for (int i = 2; i <= n; ++i) {
            f[i][0] = max(f[i-1][2], f[i-1][3]) + a[i];
            f[i][1] = max(f[i-1][0], f[i-1][1]) + b[i];
            f[i][2] = max(f[i-1][2], f[i-1][3]) + b[i];
            if (i!=n)
                f[i][3] = max(f[i-1][0], f[i-1][1]) + c[i];
        }
        printf("%d\n", max(f[n][0], f[n][1]));
    }
    return 0;
}
