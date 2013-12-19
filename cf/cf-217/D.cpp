
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

const int MAXN = 2010;
char mat[MAXN][MAXN];
int row[MAXN][MAXN], col[MAXN][MAXN];
int n, m;
int up, down, Left, Right;

bool inBorder(int i, int j) {
    if ((i==up || i==down) && j >=Left && j <= Right) return true;
    if ((j==Left || j==Right) && i>=up && i <= down) return true;
    return false;
}

bool check() {
    ff(i, n) ff(j, m) if (mat[i][j] == 'w') {
        if (!inBorder(i, j)) return false;
    }
    return true;
}

bool solve() {
    int h = down - up, w = Right - Left;
    int add = abs(h-w);
    if (h > w) {
        // 只能向一边移动
        if (Left == Right && (down-up<2 || down-up>=2 && col[down-1][Left]-col[up][Left])) { 
            if (Left-add >= 1) {
                Left -= add;
            } else if (Right+add <= m) {
                Right += add;
            } else return false; 
            return true;
        }
        // 左竖线向左移动
        if (down-up>=2 && col[down-1][Left]-col[up][Left] == 0) {
            while (Left>1 && add) --Left, --add;
        }
        // 右竖线向右移动
        if (down-up>=2 && col[down-1][Right]-col[up][Right] == 0) {
            while (Right<m && add) ++Right, --add;
        }
        return !add;
    } else {
        // 只能向一边移动
        if (up==down && (Right-Left<2 || Right-Left>=2 && row[up][Right-1]-row[up][Left])) {
            if (up-add >= 1) {
                up -= add; 
            } else if (down + add <= n) {
                down += add; 
            } else return false;
            return true;
        }
        // 上横线向上移动
        if (Right-Left>=2 && row[up][Right-1]-row[up][Left] == 0) {
            while (up>1 && add) --up, --add;
        }
        // 下横线向下移动
        if (Right-Left>=2 && row[down][Right-1]-row[down][Left] == 0) {
            while (down<n && add) ++down, --add;
        }
        return !add;
    }
    return true;
}



int main() {

    while (~scanf("%d%d", &n, &m)) {

        up = down = Left = Right = -1;
        clr(row, 0); clr(col, 0);

        ff(i, n) {
            scanf("%s", mat[i]+1);
            ff(j, m) {
                row[i][j] = row[i][j-1] + (mat[i][j]=='w'); 
                col[i][j] = col[i-1][j] + (mat[i][j]=='w');
                if (mat[i][j] == 'w') {
                    if (up==-1) {
                        up = down = i;
                        Left = Right = j;
                    } else {
                        cmin(up, i);
                        cmax(down, i);
                        cmin(Left, j);
                        cmax(Right, j);
                    }
                }
            }
        }

        if (!solve()) {
            puts("-1");
        }
        else {

            if (!check()) { 
                puts("-1");
                continue;
            }

            for (int i = Left; i <= Right; ++i) {
                if (mat[up][i] != 'w')  mat[up][i] = '+';
                if (mat[down][i] != 'w')  mat[down][i] = '+';
            }
            for (int i = up; i <= down; ++i) {
                if (mat[i][Left] != 'w')  mat[i][Left] = '+';
                if (mat[i][Right] != 'w') mat[i][Right] = '+';
            }
            ff(i, n) puts(mat[i]+1);
            puts("");
        }
    }
    return 0;
}
