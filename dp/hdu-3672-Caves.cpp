/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：hdu-3672-Caves
 *   @type: 树形dp背包
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 510;

namespace Adj {
    int size, head[MAXN];

    struct Node{
        int v, next, w; 
    }E[MAXN+10];

    void initAdj() {
        size = 0;
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v, int w) {
        E[size].v = v;
        E[size].w = w;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;
//////////////////////////////////

int n;
bool deg[MAXN];
int f[MAXN][MAXN];

void dfs(int u, int num) {

    f[u][0] = f[u][1] = 0;

    for (int i = 2; i <= num; ++i) {
        for ( int e = head[u]; e != -1; e = E[e].next) {
            int v = E[e].v;
            int w = E[e].w;
            dfs(v, i-1);
            f[u][i] = min(f[u][i], f[v][i-1] + w);
        }
    }
}

int main(){

    int cas = 1;
    while (~scanf("%d", &n) && n) {
        
        printf("Case %d:\n", cas++);

        initAdj();
        memset(deg, 0, sizeof(deg));

        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &v, &u, &w);
            deg[v] = true;
            addEdge(u, v, w);
        }

        memset(f, INF, sizeof(f));

        int root;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                root = i;
                dfs(i, n); 
                break;
            } 
        }

        for (int i = 1; i <=n; ++i) {
            printf("%d ", f[root][i]); 
        }
        puts("");
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int x; 
            scanf("%d", &x);
            int ans = 1;
            for (int i = 1; i <=n; ++i) {
                if(f[root][i] <= x) 
                    ans = i;
            }
            continue;
            printf("%d\n", ans + 1);
        }

    }
	return 0;
}
