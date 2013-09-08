/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : hdu-4714 Tree2cycle
 *   @description : 树形dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/08 23:29 All rights reserved. 
 *======================================================*/

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
#pragma comment(linker,"/STACK:102400000,102400000")  
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 1000010;
namespace Adj {
    int e, head[MAXN];
    struct Node{
        int v, next; 
    }E[MAXN*2];
    inline void initAdj() {
        e = 0;
        memset(head, -1, sizeof(head));
    }
    inline void addEdge(int u, int v) {
        E[e].v = v;
        E[e].next = head[u];
        head[u] = e++;
    }
}
using namespace Adj;

int n;
int f[MAXN];
int f1[MAXN];
int f2[MAXN];
int cnt;

// 方法一
int dfs(int u, int fa) {
    
    int& ans = f[MAXN];
    int son = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (v == fa) continue;
        son += dfs(v, u);
    }
    if (son >= 2) {
        if (u == 1) {
            cnt += (son-2) * 2; 
        } else {
            cnt += (son-1) * 2; 
        } 
        return 0;
    } else { 
        return 1;
    }
}

// 方法二
void dp(int u, int fa) {

    int first=0, second=0;
    int sum = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (v == fa) continue;
        dp(v, u);
        sum += f2[v] + 2;
        int tmp = (f2[v]+2) - f1[v];
        if (tmp >= first) {
            second = first;
            first = tmp;
        } else if (tmp > second) {
            second = tmp; 
        }
    }
    f1[u] = sum - first;
    f2[u] = sum - first - second;
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
        cnt = 0;
      //  dfs(1, -1);
        dp(1, -1);
        printf("%d\n", f2[1] + 1);
    }

    return 0;
}
