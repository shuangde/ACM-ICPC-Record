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
/*
题意：
   有n个国家，你要获取m个国家的支持，获取第i个国家的支持就要给cost[i]的价钱
   其中有一些国家是老大和小弟的关系，也就是说，如果你获得了某个老大国家的支持，
   那么这个国家的所有小弟(包括小弟的小弟...递归下去)都会无偿免费支持你。
   问最少的花费可以得到m个国家的支持

思路：
   这题还是比较好想的树形dp, 不过输入有些麻烦， 一开始以为每组样例结束都是'#'，结果一直
   RE,后来发现最后一组才是 '#'...
   国家由于是直接给名字的，所以我用map<string, int>来映射保存编号。

   老大和小弟的关系， 其实就是组成了一棵棵的树，那么所有国家的关系就是一个森林。
   为了方便进行树形dp， 在增加一个“超级根节点”，森林里所有树的根节点是“超级根节点”的儿子。

   那么，用f(i, j)表示子树i, 获取j个国家支持的最少花费

   对于子树i，所有节点i的儿子节点都是一组物品，
   对于某个儿子，可以选择让他支持1,2..,j个， 那么就是对所有儿子进行分组背包了。。

   用tot[v]表示子树v的节点个数
   状态转移为：
   f[u][i] = min{ f[u][i], f[u][i-j] + f[v][j] | 1<=j<=tot[v] && j<=i && v是u的儿子 };

 */
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

    // init
    f[u][0] = 0;
    f[u][1] = cost[u];
    if (u) {
        for (int i = 1; i <= tot[u]; ++i)
            f[u][i] = cost[u];
    }
    // dp
    for (int e = 0; e < adj[u].size(); ++e) {
        int v = adj[u][e];
        for (int i = tot[u]; i >= 1; --i) {
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
