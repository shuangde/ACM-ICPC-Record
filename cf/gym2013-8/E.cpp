
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

double L, R, M;
char buf[1000000];

void solve() {
    int mon = 0;
    int rest, pay;

    sprintf(buf, "%lf", M);
    for (int i = 0; i < strlen(buf); ++i) {
        if (buf[i] == '.') {
            buf[i] = buf[i+1]; buf[i+1] = buf[i+2]; buf[i+2] = '.'; break;
        }
    }
    sscanf(buf, "%d", &pay);
    sprintf(buf, "%lf", L);
    for (int i = 0; i < strlen(buf); ++i) {
        if (buf[i] == '.') {
            buf[i] = buf[i+1]; buf[i+1] = buf[i+2]; buf[i+2] = '.'; break;
        }
    }
    sscanf(buf, "%d", &rest);

    while (1) {
        if (mon > 1200) break;
        if (rest <= 0) {
            printf("%d\n", mon);
            return ;
        }
        ++mon;
        double add = rest*R/100.0;
        rest += floor(add + 0.5);
        rest -= pay;
    }
    
    puts("impossible");
}
int main(){

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf%lf", &R, &L, &M);
        int mon = 0;
        solve();
    }
    return 0;
}
