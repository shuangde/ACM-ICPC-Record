/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10271 Chopsticks
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/02 23:45 All rights reserved. 
 *======================================================*/
/*
题意：
   刘汝佳请了K个客人到他家吃晚饭，加上他的家人：他的老婆、儿子、女儿、妈妈、爸爸、岳父、岳母，
   那么这顿晚饭一共有K+8个人。因为是吃中餐，所以需要筷子，他家里一共有N根筷子，而且长短不一，
   这时刘汝佳的ACMer本性又暴露出来了，他不按照正常的每个人都给两只筷子，而是每个人分3根筷子，
   其中最长的一根用来叉比较大块的食物，而另外两根较短的筷子当作正常的使用。为了让每个人用得
   更加舒服，显然，要让短的两根筷子长度尽量接近,设这三根筷子的长度为A,B,C(A<=B<=C)，那么较小
   两根会有一个平方差（A-B）^ 2。刘老师要你帮他算，怎样分配，所有人的平方差之和最小？


思路：
   这题已经放着很多天了吧，可能有两个星期了。因为个人及其不喜欢看题解(但是喜欢讨论)，而是享受
   自己慢慢想然后AC出来的那种成就感，所以还有好多看过的题都悬而未决...

   期间本来想和nothi讨论一下，结果他说在高中时做过，好吧，搞过noip的人题目就是做得多。。。
   然后去翻了下那道noi题(njupt 1581)，看了下发现原题很简单。

   原题是每个人只要两根筷子，要让所有人的筷子长度平方差之和最小。那么显然从小到大排序一下，
   f(i, j)表示前i跟筷子，分配给j个人的最小平方差之和。因为所以加道理，可以知道一定要选择相邻的两个
   筷子才能让平方差尽量少，所以得到状态转移
   f(i, j) = min{ f(i-1, j), f(i-2, j-1) + (len[i]-len[i-1])^2 }

   可能正是因为先AC了原题，所以一直限制了我的思路，一直按照上面类似的思路，从小到大排序，然后状态转移，
   但是因为多了第三根最长的，所以不好想。

   如果从小到大排序的话，状态表示会有一个问题， f(i, j)的第i根，一定是最大的那个，所以他一定不会取，这样
   就给状态转移带来了困难。

   后来的某一天，终于想到了：要是从大到小排序会怎样呢？那么f(i, j)的第i根，一定是最小的那根，所以他就可以
   取了！

   然后还有一个问题，要确定以i, i-1作为一双筷子时，前面还有一根筷子可以作为三根最长的那一根，那么，
   只要保证(i-2)-(j-1)*3 >= 1，即前面j-1个人分配完以后至少还剩下有1根筷子，就一定可以作为当前i, i-1组
   的最长那根！

   状态转移就这样出来了：

   当(i-2)-(j-1)*3 < 1时
   f(i, j) = f(i-1, j);

   当(i-2)-(j-1)*3 >= 1时
   f(i, j) = min{f(i-1, j), f(i-2, j-2) + (len[i]-len[i-1])^2}

   Perfect！

 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 5100;
int n, m;
int len[MAXN];
// 前i个筷子，j个人使用
int f[MAXN][1010];

int main(){

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {

        scanf("%d%d", &m, &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &len[i]);
        m += 8;

        sort(len+1, len+1+n, greater<int>());

        memset(f, INF, sizeof(f));
        for (int i = 0; i <= n; ++i)
            f[i][0] = 0;

        for (int i = 3; i <= n; ++i) {
            for (int j = m; j >= 1; --j) {
                f[i][j] = f[i-1][j];
                if (f[i-2][j-1] != INF && (i-2)-(j-1)*3 >= 1)
                    f[i][j] = min(f[i][j], f[i-2][j-1] + SQ(len[i]-len[i-1]));
            }
        }
        printf("%d\n", f[n][m]);
    }
    return 0;
}
