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

const int MAXN = 510;
const int dir[4][2] = {0,1,0,-1,1,0,-1,0};
const int maxTime = 3000000;
int n, x, y;
int mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
char p[4000000];
int pt, tot;
char actDir[4], backDir[4];

inline bool isOut(int x, int y) {
    return  (x < 1 || x > n || y < 1 || y > n);
}

bool check(int x, int y,int d) {
    do {
        if (isOut(x, y) || vis[x][y]) return false; 
        if (mat[x][y]) return true;
        x += dir[d][0]; y += dir[d][1];
    }while (true);
}

void dfs(int x, int y) {
    if (!mat[x][y]) {
        p[pt++] = '1'; tot++;
    } 
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if (isOut(dx, dy) || vis[dx][dy] || !check(dx, dy, i)) {
            continue;
        }
        p[pt++] = actDir[i];
        dfs(dx, dy);
        p[pt++] = backDir[i];
    }
    tot--;
    p[pt++] = '2';
}


int main(){
    actDir[0] = 'R'; actDir[1] = 'L';
    actDir[2] = 'D'; actDir[3] = 'U';
    backDir[0] = 'L'; backDir[1] = 'R';
    backDir[2] = 'U'; backDir[3] = 'D';

    while (~scanf("%d%d%d", &n, &x, &y)) {

        tot = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &mat[i][j]), tot += mat[i][j];
        pt = 0; memset(vis, 0, sizeof(vis));
        dfs(x, y);
        if (tot) puts("NO");
        else {puts("YES"); p[pt]=0; puts(p);};
    }
    return 0;
}
