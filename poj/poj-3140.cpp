/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : poj-3140 Contestants Division
 *   @description : 树形dp, 计数问题
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/31 14:45 All rights reserved. 
 *======================================================*/

/*
题目：
   给n个节点的带权树，删掉其中一边，就会变成两颗子树，
   求删去某条边使得这这两颗子树的权值之差的绝对值最小。

思路：
   直接dfs一次，计算所有子树的权值总和tot[i]
   删掉一条边(v, fa)，fa是v的父亲节点，
   那么v字数总总和为tot[v]，显然另一棵子树的权值总和就是sum-tot[v]，
   最总取最小绝对值即可。
   这题要注意用long long

ps:  
连续做了几道网上找的所谓的“删点或者删边类树形DP”，感觉都是直接计数枚举的水题啊，这不是dp吧....

 */
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

const int MAXN = 100010;

namespace Adj {
    int size, head[MAXN];
    struct Node{
        int v, next; 
    }E[MAXN*2];
    inline void initAdj(){
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

int n, m;
int num[MAXN];
int64 ans, sum;

int64 Abs(int64 a) {
    return a<0?-a:a;
}

int64 dfs(int u, int fa) {

    int64 tot = num[u];
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (v == fa) continue;
        tot += dfs(v, u);
    }

    ans = min(ans, Abs(sum-tot-tot));

    return tot;
}


int main(){

    int cas = 1;
    while (~scanf("%d%d", &n, &m) && n + m) {

        sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num[i]);
            sum += num[i];
        }

        initAdj();
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        ans = sum;
        dfs(1, -1);
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
