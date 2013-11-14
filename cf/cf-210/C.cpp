
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
#define rep(i, n) for(int i=0; i<n; ++i)
#define ff(i, n) for(int i=1; i<=n; ++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 1e9;
const double eps = 1e-8;

const int MAXN = 5010;
int n, m;
struct Op {
    int type, l, r, val;
}op[MAXN];

int val[MAXN];
int ans[MAXN];

bool judge() {
    rep(i, m) {
        if (op[i].type == 1) {
            for (int j = op[i].l; j <= op[i].r; ++j)  
                val[j] += op[i].val;
        } else {
            int maxx = -INF;
            for (int j = op[i].l; j <= op[i].r; ++j) {
                maxx = max(maxx, val[j]);
            }
            if (maxx != op[i].val) return false;
        }
    }
    return true;
}

int main() {

    while (cin >> n >> m) {
        rep(i, m) scanf("%d%d%d%d", &op[i].type, &op[i].l, &op[i].r, &op[i].val);
        
        ff(i, n) val[i] = 1e9;
        for (int i = m-1; i >= 0; --i) {
            if (op[i].type == 1) {
                for (int j = op[i].l; j <= op[i].r; ++j)
                    val[j] -= op[i].val;
            } else {
                for (int j = op[i].l; j <= op[i].r; ++j)
                    val[j] = min(val[j], op[i].val);
            }
        }

        memcpy(ans, val, sizeof(val));
        if (judge()) {
            puts("YES"); 
            ff(i, n) {
                if (ans[i] > INF) ans[i] = INF;
                if (ans[i] < -INF) ans[i] = -INF;
                printf("%d ", ans[i]);
            }
            puts("");
        } else {
            puts("NO"); 
        }
    }
    return 0;
}
