/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：hdu-1011
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *   Copyright (C) 2013/08/18 20:27 All rights reserved. 
 *======================================================*/
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
namespace Adj{
    int size, head[MAXN];
    struct Node {int v, next; }E[MAXN*2+10];
    void initAdj() { size = 0; memset(head, -1, sizeof(head)); }
    void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;
///////////////////////////

int n, m;
struct Node {
    int num,cost, val;
}room[MAXN];

int  f[MAXN][MAXN];
bool vis[MAXN];

void dfs(int u) {

    vis[u] = true;

    memset(f[u], 0, sizeof(f[u]));
    int cost = room[u].cost;
    int val  = room[u].val;
    bool flag = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (vis[v]) continue;
        flag = false;
        dfs(v);
        for (int s = m; s >= 1; --s) {
            f[u][s] = max(f[u][s], f[v][s-cost] + val); 
        }
    }
    if (flag) {
        for (int i = cost; i <= m; ++i) 
            f[u][i] = val;
    }
}

int main(){

    while (~scanf("%d %d", &n, &m) && n+m != -2) {
    
        initAdj();
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d%d", &x, &room[i].val); 
            room[i].cost = x/20 + (x%20!=0 || x==0);
        }
    
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        memset(vis, 0, sizeof(vis));
        dfs(1);
        /*
        for (int i = 1; i <= m; ++i)
            printf("%d ", f[1][m]);
        puts("");
        */

        printf("%d\n", f[1][m]);
    }

    return 0;
}
