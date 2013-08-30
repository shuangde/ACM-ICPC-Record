/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : hdu-3586 Information Disturbing
 *   @description : 树形dp + 二分
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/30 12:01 All rights reserved.
 *======================================================*/
/*
题意：
   给一棵n个节点的树，节点编号为1～n，根节点为1。每条边有权值，砍掉一条边要花费cost(w)
   要砍掉一些边， 使得每个叶子节点无法走到根节点。
   要求砍掉花费总和不能超过m的情况下，让每条边花费上限尽量低

思路：
   二分可以砍的边的权值上限，然后树形dp
   f[i]: 表示让i子树所有的叶子节点无法到达i点的最小花费
   f[i] = sum { min(w(i,v), f[v]) | v是i的儿子节点 }
   而这题有一个上限权值，即权值大于上限的就不能去砍。
   所以上面的转移要改一下
   if (w(i, v) > 上限) f[i] += f[v];
   else  f[i] += min(w(i,v), f[v]);

   然后，如果f[1]<=m，那么这个上限就符合条件
   这一题，如果用INF初始化的话，那么INF一定要大于m的最大值1000000

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MP make_pair
using namespace std;

typedef long long int64;
typedef pair<int,int>PII;
const int INF = 1000010;

const int MAXN = 1010;

namespace Adj {
    int size, head[MAXN];
    struct Node{
        int v, w, next;   
    }E[MAXN*2];
    inline void initAdj(){
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

int n, m, mid;
int f[MAXN];

void dfs(int u, int fa) {

    // 如果是叶子节点
    if (E[head[u]].v == fa) {
        f[u] = INF;
        return;
    }
    f[u] = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        int w = E[e].w;
        if (v == fa) continue;
        dfs(v, u);
        if (w > mid)
            f[u] += f[v];
        else
            f[u] += min(w, f[v]);
    }
}

int main(){

    while (~scanf("%d%d", &n, &m) && n + m) {

        initAdj();
        int l = 0, r = 0;
        for (int i = 0; i < n-1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            r = max(r, w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        int ans = INF;

        while (l <= r) {
            mid = (l+r) >> 1;
            dfs(1, -1);
            if (f[1] <= m) {
                r = mid - 1; 
                ans = min(ans, mid);
            } else {
                l = mid + 1; 
            }
        }
        if (ans != INF)
            printf("%d\n", ans);
        else 
            puts("-1");
    }
    return 0;
}
