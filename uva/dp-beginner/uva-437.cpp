/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-437 The Tower of Babylon
 *   @type: 记忆化搜索，DAG上的最长路
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意:
   有n种长宽高为x,y,z的砖头，每种都有无数个。
   砖头可以用不同姿势的方向来盖。
   砖头a以某种姿势可以盖在砖头b上，当且仅当a的底部的长宽都要比b的底部长宽要小。
   问最高可以建多高？

思路:
   对于一个x,y,z砖头，它可以有3中姿势放置。
   (前两个为地面，后一个为高)
   x, y, z
   x, z, y
   y, z, x
   把每种姿势都记录下来，变成了有3*n种固定姿势的砖头。
   然后建图，g[i][j] = true, 表示砖头i可以盖在砖头j上，反之亦然。
   然后就是求dag上的最长路了。


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

const int MAXN = 230;
int n;
bool g[MAXN][MAXN];
int f[MAXN];

struct Node{
    int x, y, h;
}A[MAXN];

bool check(int i, int j) {
    return A[i].x<A[j].x && A[i].y<A[j].y
        || A[i].x<A[j].y && A[i].y<A[j].x;
}

int dfs(int u) {
    if(f[u] != -1) return f[u];
    f[u] = A[u].h;
    for(int i = 0; i < n; ++i) if(g[u][i]){
        f[u] = max(f[u], dfs(i)+A[u].h);
    }
    return f[u];
}

int main(){

    int cas = 1;
    while (~scanf("%d", &n) && n) {

        for(int i = 0; i < n; ++i) {
            scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].h);
            A[n+i].x=A[i].x;   A[n+i].y=A[i].h;   A[n+i].h=A[i].y;
            A[2*n+i].x=A[i].y; A[2*n+i].y=A[i].h; A[2*n+i].h=A[i].x;
        }

        n *= 3;

        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j) {
                g[i][j] = check(i, j);
                g[j][i] = check(j, i);
            }

        int ans = 0;
        memset(f, -1, sizeof(f));
        for(int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i)); 
        }
        printf("Case %d: maximum height = %d\n", cas++, ans);
    }

    return 0;
}
