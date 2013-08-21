/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : hdu-1011 Starship Troopers
 *   @description : 树形背包dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/18 20:27 All rights reserved. 
 *======================================================*/

/*
题意：
   有n个洞穴编号为1～n，洞穴间有通道，形成了一个n-1条边的树, 洞穴的入口即根节点是1。
   每个洞穴有x只bugs，并有价值y的金子，全部消灭完一个洞穴的虫子，就可以获得这个洞穴的y个金子.
   现在要派m个战士去找金子，从入口进入。每次只有消灭完当前洞穴的所有虫子，才可以选择进入下一个洞穴。
   一个战士可以消灭20只虫子，如果要杀死x只虫子，那么要x/20向上取整即(x+19)/20个战士。
   如果要获得某个洞穴的金子，必须留下足够杀死所有虫子的战士数量， 即(x+19)/20个战士，然后这些留下战士就不能再去其它洞穴
   其他战士可以继续走去其它洞穴，可以选择分组去不同的洞穴。
   战士只能往洞穴深处走，不能走回头路
   问最多能获得多少金子？

思路：
   这题一开始没有理解好题意，所以WA了多次，理解好题意就不难了。
   我们可以知道每个节点的花费cost(i) = (x(i)+19)/20。
   那么，
   f(i, j)：表示i子树，用j个战士最多可以获得的价值。
   如果i有s个儿子节点，那么就形成了s组的物品，对每组物品进行分组背包。
   每一组可以选择派1,2...j-cost(i)个战士去，为什么最多是j-cost(i)？因为还要留下cost(i)个战士消灭当前洞穴的虫子。
   这样就可以得到状态转移了：

   f(i, j) = max { max{ f(i, j-k) + f(v, k) | 1<=k<=j-cost(i) } |  v是i的儿子节点 }

   这题要特别注意的是，如果是叶子节点，并且叶子节点的花费为0,那么要让他的花费变为1,因为必须派一个战士走向叶子节点才可以获得金子.

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
const double PI  = acos(-1.0);

const int MAXN = 110;

int n, m;
struct Node {
    int num,cost, val;
}room[MAXN];
int  f[MAXN][MAXN];
bool vis[MAXN];

vector<int>adj[MAXN];

void dfs(int u) {

    vis[u] = true;
    memset(f[u], 0, sizeof(f[u]));

    // 如果是叶子节点，并且花费为0时，要变成1
    if (!room[u].cost && adj[u].size()==1 && u!=1) 
        room[u].cost = 1;

    // 初始化
    for (int i = room[u].cost; i <= m; ++i)
        f[u][i] = room[u].val;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (vis[v]) continue;
        dfs(v);
        for (int s = m; s >= room[u].cost; --s) {
            for (int j = 1; s-j >= room[u].cost; ++j)
                f[u][s] = max(f[u][s], f[u][s-j] + f[v][j]);
        }
    }
}

int main(){

    while (~scanf("%d %d", &n, &m) && n+m != -2) {

        for (int i = 1; i <= n; ++i)
            adj[i].clear();

        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d%d", &x, &room[i].val); 
            room[i].cost = x/20 + (x%20!=0);
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (m==0) {
            puts("0");
            continue;
        }

        memset(vis, 0, sizeof(vis));
        vis[1] = true;
        dfs(1);
        printf("%d\n", f[1][m]);
    }

    return 0;
}
