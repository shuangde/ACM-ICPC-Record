
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

int main(){

    int n, sum = 0, cnt = 0, minx = INF;
    scanf("%d", &n);
    rep(i, 2*n-1) {
        int a;
        scanf("%d", &a);
        sum += abs(a);
        if (a < 0) ++cnt;
        minx = min(minx, abs(a));
    }
    if (cnt&1 && (n%2)==0) printf("%d\n", sum-minx*2);
    else printf("%d\n", sum);
    return 0;
}
