/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-12260 Free Goodies
 *   @type: dp,贪心
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
/*
题意：
Petra和Jan分n个糖果，每个人轮流拿，一次只能拿一个，抽签决定谁先开始拿
每个糖果有两个值x,y, 如果Petra拿了会获得值x, Jan拿了会获得值y
Petra每次都选择对自己价值最大的(x最大)拿，如果有多个x相同大，选择y值最小的
Jan选择的策略是，要让自己最终获得的总价值最大, 并且在这个的前提下，要让Petra的值也尽量大
问最终他们获得的价值各是多少？

思路：
一开始没有什么思路，就lfj200411讨论了一下, 在各种头脑风暴之下，很快就AC了

先只考虑Petra拿糖的情况，他的策略是贪心的，排序一下，可以知道他一定是从按照顺序依次选择下去的
看样例：
Jan
4 1
3 1
2 1
1 1
1 2
1 3
1 4
这个样例已经按照Petra的贪心策略排序好了，第一个被Jan拿先拿了，第二个一定会被Petra拿去。
接下来，如果Jan选择第3个，那么Petra就会拿第4个，如果Jam选除了第3个意外的任意一个，Petra都会拿走第3个。
所以，Jan每一次的选择策略是，要不要把Petra下一次要拿的那个给“抢过来”！

可以发现假设第一次是Jan开始拿(如果第一次是Petra拿，那么就从第二次开始算)
前1个，Jan最多可以抢1个
前2个，最多可以抢1个(如果拿了第1个，第2个一定会给Petra拿走，如果不拿第1个，那第1个就被Petra拿走了, Jan怎么也不可能拿走2个)
前3个, 最多可以抢2个
前4个，最多可以抢2个
前5个，最多可以抢3个
...（以下省略）
规律是，前i个，最多可以抢(i+1)/2个

所以，我们可以用状态f(i, j),表示前i个，抢j个的时候，自己的最大值

f(i, j) = max{ f(i-1, j), f(i-1,j-1) + y(i) |  当f(i-1, j-1)状态可达时);

另外，题目要有一个限制：在Jan最大价值的情况，让Petra的价值也最大。

那么，sum = x1+x2+x3+...xn, sum是所有糖果对Petra的价值之和

每当Jan抢了一个的时候，Petra的sum就会减少xi, 我们要让所有减少的xi之和最少，
这样，可以把物品x值看作是花费， y值看作是价值，目标是让Jan拿最大价值的情况下，花费最少
那么我们可以再维护一个数组cost(i, j)即可



*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 1010;
struct Node{
    int x, y;
    bool operator < (const Node& rhs) const {
        if (x != rhs.x) return x > rhs.x;
        return y < rhs.y;
    }
}arr[MAXN];

int n;
int f[MAXN][MAXN/2];
int cost[MAXN][MAXN/2];
char name[10];

int main(){
    
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &n);

        scanf("%s", name);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &arr[i].x, &arr[i].y);
            sum += arr[i].x;
        }

        sort(arr+1, arr+1+n);

        memset(f, 0, sizeof(f));
        memset(cost, 0, sizeof(cost));

        int cur = 0;
        for (int i = (name[0]=='P'?2:1); i <= n; ++i) {
            ++cur;
            for (int j = 1; j <= (cur+1)/2; ++j) {
                int& ans = f[i][j] = f[i-1][j];
                cost[i][j] = cost[i-1][j];

                if (j==1 || f[i-1][j-1]) { 
                    int tmp = f[i-1][j-1] + arr[i].y;
                    if (tmp > ans) {
                        ans = tmp;
                        cost[i][j] = cost[i-1][j-1] + arr[i].x;
                    } else if (tmp == ans) {
                        cost[i][j] = min(cost[i][j], cost[i-1][j-1]+arr[i].x);
                    }
                }
            }
        }
        printf("%d %d\n", sum-cost[n][(cur+1)/2], f[n][(cur+1)/2]);
    }
    return 0;
}
