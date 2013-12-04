
// 求割点
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
#define PB push_back
#define SQ ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 110;
const int M = N*N;

template <class T>
inline bool rd(T &ret) {
    char c;  ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9') ret = ret * 10 + (c - '0'), c = getchar();
    if (c == '\n') return false;
    else return true;
}

namespace Adj {
    int size, head[N];
    struct Edge {
        int v, next; // 可根据题目需求变化，例如增加权值w
    }E[M*2];
    void init () {
        size = 0;
        memset(head, -1, sizeof(head));
    }
    void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
} using namespace Adj; 

int dfn[N], low[N], idx, cnt;
bool cut[N];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = idx++;
    int son = 0;
    ra(e, u) {
        int v = E[e].v;
        if (dfn[v] < 0) {
            ++son;
            tarjan(v, u);
            cmin(low[u], low[v]);
            if (fa<0&&son>1 || fa>0&&dfn[u]<=low[v]) { 
                if (!cut[u]) cut[u] = true, ++cnt;
            }

        } else if (v != fa)
            cmin(low[u], dfn[v]);
    }
}

int findCut(int n) {
    idx = cnt = 0;
    clr(dfn, -1);
    clr(cut, 0);
    ff(i, n) if (dfn[i] < 0) tarjan(i, -1);
    return cnt;
}

int main() {

    int n;
    while (~scanf("%d", &n) && n) {
        init();
        while (1) {
            int u; rd(u);
            if (u == 0) break;
            while (1) {
                int v; bool res = rd(v);
                addEdge(u, v);
                addEdge(v, u);
                if (!res) break;
            }
        }
        printf("%d\n", findCut(n));
    }
    return 0;
}
