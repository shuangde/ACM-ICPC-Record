
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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 1010;
const int dir[4][2] = {0,1,0,-1,1,0,-1,0};

int mat[MAXN][MAXN];
int sumRow[MAXN][MAXN], sumCol[MAXN][MAXN];
int f[MAXN], maxLen;
bool vis[MAXN][MAXN];
int n, m, k;
int oddDeg;

int findMaxLen() {
    maxLen = 0;
    for (int i = 1; i <= n; ++i) {
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= n; ++j) {
            if (mat[i][j]) f[j] = f[j-1] + 1;
            maxLen = max(maxLen, f[j]);
        }
    }
    for (int c = 1; c <= m; ++c) {
        memset(f, 0, sizeof(f));
        for (int r = 1; r <= n; ++r) {
            if (mat[r][c]) f[r] = f[r-1] + 1;
            maxLen = max(maxLen, f[r]);
        } 
    }
}

bool isOut(int x, int y) {
    return x < 1 || x > n || y < 1 || y > m;
}

bool isCon(int x1, int y1, int x2, int y2) {
    if (x1 == x2) { 
        if (y1 > y2) swap(y1, y2);
        return y2-y1+1 == sumRow[x1][y2] - sumRow[x1][y1-1];
    } 
    if (x1 > x2) swap(x1, x2);
    return x2-x1+1 == sumCol[x2][y1] - sumCol[x1-1][y1];
}

int dfs (int x, int y) {
    int ret = 2, deg = 0;
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int dx = x + dir[i][0] * k; 
        int dy = y + dir[i][1] * k;
        if (!isOut(dx, dy) && isCon(x,y,dx,dy)) {
            ++deg;
            ret += k - 1;
            if (!vis[dx][dy]) {
                ret += dfs(dx, dy); 
            }
        }
    }
    oddDeg += deg&1;
    return ret;
}


int main(){

    while (~scanf("%d%d", &n, &m)) {

        memset(sumRow, 0, sizeof(sumRow));
        memset(sumCol, 0, sizeof(sumCol));
        int one = 0;
        int x=0, y = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &mat[i][j]);
                one += mat[i][j];
                if (!x && mat[i][j]) {x=i, y=j;}
                sumRow[i][j] = sumRow[i][j-1] + mat[i][j];
                sumCol[i][j] = sumCol[i-1][j] + mat[i][j];
            }
        }
        findMaxLen();
        bool flag = false;
        for (k = 2; k <= maxLen; ++k)if ((maxLen-1)%k==0) {
            oddDeg = 0;
            memset(vis, 0, sizeof(vis));
           // printf("k = %d ", k);
            if (dfs(x, y) == one*2 && (oddDeg==0 || oddDeg==2)) {
                flag = true;
                printf("%d ", k);
            }
        }
        if (!flag) printf("-1");
        printf("\n");
    } 

    return 0;
}
