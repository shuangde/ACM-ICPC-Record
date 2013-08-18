/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-1484 Alice and Bob's Trip 
 *   @source: 树形dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*

题意：
给一棵n个结点的树，结点编号为0~n-1,顶点是0
每条边都有一个权值。
Alice和Bob初始位置在顶点，要往下一直走到叶子结点。
第一次是由Bob选择走向哪个子结点，第二次轮到Alice，依次轮流下去...
每走过一条边就会获得相应的权值，Bob希望所走的路径总权值越大越好，而Alice希望越小越好
每次他们都会选择最优解。
最终总权值要在范围[L,R]之内。
问最终Bob希望的最大权值是多少？


思路：

f(u, 0)表示第u点由Bob选时的最大值
f(u, 1)表示第u点由Alice选时的最大值
tot(u) 表示由顶点走到i点的权值之和

那么
f(u, 0) = max{ f(v, 1) + w(u,v) | v是u的儿子结点 && L <= f(v,1)+w(u)+tot(u) <= R}
f(u, 1) = min{ f(v, 0) + w(u,v) | v是u的儿子结点 && L <= f(v,0)+w(u)+tot(u) <= R}

最终答案为f(0, 0)

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>

typedef long long int64;

const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);
const int MAXN = 500010;

namespace Adj{
    int head[MAXN];
    int size;

    struct Node{
        int v, w, next;
    }E[MAXN];

    inline void initAdj() {
        size = 0;
        memset(head, -1, sizeof(head));
    }

    inline void addEdge(int u, int v, int w) {
        E[size].v = v;
        E[size].w = w;
        E[size].next = head[u];
        head[u] = size++;
    }
}

using namespace Adj;
using namespace std;

int n, l, r;
int f[MAXN][2];
int dist[MAXN];

inline bool check(int sum) {
    return sum >=l && sum <= r;
}

void dfs(int u, int tot) {
    f[u][0] = 0; 
    f[u][1] = head[u]==-1?0:INF;

    // 当当前路径之和大于r时，这条路已经不可行了
    if(tot > r) {
        f[u][0] = f[u][1] = INF;
        return ;
    }

    for(int e = head[u]; e!=-1; e = E[e].next) {
        int v = E[e].v;
        int w = E[e].w;

        dfs(v, tot+w);

        if(check(tot+w+f[v][1])) {
            f[u][0] = max(f[u][0], w+f[v][1]);    
        }

        if(check(tot+w+f[v][0])) {
            f[u][1] = min(f[u][1], w+f[v][0]);    
        }
    }
}

// 读入加速  
inline int nextInt() {  
    char c = getchar();  
    while (!isdigit(c)) c = getchar();  
    int x = 0;
    while (isdigit(c)) {  
        x = x*10+c-'0';  
        c = getchar();  
    }  
    return x;  
}

int main(){

    while (~scanf("%d%d%d", &n, &l, &r)) {

        initAdj();
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            u = nextInt();
            v = nextInt();
            w = nextInt();
            addEdge(u,v,w);
        }

        dfs(0, 0);

        if (!check(f[0][0])) {
            puts("Oh, my god!");
        } else {
            printf("%d\n", f[0][0]);
        }
    }
    return 0;
}
