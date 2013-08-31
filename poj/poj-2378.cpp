/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : poj-2378 Tree Cutting
 *   @description : 树形dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/31 14:10 All rights reserved. 
 *======================================================*/

/*
题意：
 给一颗n个结点的树，节点编号为1~n，把删除一个节点之后，
 剩下的分支中节点数量最多的数量不大于总数量一半的编号全部按顺序输出

思路：
   和poj-3107 GodFather完全一样，只是输出不一样。改为<=n/2的就输出即可。
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 10010;
int tot[MAXN];
int f[MAXN], minx;

namespace Adj {
    int size, head[MAXN];
    struct Node{
        int v, next; 
    }E[MAXN*2];
    inline void initAdj() {
        size = 0;
        memset(head, -1, sizeof(head));
    }
    inline void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;

int n;

int dfs(int u, int fa) {

    tot[u] = 1;
    // count
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (v == fa) continue;
        tot[u] += dfs(v, u);
    }
    // 计算答案
    int& ans = f[u] = n - tot[u];
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (v == fa) continue;
        ans = max(ans, tot[v]);
    }
    minx = min(minx, ans);
    return tot[u];
}

int main(){

    while (~scanf("%d", &n)) {

        initAdj();
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        dfs(1, -1);

        for (int i = 1; i <= n; ++i) 
            if (f[i] <= n/2) {
                printf("%d\n", i);
            }
        puts("");
    }
    return 0;
}
