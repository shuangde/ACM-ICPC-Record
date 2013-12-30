
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define asc(a,b) if(a>b)swap(a,b)
#define des(a,b) if(a<b)swap(a,b)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int r1, c1, r2, c2;

int rook() {
    return (r1!=r2) + (c1!=c2);
}

int bishop(int r1, int c1, int r2, int c2) {
    if (r1==r2 && c1==c2) return 0;
    if ( abs(r1-r2) == abs(c1-c2) ) return 1;
    int add = r2-r1;
    r1 += add; c1 += add;
    if (abs(c1-c2)>=2 && abs(c1-c2)%2==0  ) return 2;
    return 0;
}

int king() {
    return max(abs(r1-r2), abs(c1-c2));
}

int main() {

    while (~scanf("%d%d%d%d", &r1, &c1, &r2, &c2)) {
        printf("%d\n%d\n%d\n", rook(), bishop(r1, c1, r2, c2), king());
    }
    return 0;
}
