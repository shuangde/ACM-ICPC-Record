/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：HDU-4679 Terrorist’s destroy
 *   @type: 树形dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意:
   给一棵树，每条边有个权值，要删掉一条边，删掉以后会变成两颗子树，设两个子树的直径分别为d1, d2，删掉的这条边权值为w
   问删掉哪一条边，使得w*max(d1, d2)的值最小?


思路:
   典型的树形dp, 但比赛时的代码写得非常搓，200+行，还好1A了

   f(u, 0)：以u点为顶点的子树的直径
   f(u, 1)：以u的父节点为顶点减去u的子树部分的子树的直径

   先用树形dp求出上面的数组

   然后答案等于 min{ w(u,v)*max{f(v,0), f(v,1)} | v为u的子节点 }
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;

typedef pair<int,int> PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;

namespace Adj{
    int head[MAXN], size;

    struct Node{
        int v, w, id, next; 
    }E[MAXN*2+100];

    void initAdj() {
        size = 0; 
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v, int w, int _id) {
        E[size].id = _id;
        E[size].v = v;
        E[size].w = w;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;

int n;
bool vis[MAXN];
int ans, ans_id;

// f[u][0]，每个子树的最大直径
// f[u][1], 每个节点朝上的最大直径
int f[MAXN][2]; 
int dept[MAXN][2]; //每个结点的最大和次大 
int up[MAXN][2];   // 每个结点往上的最大和次大

// m1,m2,m3分别保存第一大，第二大，第三大
inline void insert(int w, int v, PII& m1, PII& m2, PII& m3) {
    if(w >= m1.first) {
        m3 = m2; m2 = m1; m1.first = w; m1.second = v;
    } else if(w >= m2.first) {
        m3 = m2; m2.first = w; m2.second = v;
    } else if(w >= m3.first) {
        m3.first = w; m3.second = v;
    }
}

// m1,m2,m3分别保存第一大，第二大
inline void insert(int w, int v, PII& m1, PII& m2) {
    if(w >= m1.first) {
        m2 = m1; m1.first = w; m1.second = v;
    } else if(w >= m2.first) {
        m2.first = w; m2.second = v;
    }
}

inline int add(int a, int b) {
    if(a&&b) return 2;
    return 1;
}
// 第一次dfs,求出每个子结点最大和次大的距离,和直径
void dfs(int u) {
    vis[u] = true;

    dept[u][0] = dept[u][1] = 0;

    int& ans = f[u][0] = 0;
    int maxx = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        int w = E[e].w;
        if (vis[v]) continue;

        dfs(v);

        if (dept[v][0] + 1 >= dept[u][0]) {
            dept[u][1] = dept[u][0];
            dept[u][0] = dept[v][0] + 1; 
        } else if (dept[v][0] + 1 > dept[u][1]) {
            dept[u][1] = dept[v][0] + 1;
        }
        maxx = max(maxx, f[v][0]);
    }
    ans = max(ans, max(dept[u][0]+dept[u][1], maxx));
}

void dp(int u, int fa, int w, int id) {
    vis[u] = true;
    PII m1, m2, m3;
    PII n1, n2;

    if(fa!=-1) {
        int tmp = w * max(f[u][1], f[u][0]);
        if(tmp < ans) {
            ans = tmp; ans_id = id;
        } else if(tmp == ans) {
            ans_id = min(ans_id, id); 
        }
    }

    for(int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if(vis[v]) continue;
        f[v][1] = 0;
        insert(dept[v][0]+1, v, m1, m2, m3);
        insert(f[v][0], v, n1, n2);
    }

    if(fa!=-1) {
        insert(up[u][0]+1, u, m1, m2, m3);
        insert(f[u][1], u, n1, n2);
    }

    for(int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v, w = E[e].w, _id = E[e].id;
        if(vis[v]) continue;

        if(v!=m1.second && v!=m2.second) {
            up[v][0] = m1.first; up[v][1] = m2.first;
            f[v][1] =  max(f[v][1], m1.first+m2.first+add(m1.first, m2.first));       

        } else if(v==m1.second) {
            up[v][0] = m2.first; up[v][1] = m3.first; 
            f[v][1] =  max(f[v][1], m2.first+m3.first+add(m2.first, m3.first));       

        } else if(v==m2.second) {
            up[v][0] = m1.first; up[v][1] = m3.first; 
            f[v][1] =  max(f[v][1], m1.first+m3.first + add(m1.first, m3.first));       
        }

        if(v==n1.second) f[v][1] = max(f[v][1], n2.first); 
        else f[v][1] = max(f[v][1], n1.first); 

        f[v][1] = max(f[v][1], up[v][0]+up[v][1]); 

        dp(v, u, w, _id);
    }
}

int main(){

    int nCase, cas=1;
    scanf("%d", &nCase);

    while(nCase--) {

        scanf("%d", &n);
        initAdj();
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w, i+1);
            addEdge(v, u, w, i+1);
        }

        memset(vis, 0, sizeof(vis));
        dfs(1);

        up[1][0] = up[1][1] = 0;
        memset(vis, 0, sizeof(vis));

        ans = INF;
        memset(vis, 0, sizeof(vis));
        dp(1, -1, 0, 0);

        printf("Case #%d: %d\n", cas++, ans_id);
    }


    return 0;
}
