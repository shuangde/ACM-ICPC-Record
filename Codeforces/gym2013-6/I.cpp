
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

const int MAXN = 1e6+10;

int64 f[MAXN][2];
int n;
char str[MAXN];

int main(){

    while (~scanf("%d", &n)) {
        scanf("%s", str+1);
        f[0][0] = f[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            if (str[i] == 'A') {
                f[i][0] = f[i-1][0];
                f[i][1] = min(f[i-1][1]+1, f[i-1][0]+1);
            } else {
                f[i][1] = f[i-1][1];
                f[i][0] = min(f[i-1][0]+1, f[i-1][1]+1);
            } 
        }
        cout << f[n][0] << endl;
    }
    return 0;
}
