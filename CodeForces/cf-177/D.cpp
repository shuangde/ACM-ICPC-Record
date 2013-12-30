// 树形dp
//shuangde
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
#define MP make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 80010;
int64 f[MAXN];
int64 ans;

namespace Adj {
    int head[MAXN], size;
    struct Edge{
        int v, next;
    } E[MAXN*4];
    void init() {memset(head,-1,sizeof(head)); size=0; }
    void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;
int n;

int dfs(int u, int fa) {
    f[u] = 1;
    cout<<u<<endl;
    int numSon = 0;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (v == fa) continue;
        ++numSon;
        f[u] += dfs(v, u);
    }
    if (numSon) {
        for (int e = head[u]; e != -1; e = E[e].next) {
            int v = E[e].v;
            if (v == fa) continue;
            int64 a = f[v], b = n - 1 - f[v] - numSon;
            if (a>0 && b>0) {
                ans += a*b;
            }
        }
        int64 a = n - f[u], b = f[u] - 1 - numSon;
        if (a>0 && b>0) {
            ans += a*b;
        }
    } 
    return f[u];
}

int main(){

    cin >> n;
    init();
    rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
    }
    ans = 0;
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}
