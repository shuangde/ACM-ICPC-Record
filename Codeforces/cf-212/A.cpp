
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
const int MAXN = 1000010;
int arr[MAXN];
int n, m, k;
PII a, b;

const int N = 8;
char mat[10][10];
int vis[10][10][10][10];

const int dir[4][2] = {
    {-2,-2}, {-2,2},{2,2},{2,-2},
};

bool isOut(int x, int y) {
    return x<0||y<0||x>=8||y>=8;
}

bool dfs(int x1, int y1, int x2, int y2) {
    if (x1==x2&&y1==y2&&mat[x1][y1]!='#'){
        return true; 
    }
    vis[x1][y1][x2][y2] = true;
    for (int i = 0; i < 4; ++i) {
        int dx1 = x1 + dir[i][0];
        int dy1 = y1 + dir[i][1];
        if (isOut(dx1, dy1)) continue;
        for (int j = 0; j < 4; ++j) {
            int dx2 = x2 + dir[j][0];
            int dy2 = y2 + dir[j][1];
            if (isOut(dx2, dy2) || vis[dx1][dy1][dx2][dy2]) continue;
            if (dfs(dx1, dy1, dx2, dy2)) return true;
        }
    }
    return false;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        a.first = -1; b.first = -1;
        for (int i = 0; i < 8; ++i) {
            scanf("%s", mat[i]);
            for (int j = 0; j < 8; ++j) if (mat[i][j] == 'K'){
                if (a.first == -1) {
                    a.first = i, a.second = j; 
                } else if (b.first = -1) {
                    b.first = i, b.second = j;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        if (dfs(a.first, a.second, b.first, b.second)) puts("YES");
        else puts("NO");
    }
    return 0;
}
