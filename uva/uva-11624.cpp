
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
const int dir[4][2] = { {0,-1},{0,1},{1,0},{-1,0}};
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 1050;
int n, m;
char mat[MAXN][MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
int xo, yo;

inline bool isOut(int x, int y) {
    return x<0||y<0||x>=n||y>=m;
}

void bfs() {
    queue<PII> que;
    que.push(MP(xo*m+yo, 0));
    memset(vis, 0, sizeof(vis));
    vis[xo][yo] = true;
    while (!que.empty()) {
        PII tmp = que.front();
        que.pop();
        int x = tmp.first/m, y = tmp.first%m;
        for (int i = 0; i < 4; ++i) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (!isOut(dx, dy) && ( vis[dx][dy] || mat[dx][dy]!='.' || dist[dx][dy]<=tmp.second+1)) continue;
            if (isOut(dx, dy)) {
                printf("%d\n", tmp.second + 1); 
                return;
            }
            vis[dx][dy] = true;
            que.push(MP(dx*m+dy, tmp.second+1));
        }
    } 
    puts("IMPOSSIBLE");
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        queue<PII>que;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            scanf("%s", mat[i]);
            for (int j = 0; j < m; ++j) {
                dist[i][j] = INF;
                if (mat[i][j] == 'F') {
                    vis[i][j] = true;
                    que.push(MP(i*m+j, 0));
                }
                if (mat[i][j] == 'J') {
                    xo=i, yo=j; 
                }
            }
        }
        while (!que.empty()) {
            PII tmp = que.front(); que.pop();
            int x = tmp.first/m, y = tmp.first%m;
            dist[x][y] = tmp.second;
            for (int i = 0; i < 4; ++i) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if (!isOut(dx, dy) && !vis[dx][dy] && mat[dx][dy]=='.') {
                    vis[dx][dy] = true;
                    que.push(MP(dx*m+dy, tmp.second+1));
                }
            }
        }
        bfs();
    }
    return 0;
}
