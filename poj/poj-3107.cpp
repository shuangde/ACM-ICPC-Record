/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : poj-3107 Godfather
 *   @description : 树形dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/30 16:26 All rights reserved. 
 *======================================================*/
/*
题意：
   给一颗n个结点的树，节点编号为1~n，问删除一个节点之后，让剩下的分支中节点数量最多的尽量少。
   可能有多种方案，按编号顺序输出。

思路：
   简单的树形dp. 连dp都不能算吧。
   先dfs计算每个节点子树的节点个数tot[i]。
   再次dfs更新答案：
   f[i] = max( n-tot[i], max{tot[v] | v是i的儿子} );
   两个dfs可以合并在一个dfs里完成, 复杂度O(n)

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

const int MAXN = 50010;
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
    // 保存答案
    int& ans = f[u] = n - tot[u];
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (v == fa) continue;
        ans = max(ans, tot[v]);
    }
    minx = min(minx, ans);
    return tot[u];
}

inline int nextInt(){  
    char ch = getchar();  
    while (!isdigit(ch)) ch = getchar();  
    int ret = 0;
    while (isdigit(ch)) {  
        ret = ret * 10 + ch - '0';  
        ch = getchar();  
    }  
    return ret;  
}

int main(){

    while (~scanf("%d", &n)) {

        initAdj();
        for (int i = 0; i < n - 1; ++i) {
            int u = nextInt(), v = nextInt();
            // scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        minx = INF;
        dfs(1, -1);

        bool first = true;
        for (int i = 1; i <= n; ++i) 
            if (f[i] == minx) {
                if (first) first = false, printf("%d", i);
                else printf(" %d", i);
            }
        puts("");
    }
    return 0;
}
