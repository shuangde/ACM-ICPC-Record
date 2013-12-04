
// 2-SAT
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define PB push_back
#define SQ ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 1010;
const int M = 1000010;

namespace Adj {
    int size, head[N];
    struct Edge {
        int v, next; 
    }E[M*2];
    void init ( ) {
        size = 0;
        memset(head, -1, sizeof(head));
    }
    void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
} using namespace Adj; 

int dfn[N], low[N], sta[N], belong[N], idx, top, bcnt;
bool instack[N];

void tarjan(int u) {
    dfn[u] = low[u] = idx++;
    sta[top++] = u; instack[u] = true;
    ra(e, u) {
        int v = E[e].v;
        if (dfn[v] == -1) tarjan(v), cmin(low[u], low[v]);
        else if (instack[v]) cmin(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++bcnt; int v;
        do { v=sta[--top]; instack[v]=false; belong[v]=bcnt; } while ( u!= v);
    }
}
void findScc(int n) {
    idx = bcnt = top = 0;
    clr(instack, 0); 
    clr(dfn, -1);
    rep(i, n) if (dfn[i] == -1) tarjan(i);
}

bool check(int n) {
    findScc(2*n);
    rep(i, n) if (belong[2*i]==belong[2*i+1]) return false;
    return true;
}

int cal(int a, int b, char op) {
    if (op == 'A') {
        return a&b;
    } else if (op == 'O') {
        return a|b;
    } else {
        return a^b;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init();
    rep(i, m) {
        int a, b, c; char op[5];
        scanf("%d%d%d%s", &a, &b, &c, op);
        rep(i, 2) rep(j, 2) if (cal(i,j,op[0]) != c) {
            addEdge(2*a+!i, 2*b+j); addEdge(2*b+!j, 2*a+i);
        }
    }
    puts(check(n) ? "YES" : "NO");
    return 0;
}
