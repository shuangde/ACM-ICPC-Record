
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

const int INF = 0x3f3f3f3f;

#define lson(x) ((x)<<1)
#define rson(x) (lson(x)|1)
#define mid ((left+right)>>1)

const int MAXN = 200010;
struct Node {
    int left, right, minx; 
}node[4*MAXN];

void init(int left, int right, int rt) {
    node[rt].left = left; 
    node[rt].right = right;
    if (left == right ) {
        scanf("%d", &node[rt].minx);
        return ;
    }
    int m = mid;
    init(left, m, lson(rt));
    init(m+1, right, rson(rt));
    node[rt].minx = max(node[lson(rt)].minx, node[rson(rt)].minx);
}

int query(int left, int right, int rt) {
    if (node[rt].left == left &&  node[rt].right == right) {
        return node[rt].minx; 
    }
    int m = (node[rt].left + node[rt].right) >> 1;
    if (right <= m) return query(left, right, lson(rt));
    else if (left > m) return query(left, right, rson(rt));
    else return max(query(left, m, lson(rt)), query(m+1, right, rson(rt)));
}

int solve(int left, int right, int rt, int len) {
    if (node[rt].right - node[rt].left + 1 <= len) {
        return node[rt].minx;
    }
    int m = (left+right) >> 1;
    if ( len * 2 <= right-left+1) {
        int res = solve(left, m, lson(rt), len);
        res = min(res, solve(m+1, right, rson(rt), len));
        return res;
    } else {
        return query(left, right, rt);
    }
} 

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        cin >> n;
        init(1, n, 1);
        for (int i = 1; i <= n; ++i) {
            cout << solve(1, n, 1, i) << endl;
        }
    }
    return 0;
}
