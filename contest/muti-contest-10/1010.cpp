/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : 1010
 *   @description :
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/22 12:46 All rights reserved. 
 *======================================================*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <complex>
#pragma comment(linker, "/STACK:16777216")
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 100010;
namespace Adj{
    int size, head[MAXN];
    struct Node{
        int v, next; 
    }E[MAXN * 2 + 10];
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
///////////////////////////////

int n;
int64 tot[MAXN];
bool vis[MAXN];

int64 dfs(int u) {
    vis[u] = true;
    tot[u] = 1;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if(vis[v]) continue;
        tot[u] += dfs(v);
    }
    return tot[u];
}

int64 ans;

void count(int u) {
    vis[u] = true;
    int sum = tot[1] - 1;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (vis[v]) continue;
        ans += (int64)tot[v] * (int64)(sum-tot[v]);
        sum -= tot[v];
    }
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (vis[v]) continue;
        count(v); 
    }
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
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(1);
        memset(vis, 0, sizeof(vis));
        count(1);
        cout << ((int64)n*(n-1) / 2 *(n-2) / 3) - ans << endl;
    }

    return 0;
}
