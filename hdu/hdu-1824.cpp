
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
int n, m;

const int VN = 6010;
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
        } else if (inStack[v]){
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
        } while ( u != v );
    }
}

void scc() {
    top = bcnt = idx = 0;
    memset(DFN, -1, sizeof(DFN));
    memset(inStack, 0, sizeof(inStack));
    for (int i = 0; i < 2 * n; ++i)
        if (DFN[i] < 0) tarjan(i);
}

bool check() {
    scc();
    for (int i = 0; i < n; ++i) 
        if (belong[2*i] == belong[2*i+1]) return false;
    return true;
}

int main() {

    while (~scanf("%d%d", &n, &m)) {

        rep(i, 6*n) adj[i].clear();
        // 0留下，1回家
        rep(i, n) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            adj[2*a+1].push_back(2*b);
            adj[2*a+1].push_back(2*c);

            adj[2*b+1].push_back(2*a);
            adj[2*c+1].push_back(2*a);
        }

        rep(i, m) {
            int a, b; scanf("%d%d", &a, &b);
            adj[2*a].push_back(2*b+1);
            adj[2*b].push_back(2*a+1);
        }

        if (check()) puts("yes");
        else puts("no");

    }
    return 0;
}
