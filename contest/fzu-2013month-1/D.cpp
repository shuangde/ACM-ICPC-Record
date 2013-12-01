
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
char str[120];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        sort(str, str+strlen(str));
        if (str[0] == '0') {
            for (int j = 1; str[j]; ++j)
                if (str[j] != '0') {
                    swap(str[0], str[j]) ;
                        break;
                }
        }
        puts(str);
    } 
    return 0;
}
