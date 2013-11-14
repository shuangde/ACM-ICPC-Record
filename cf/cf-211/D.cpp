
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

const int MAXN = 100010;
int p[MAXN], b[MAXN], n, m, a;

int main() {

    while (~scanf("%d%d%d", &n, &m, &a)) {
        rep(i, n) scanf("%d", &b[i]);
        rep(i, m) scanf("%d", &p[i]);
        sort(b, b+n);
        sort(p, p+m);

        int pb=0, pp=0;
        int cnt = 0, used = 0;
        while (pb < n && pp < m) {
            
        }
    }
    return 0;
}
