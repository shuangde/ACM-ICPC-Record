/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : poj-1655 Balancing Act
 *   @description : 树形dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/31 15:32 All rights reserved. 
 *======================================================*/

/*
题意：
   一n个节点的棵树，去掉某个节点后，会变成一个森林.
   这个森林中的每个树都有个节点数量，其中最大节点数设为max
   问删除某个节点后，max最小可以多少？

思路：
    和poj-3107 GodFather完全一样！

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

const int MAXN = 20010;
int tot[MAXN];
int f[MAXN], minx, id;

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
    if (ans < minx) {
        minx = ans;  
        id  = u;
    } else if(ans == minx) {
        id = min(id, u); 
    }
    return tot[u];
}

int main(){
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        
        scanf("%d", &n);

        initAdj();
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v); 
            addEdge(u, v);
            addEdge(v, u);
        }
        minx = INF;
        dfs(1, -1);
        printf("%d %d\n", id, minx);
    }

    return 0;
}
