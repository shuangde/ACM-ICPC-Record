/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-1292 Strategic game
 *   @description : 树形dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:27 All rights reserved. 
 *======================================================*/

/*
题意:
   给定一棵树，选择尽量少的节点，使得每个没有选中的结点至少和一个已选结点相邻。

思路:
   经典的树形dp题，据说是最小顶点覆盖。
   f[u][0]: 表示不选i点，覆盖这个子树的最少点
   f[u][1]：选i点，覆盖这个子树的最少点


   对于u点，如果选择这个点，那么他的字节点可选也可不选
   如果不选u点的话，那么它的子结点就必须要选！开始时我以为字节点只要至少选一个就可以了，但是这样是错的！
   因为会出现下面这种情况：

   顶点1不选，子节点中2有选了，但是3却没有相邻结点有选。

   所以可以得到状态转移方程：

   f[u][1] = sum{ min{f[v][0], f[v][1]}, v是u的子结点 }
   f[u][0] = sum{ f[v][1], v是u的子结点 }
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 1510;

int n;
int f[MAXN][2];
bool vis[MAXN];
vector<int>adj[MAXN];

void dfs(int u){
    vis[u] = true;
    f[u][0] = 0; f[u][1] = 1;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(vis[v]) continue;
        dfs(v);
        f[u][1] += min(f[v][1], f[v][0]);
        f[u][0] += f[v][1];
    }
}

int main(){

    while(~scanf("%d", &n) && n){

        for(int i=0; i<=n; ++i) 
            adj[i].clear();

        for(int i=0; i<n; ++i){
            int u, x;
            scanf("%d:(%d)", &u, &x);
            for(int j=0, v; j<x; ++j){
                scanf("%d", &v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

        }
        memset(vis, 0, sizeof(vis));
        dfs(0);
        printf("%d\n", min(f[0][0], f[0][1]));
    }

    return 0;
}
