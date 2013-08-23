/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : hdu-4003 Find Metal Mineral
 *   @description : 树形背包dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 16:21 All rights reserved. 
 *======================================================*/

/*
题意:
    给一棵n个节点的树, 节点编号为1~n, 每条边都有一个花费值. 
    有k个机器人从S点出发, 问让机器人遍历所有边,最少花费值多少?

思路:
    前天看的这题, 今天才想出来的. 方法想出来后,代码很简单
    最近做的几道dp,都是一开始没什么想法,然后过两天再想就想出来了,也许是因为人的潜意识其实会一直在想某个问题

    翻看一下网上其他人的做法, 和我的稍有不同, 他们是用f(i, j)表示子树i用j个机器人的最少花费, 一开始我也是这样
    去想,但是没想到怎么去状态转移.

    然后我换了一种思路,很快就想出来了

    如果从根节点出发,遍历所有节点之后再回到原点, 那么最少的花费一定是所有边的权值之和sum的两倍, 因为每条边都走了两次.

    而这题, 遍历完之后,并不需要走回出发点, 所以, 有些边只走了一次就可以了,
    如果用1台机器人走, 最少的的花费 = sum * 2 - {根节点到叶子节点路径的最大权值和}
    如果是j台机器走, 我们要让j台机器人只走一次的边的权值之和尽量少, 也就是减少的花费尽量大.

    那么, 我的状态表示为:
    f(i, j) 表示子树i用j个机器人最多可以减少的花费.
    
    对于i节点, 它的每个子节点的子树是一组物品, 我们可以选择派1,2,...j个机器人走去
    需要注意, 如果派x个机器人走向某个子节点v, 那么边edge(i, v)就会被走了x次, 花费了x*w(i, v).
    而原始的sum中每条边只走了两次, 所以最与edge(i, v)的花费减少了 2*w(i,v) - x*w(i,v)

    最后可以得到状态转移式:

    f(i, j) = max{ max{f(i, j-k) + f(v, k) + 2*w(i,v) - k*w(i,v) | 1<=k<=j }  | v是i的儿子节点 }
    
    最终答案ans = sum * 2 - f(s, k)

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 10010;

namespace Adj {
    int size, head[MAXN];
    struct Node{
        int v, next, w; 
    }E[MAXN*2];
    inline void initAdj() {
        size = 0;
        memset(head, -1, sizeof(head));
    }
    inline void addEdge(int u, int v, int w) {
        E[size].v = v;
        E[size].w = w;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;
//////////////////////////////
vector<int>adj[MAXN];
int f[MAXN][12];
bool vis[MAXN];
int n, m, k;

void dfs(int u) {
    vis[u] = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        int w = E[e].w;
        if (vis[v]) continue;
        dfs(v);
        for (int i = k; i >= 1; --i) {
            for (int j = 1; j <= i; ++j) 
                f[u][i] = max(f[u][i], f[u][i-j] + f[v][j] + 2*w - j*w);
        }
    }
}

int main(){

    while (~scanf("%d%d%d", &n, &m, &k)) {
        
        initAdj();
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            sum += w;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
        dfs(m);
        printf("%d\n", sum * 2 - f[m][k]);
    }

	return 0;
}
