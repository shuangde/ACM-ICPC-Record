/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：hdu-1011 Starship Troopers
 *   @description: 树形dp
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
