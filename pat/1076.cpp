//BFS
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 1010;
vector<int>adj[N];
bool vis[N];
int n, L;


int bfs(int u) {
    queue<PII>Q;
    Q.push(MP(u, 0));
    vis[u] = true;
    int cnt = 0;
    while (!Q.empty()) {
        PII tmp = Q.front(); Q.pop();
        if (tmp.second >= L) continue;
        int u = tmp.first;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (vis[v]) continue;
            vis[v] = true;
            Q.push(MP(v, tmp.second+1));
            ++cnt;
        }
    }
    return cnt;
}

int main () {
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; ++i) {
        int m, u;
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &u);
            adj[u].push_back(i);
        }
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int u;
        scanf("%d", &u);
        memset(vis, 0, sizeof(vis));
        printf("%d\n", bfs(u));
    }
    return 0;
}
