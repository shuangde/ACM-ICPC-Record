/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source: uva-11552 Fewest Flops
 *   @type:  多维dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意
   给一个字符串，把它分为ｋ块，例如字符串“helloworld”分成2块，"hello", "world"
   每一块里面的字母可以任意的排序。
   最终字符串， 连续的一样的字母算作一个chunk，问总chunks最少是多少？


思路
   f[i][j]: 第i块的第j位排在最后一位的最少chunks

   对于每个单独的一块，它的chunks就是等于出现的不同字母数
   第i块的chunks记做 chunks[i]

   如果第i-1块的最后一位和第i块的第一位是一样的，那么可以合并这两个，总chunks可以减少一个

   f[i][j] = min{  如果i-1块的第k位和i块的第一位不同:  f[i-1][k]+chunks[i], 
   如果i-1块的第k位和i块的第一位相同:  f[i-1][k]+chunks[i]-1  }

 */
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
