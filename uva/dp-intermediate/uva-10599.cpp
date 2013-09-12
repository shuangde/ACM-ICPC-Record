/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10599 Robots(II)
 *   @description : dp，记忆化搜索
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/09 17:46 All rights reserved. 
 *======================================================*/
/*
题意：
给一个n*m大小的网格，有一些格子上面会有一个垃圾。机器人从左上角(1,1)出发，每次只能选择向右，或者向下走一步，
终点是(n, m)。问最多可以捡多少个垃圾？ 且捡最多垃圾有几种路径方案？注意路径方案指和有垃圾的格子有关。

思路：
一开始没注意到方案只和有垃圾的格子有关，当作水题做，结果输出的方案数比样例大了非常多。然后又想了下。
根据题意，路径只和有垃圾的格子有关，那么我们可以把这个网格抽象成一个图，图的节点就是有垃圾的格子，然后加上
一些边把这些格子连起来。那么关键就是怎样加这些边？
我们知道，对于点(i, j)，只能选择走到(x, y) x>=i, y>=j，如果把所有有垃圾的点(x,y)都和(i,j)用边连起来，那么估计就要TLE了。

对于点(i,j)首先，它可以直着往下走，那么往下碰到的第一个有垃圾的点，就可以和当前点连成一边。
然后还可以往右边走，和往右下角走，那么就从从当前行一直往下行枚举，对于每一行，从j+1列开始取第一个有垃圾的点，可以加一条边。

注意，上面所谓的“加边”，只是一种思考方式，实际写代码时不需要真的去建图。

f(i, j) 表示从点(i,j)出发最多可以捡到多少个垃圾。
cnt(i, j) 表示从点(i, j)出发，捡最多垃圾有多少种方案。

那么,
f(i, j) = max{ f(x, y) + 1 | 点(x,y)是和(i,j)有边的相连的点} （“有边”的定义看上面分析）
cnt(i, j) = sum( cnt(x, y) | 点(x, y)是和(i,j)相连的点 && f(x,y) = f(x,y)+1)

输出路径很简单，记录一下转移过程即可。

需要注意的是，点（1,1）和（n,m）可能会没有垃圾，这时我们就手动给他们增加一个垃圾，输出时不要输出这点就可以了

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 110;
int mat[MAXN][MAXN];
int  f[MAXN][MAXN];
int  cnt[MAXN][MAXN];
int next[MAXN][MAXN][2];
bool ok1, ok2;

int n, m;


int dfs(int x, int y) {
    int& ans = f[x][y];
    if (ans != -1) return ans;
    
    if (x==n && y==m) {
        cnt[x][y] = 1;
        return ans = 1; 
    }

    int maxx=0, count = 0;
    for (int i = x+1; i <= n; ++i) {
        if (mat[i][y]) {
            maxx = dfs(i, y); 
            count = cnt[i][y]; 
            next[x][y][0] = i;
            next[x][y][1] = y;
            break;
        } 
    }

    int r = m;
    for (int i = x; i <= n; ++i) {
        for (int j = y + 1; j <= r; ++j) {
            if (mat[i][j]) {
                int tmp = dfs(i, j); 
                if (tmp > maxx) {
                    maxx = tmp;
                    count = cnt[i][j];
                    next[x][y][0] = i;
                    next[x][y][1] = j;
                } else if (tmp == maxx) {
                    count += cnt[i][j];
                }
                r = min(j, r);
                break;
            } 
        } 
    } 
    ans = maxx + 1;
    cnt[x][y] = count;
    return ans;
}


void print(int x, int y) {
    if (x==n && y==m) {
        if (ok2)
            printf(" %d", (x-1)*m+y);
    } else {
        if (x==1 && y==1) {
            if (ok1) printf(" %d", (x-1)*m+y);
        } else {
            printf(" %d", (x-1)*m+y); 
        }
        print(next[x][y][0], next[x][y][1]);
    }
}

int main() {

    int cas = 1;
    while (~scanf("%d%d", &n, &m) && n+m!=-2) {

        memset(mat, 0, sizeof(mat));
        int u, v;
        while (~scanf("%d%d", &u, &v) && u+v) {
            mat[u][v] = 1; 
        }

        ok1 = ok2  = true;
        int add = 0;
        if (!mat[n][m]) {
            ok2 = false;
            ++add;
            mat[n][m] = 1; 
        }
        if (!mat[1][1]) {
            ok1 = false;
            ++add;
        }

        memset(f, -1, sizeof(f));
        dfs(1, 1);
        printf("CASE#%d: %d %d", cas++, f[1][1]-add, cnt[1][1]);
        print(1, 1);
        puts("");
    }
    return 0;
}
