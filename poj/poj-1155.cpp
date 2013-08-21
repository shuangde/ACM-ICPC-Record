/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：poj-1155 TELE
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *   Copyright (C) 2013/08/18 19:29 All rights reserved. 
 *======================================================*/
/*
题意
   某收费有线电视网计划转播一场重要的足球比赛。他们的转播网和用户终端构成一棵树状结构，
   这棵树的根结点位于足球比赛的现场，树叶为各个用户终端，其他中转站为该树的内部节点。
   从转播站到转播站以及从转播站到所有用户终端的信号传输费用都是已知的，一场转播的总费用等于传输信号的费用总和。
   现在每个用户都准备了一笔费用想观看这场精彩的足球比赛，有线电视网有权决定给哪些用户提供信号而不给哪些用户提供信号。
   写一个程序找出一个方案使得有线电视网在不亏本的情况下使观看转播的用户尽可能多。

思路
   树形背包的入门题。
   f(i, j)，表示子树i转播给j个用户的最大收益值
   这题可以看作是树上的分组背包，每个子树看作是一组物品，这一组物品可以取1个，2个...j个
   然后就是套用分组背包的算法了

   f(i, 1) = w(i), 当点i是叶子节点时
   f(i, j) = max{ f(i, j-k) + f[v][k] - w(i, v) | v是i的儿子节点， 0<=k<=j}

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

const int MAXN = 3010;

namespace Adj{
    int size, head[MAXN];
    struct Node {int v, next, w; }E[MAXN];
    void initAdj() { size = 0; memset(head, -1, sizeof(head)); }
    void addEdge(int u, int v, int w) {
        E[size].v = v;
        E[size].w = w;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;
/////////////////////////////

int n, m;
int val[MAXN];
int f[MAXN][MAXN];

// 返回的是有几个叶子节点
int dfs(int u) {
    // init
    for (int i = 1; i <= m; ++i)
        f[u][i] = -INF; 

    if (head[u] == -1) {
        f[u][1] = val[u]; 
        return 1;
    }

    int sum = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v, w = E[e].w;

        int numLeaf = dfs(v);
        sum += numLeaf;
        // 做分组背包
        for (int s = sum; s >= 1; --s) {
            for (int k = 0; k <= numLeaf && k <= s;  ++k)
                for (int k = 0; k <= numLeaf;  ++k)
                    f[u][s] = max(f[u][s], f[u][s-k] + f[v][k] + w);
        }
    }
    return sum;
}

int main(){

    while (~scanf("%d%d", &n, &m)) {

        initAdj();
        for (int i = 1; i <= n - m; ++i) {
            int x, v, w;
            scanf("%d", &x);
            while (x--) {
                scanf("%d%d", &v, &w);
                addEdge(i, v, -w);
            }
        }

        for (int i = n - m + 1; i <= n; ++i) {
            scanf("%d", &val[i]); 
        }
        dfs(1);
        for (int i = m; i >= 0; --i) {
            if (f[1][i] >= 0) {
                printf("%d\n", i); 
                break;
            } 
        }
    }
    return 0;
}
