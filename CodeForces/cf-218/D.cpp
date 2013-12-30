
// 题意： 给n个盘子，按照题目图中的放置，盘i的容量为ai.
// 向第i个盘子倒水，如果盘i满了，水会流到盘i+1, 以此类推.


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
#include <ext/rope>
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
using namespace __gnu_cxx;

typedef pair<int, int >PII;
typedef long long int64;
typedef set<int>::iterator iter;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int MAXN = 2000010;
int a[MAXN], c[MAXN], next[MAXN];

int f[MAXN];
int find(int x) {
    return x==f[x]?x:f[x]=find(f[x]);
}

int main() {

    int n, m;
    while (~scanf("%d", &n)) {

        ff(i, n) scanf("%d", &a[i]);
        
        clr(c, 0);
        for (int i = 0; i <= n+2; ++i) f[i] = i;

        scanf("%d", &m);

        rep(i, m) {
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int p, x;
                scanf("%d%d", &p, &x);
                while (x > 0 && p <= n) {
                    if (a[p] - c[p] > x) {
                        c[p] += x;
                        x = 0;
                    } else if (a[p] - c[p] == x) {
                        c[p] += x;
                        f[p] = find(p+1);
                        x = 0;
                    } else {
                        x -= a[p]-c[p];
                        c[p] = a[p];
                        p = f[p] = find(p+1);
                    }
                }
            } else {
                int x;
                scanf("%d", &x);
                printf("%d\n", c[x]);
            }
        }
    }
    return 0;
}
