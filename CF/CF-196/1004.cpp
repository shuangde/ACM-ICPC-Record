/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：cf-1004 Book of Evil
 *   @type: 树形dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
/*
题意：
给一棵n个结点的树，任意两个节点的距离是指连接两点的最短的边数
在树上的某个结点有一个“恶魔之书”，这本书会让距离它d以内的节点都受到影响
已知有m个节点收到了影响，问最多有几个结点可能放着“恶魔之书”？

思路：
要判断某个点是不是放着书，就要判断这个点的周围d距离以内是否包含所有受影响的m节点
而如果某个节点距离最远的那个受影响节点的距离是L,如果L <= d，那么说明所有受影响的m节点都在d以内，就可判断这个点可能放着书

那么，我们只要能够求出每个节点距离最远的影响节点是多少，就可以O(n)的时间求出答案了。

所以可以用树形dp求解：

f(u, 0): 表示u为顶点的子树中，距u最远的“受影响节点”的距离
f(u, 1): 表示整个树删去u为顶点的子树,但是依旧保留u点为顶点，这个树中距离u最远的“受影响节点”的距离

所有的f(u, 0)可以一次dfs搞定, O(n)
f(u, 1)可以由顶节点一直推下去

f(v, 1) = max{f[brother1][0], f[brother2][0]..., f[brother3][0], f[father][1] | brother是v的兄弟节点，fa是v的父节点} + 1



*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef long long int64;
typedef pair<int,int> PII;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 1e5+10;

namespace Adj{
    int head[MAXN], size;

    struct Node{
        int v, next; 
    }E[MAXN*2+100];

    void initAdj() {
        size = 0; 
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }

}

using namespace Adj;

int n, m, d;
int f[MAXN][2];
bool vis[MAXN], p[MAXN];
int ans;

void dfs(int u) {
    vis[u] = true;
    int& ans = f[u][0] = (p[u] ? 0 : -1);
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (vis[v]) continue;
        dfs(v);
        if (f[v][0] != -1) 
            ans = max(ans, f[v][0] + 1);
    }
}

// 维护m1,m2保存第一大，第二大
inline void update(int w, int v, PII& m1, PII& m2) {
    if (w >= m1.first) {
        m2 = m1; m1.first = w; m1.second = v;
    } else if (w >= m2.first) {
        m2.first = w; m2.second = v;
    }
}

void dp(int u) {
    vis[u] = true;

    PII m1 = MP(-1, 0), m2=MP(-1, 0);

    int tmp = max(f[u][0], f[u][1]);
    if (tmp != -1 && tmp <= d) {
        ++ans; 
    }

    update(f[u][1], u, m1, m2);

    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (vis[v]) continue; 
        if (f[v][0] != -1) {
            update(f[v][0]+1, v, m1, m2);
        }
    }

    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (vis[v]) continue; 
        f[v][1] = -1;
        if (v!=m1.second && m1.first!=-1) {
            f[v][1] = max(f[v][1], m1.first+1);
        } else if (m2.first != -1) {
            f[v][1] = max(f[v][1], m2.first+1);
        }
        dp(v);
    }
}

int main(){

    while (~scanf("%d%d%d", &n, &m, &d)) {

        initAdj();
        memset(p, 0, sizeof(p));

        for (int i = 0; i < m; ++i) {
            int x;
            scanf("%d", &x);
            p[x] = true;
        } 

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        memset(vis, 0, sizeof(vis));
        dfs(1);

        f[1][1] = p[1]?0:-1;
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dp(1);

        printf("%d\n", ans);
    }

    return 0;
}
