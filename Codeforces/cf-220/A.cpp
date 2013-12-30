
// 题意： 给一个n*m的矩阵，和初始位置i,j,以及a,b
// 每次从x,y走到(x-a,y+b),(x-a,y-b),(x+a,y+b),(x+a,y-b)
// 最少步数从(x,y)走到矩形的(1,1),(1,m),(n,1),(n,m)任意一点是多少？

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

const int dir[4][2] = {-1, -1, 1,-1, -1,1, 1,1};
const int N = 1000000;

int n, m, i, j, a, b;

int gao(int x, int y) {
    int dis_x = abs(i-x), dis_y = abs(j-y);
    if (x==i && y==j) return 0;
    if (dis_x % a || dis_y % b) return INF;
    if (x+a>n && x-a<1 || y+b>m && y-b<1) return INF;
    int cnt_x = dis_x / a, cnt_y = dis_y / b;
    int len = abs(cnt_x*b - dis_y);
    if (len % b != 0 || len % b == 0 && (len/b)%2) return INF;
    return max(cnt_x, cnt_y);
}

int main() {


    while (~scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &a, &b)) {
        int ans = INF;
        cmin(ans, gao(1, 1));
        cmin(ans, gao(1, m));
        cmin(ans, gao(n, 1));
        cmin(ans, gao(n, m));
        if (ans == INF) puts("Poor Inna and pony!");
        else printf("%d\n", ans);
    }
    return 0;
}
