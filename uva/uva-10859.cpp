/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-10859 Placing Lampposts
 *   @type:  树形dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*

f[u][1]表示u点放灯时的整个子树最小值
f[u][0]表示u点不放灯时的整个子树最小值

如果u放，那么u个子结点可以选择放，也可以不放，选择其中较小的值。如果选的是不照，就要增加一条只有一个灯照的边

如果u不放，那么其子结点就必须选择要放，而且每条边都只有一个灯照


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

const int MAXN = 1010;
vector<int>adj[MAXN];
bool vis[MAXN];
int n, m;
int f[MAXN][2];
const int M = 2000;

void dfs(int u) {
    vis[u] = true;
    f[u][0] = 0;
    f[u][1] = M;
    for(int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i]; 
        if(vis[v]) continue;
        dfs(v);
        f[u][0] += f[v][1] + 1;
        if (f[v][0] < f[v][1]) {
            f[u][1] += f[v][0] + 1;
        } else {
            f[u][1] += f[v][1];
        } 
    }
}

int main(){

    int nCase;

    scanf("%d", &nCase);

    while(nCase--) {

        scanf("%d%d", &n, &m);

        for(int i = 0; i < n; ++i) 
            adj[i].clear();

        for(int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < n; ++i) if(!vis[i]){
            dfs(i);
            ans += min(f[i][0], f[i][1]);
        }
        printf("%d %d %d\n", ans/M, m-(ans%M), ans%M);
    }

	return 0;
}
