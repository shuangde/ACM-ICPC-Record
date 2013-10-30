
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

int n;
int idx;
int vis[20][20];

struct Node {
    int x, y;
};

int main(){

    while (~scanf("%d", &n) && n) {
       // printf("%d\n", n);
        int maxH=0, m = 0;
        memset(vis, 0, sizeof(vis));
        idx = 0;
        int minX = INF;

        //for (int i = 1; i <= n; i += minX) {
        for (int i = 1; i <= n; ++i) {
            int k;  
            scanf("%d", &k);
            minX = INF;
            if (i!=1) {
                int jj = 1;
                for (int p = 1; p <= k; ++p) {
                    int h, w;
                    scanf("%d%d", &h, &w);
                    minX = min(minX, h);
                    while (vis[i][jj]) ++jj;
                    ++idx;
                    for (int x = i; x < i + h; ++x) {
                        maxH = max(maxH, x);
                        for (int y = jj; y < jj + w; ++y)
                            vis[x][y] = idx;
                    }
                    jj += w;
                }
            } else {
                int jj = 1;
                for (int p = 1; p <= k; ++p) {
                    int h, w;
                    scanf("%d%d", &h, &w);
                    minX = min(minX, h);
                    m += w;
                    ++idx;
                    for (int x = i; x < i + h; ++x) {
                        maxH = max(maxH, x);
                        for (int y = jj; y < jj + w; ++y) {
                            vis[x][y] = idx;
                        }
                    }
                    jj += w;
                }
            }
        }

        for (int i = 1; i <= maxH; ++i) {
            // 第一行
            printf(" ");
            for (int j = 1; j <= m; ++j) {
                if (vis[i][j] != vis[i-1][j]) printf("-- "); 
                else printf("   ");
            } puts("");

            // 第二行
            printf("|");
            for (int j  = 1; j <= m; ++j) {
                if (vis[i][j] != vis[i-1][j] && vis[i][j]!=vis[i][j-1]) {
                    printf("%d%d", i, j); 
                } else {
                    printf("  "); 
                }
                if (vis[i][j] != vis[i][j+1]) printf("|");
                else printf(" ");
            } puts("");
        }
        printf(" ");
        for (int i = 0; i < m; ++i) 
            printf("-- ");
        puts("\n");
    }
    return 0;
}
