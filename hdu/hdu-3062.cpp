
// 2-sat
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
#define SQ ((x)*(x))
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int VN = 2010;
int n, m;
namespace Two_Sat {
    vector<int>adj[VN];

    int top, bcnt, idx;
    int sta[VN], DFN[VN], low[VN], belong[VN];
    bool inStack[VN];

    void tarjan(int u) {
        DFN[u] = low[u] = ++idx;
        sta[top++] = u;
        inStack[u] = true;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (DFN[v] < 0) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], DFN[v]);
            }
        }
        if (DFN[u] == low[u]) {
            ++bcnt;
            int v;
            do {
                v = sta[--top];
                inStack[v] = false;
                belong[v] = bcnt;
            } while (u != v);
        }
    }

    void scc() {
        top = bcnt = idx = 0;
        memset(DFN, -1, sizeof(DFN));
        memset(inStack, 0, sizeof(inStack));
        for (int i = 0; i < 2*n; ++i)
            if (DFN[i] < 0) tarjan(i);
    }

    bool check() {
        scc();
        for (int i = 0; i < n; ++i) 
            if (belong[i*2] == belong[(i*2)^1]) return false;
        return true;
    }
}
using namespace Two_Sat;

int main() {

    while (~scanf("%d%d", &n, &m)) {

        // init
        rep(i, 2*n) adj[i].clear();

        rep(i, m) {
            int a1, a2, c1, c2;
            scanf("%d%d%d%d", &a1,&a2,&c1,&c2);
            adj[(a1*2)^c1].push_back((a2*2+1)^c2);
            adj[(a2*2)^c2].push_back((a1*2+1)^c1);
        }
        if (check()) puts("YES");
        else puts("NO");
    }
    return 0;
}
