
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
#include <bitset>
#define MP make_pair
#define PB push_back
#define SQ ((x)*(x))
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

const int MAXN = 8000000;

bitset<102>mask[102];

int main() {

    int n; 
    scanf("%d", &n);
    rep(i, n) {
        int m; 
        scanf("%d", &m); 
        rep(j, m) {
            int x;
            scanf("%d", &x); 
            mask[i].set(x);
        }
    }
    rep(i, n) {
        bool ok = true;
        rep(j, n) if ( i != j) {
            if (mask[i] == (mask[i] | mask[j])) {
                ok = false; break;
            }
        } 
        puts(ok?"YES":"NO");
    }
    return 0;
}
