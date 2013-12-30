
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

int64 f[110][110];
struct Node {
    int val, num;
    bool operator < (const Node& rhs)const{
        return num < rhs.num; 
    }
}arr[110];
int sum[110];

int main(){

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &arr[i].val, &arr[i].num);

        sort(arr, arr+n);

        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + arr[i].val;

        for (int i = 1; i <= n; ++i)
            f[i][i] = (arr[i].val+10)*arr[i].num;

        for (int d = 2; d <= n; ++d) {
            for (int l = 1; l+d-1 <= n; ++l) {
                int r = l + d - 1;
                f[l][r] = (sum[r]-sum[l-1]+10)*arr[r].num;
                for (int k = l; k < r; ++k) 
                    f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]);
            }
        }
        cout << f[1][n] << endl;
    }
    return 0;
}
