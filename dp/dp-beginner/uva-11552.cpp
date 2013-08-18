/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source: uva-11552 Fewest Flops
 *   @type:  dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 1010;
int k;
char str[MAXN];
int f[MAXN][MAXN];
bool vis[130];

int main() {

    int nCase;

    scanf("%d", &nCase);

    while (nCase--) {

        scanf("%d %s", &k, str);

        int len = strlen(str);


        // init
        memset(f, INF, sizeof (f));

        for (int i = 0; i < len / k; ++i) {

            // 计算出Si的chunks
            int chunks = 0;
            memset(vis, 0, sizeof (vis));
            for (int j = i * k; j <= (i + 1) * k - 1; ++j) {
                vis[str[j]] = true;
            }

            for (int j = 'a'; j <= 'z'; ++j)
                if (vis[j]) ++chunks;

            if (i == 0) {
                for (int j = 0; j < k; ++j)
                    f[i][j] = chunks;
                continue;
            }

            for (int j = 0; j < k; ++j) {
                int rear = i * k + j;
                for (int l = 0; l < k; ++l) {
                    int pre = (i - 1) * k + l;
                    if (vis[str[pre]] && (chunks == 1 || str[pre] != str[rear])) {
                        f[i][j] = min(f[i][j], f[i - 1][l] + chunks - 1);
                    } else {
                        f[i][j] = min(f[i][j], f[i - 1][l] + chunks);
                    }
                }
            }

        }

        int ans = INF;
        for (int i = 0; i < k; ++i)
            ans = min(ans, f[len / k - 1][i]);

        printf("%d\n", ans);
    }
    return 0;
}
