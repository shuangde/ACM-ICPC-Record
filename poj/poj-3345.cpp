/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : poj-3345 Bribing FIPA
 *   @description : 树形背包dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/24 11:30 All rights reserved. 
 *======================================================*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 210;

vector<int>adj[MAXN];
map<string, int>name;
int cost[MAXN];
int f[MAXN][MAXN];
int tot[MAXN];
bool deg[MAXN];
vector<string>str[MAXN];
char buf[MAXN], buf2[MAXN];
int n, m;

inline void read() {

    // clear
    for (int i = 0; i <= n; ++i)
        adj[i].clear(), str[i].clear();
    name.clear();

    int idx = 1;
    // read
    string buf;
    for (int i = 1; i <= n; ++i) { 
        getline(cin, buf);
        stringstream sin(buf);
        string s;
        int v;
        sin >> s >> cost[i];
        name[s] = i;
        while (sin >> s) {
            str[i].push_back(s); 
        }
    }

    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; ++i) {
        for (int e = 0; e < str[i].size(); ++e) {
            int v = name[str[i][e]];
            adj[i].push_back(v);
            deg[v] = true;
        }  
    }

    for (int i = 1; i <= n; ++i)
        if (!deg[i])
            adj[0].push_back(i);
} 

int dfs(int u) {
    tot[u] = 1;

    // count vertex
    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e];
        tot[u] += dfs(v);
    }

    f[u][0] = 0;
    f[u][1] = cost[u];
    if (u) {
        for (int i = 1; i <= tot[u]; ++i)
            f[u][i] = cost[u];
    }

    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e];

        for (int i = tot[u]; i >= 1; --i) {
            if (i <= tot[v])
                f[u][i] = min(f[u][i], f[v][i]);
            for (int j = 1; j <= tot[v] && j <= i; ++j) 
                f[u][i] = min(f[u][i], f[u][i-j] + f[v][j]); 
        }
    }
    return tot[u];
}

int main(){

    while (gets(buf) && buf[0] != '#'){

        sscanf(buf, "%d%d", &n, &m);
        read();
        memset(f, INF, sizeof(f));
        dfs(0);
        int ans = INF;
        for (int i = m+1; i <= n+1; ++i)
            ans = min(ans, f[0][i]);
        printf("%d\n", ans);
    }

    return 0;
}
