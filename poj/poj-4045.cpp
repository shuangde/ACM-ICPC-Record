/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source: poj-4045 Power Station
 *   @type:  树形dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
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
const double PI  = acos(-1.0);
const int MAXN = 50010;

int64 f[MAXN][2];
int64 num[MAXN], ans;
bool vis[MAXN];
int n, I, R;
vector<int>adj[MAXN];

int64 dfs(int u){
    vis[u] = true;
    // u为根节点的子树，方向往下，u到所有子节点的总距离
    f[u][0] = 0;

    // u为根节点的子树，方向往下，共有多少个结点
    num[u] = 1;  

    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(vis[v]) continue;
        dfs(v);
        f[u][0] += f[v][0]; 
        num[u] += num[v];
    }
    f[u][0] += num[u]-1;
    return f[u][0];
}

void dp(int u){
    vis[u] = true;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(vis[v]) continue;
        // 计算出以v为根节点，方向往上, 总距离
        f[v][1] = (f[u][0]-f[v][0]-num[v]) + f[u][1] + n - num[v];
        dp(v);
    }
    ans = min(ans, f[u][0]+f[u][1]);
}


int main(){

    int nCase;
    scanf("%d", &nCase);
    
    while(nCase--){
        
        scanf("%d%d%d", &n, &I, &R);

        for(int i=0; i<=n; ++i) adj[i].clear();

        for(int i=0, u, v; i<n-1; ++i){
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(vis, 0, sizeof(vis));
        dfs(1);

        ans = (int64)1<<62;
        memset(vis, 0, sizeof(vis));
        f[1][1] = 0;
        dp(1);

        cout << ans*I*I*R<< endl;

        bool first = true;
        for(int i=1; i<=n; ++i){
            if(f[i][0]+f[i][1] == ans){
                if(first){first=false; printf("%d", i);}
                else printf(" %d", i);
            }
        }
        printf("\n\n");
    }

	return 0;
}
