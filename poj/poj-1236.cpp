
// 强连通分量缩点后，求入度、出度为0的数量
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
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for (int e = head[u]; e != -1; e = E[e].next)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 110;
const int M = N*N;

namespace Adj {

    int size, head[N];

    struct Edge {
        int v, next; // 可根据题目需求变化，例如增加权值w
    }E[M*2];

    void initAdj () {
        size = 0;
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v) {
        E[size].v = v;
        E[size].next = head[u];
        head[u] = size++;
    }
} using namespace Adj; 

int low[N], dfn[N], sta[N], belong[N], top, idx, bcnt;
bool inStack[N];

void tarjan(int u) {
    dfn[u] = low[u] = idx++;
    sta[top++] = u; inStack[u] = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (dfn[v] < 0) {
            tarjan(v);
            cmin(low[u], low[v]);
        } else if (inStack[v])
            cmin(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++bcnt; int v;
        do {
            v = sta[--top]; 
            inStack[v] = false;
            belong[v] = bcnt;
        } while ( u != v);
    }
}
void findScc(int n) {
    idx = top = bcnt = 0;
    CLR(inStack, 0);
    CLR(dfn, -1);
    ff(i, n) if (dfn[i] < 0) tarjan(i);
}

bool out[N], in[N];

int main() {

    int n;
    while (~scanf("%d", &n)) {
        initAdj();
        ff(u, n) {
            int v;
            while (~scanf("%d", &v) && v) {
                addEdge(u, v);
            }
        }

        findScc(n);

        ff(i, bcnt) in[i] = out[i] = true;
        ff(u, n) {
            ra(e, u) {
                int v = E[e].v;
                if (belong[u] != belong[v]) {
                    out[belong[u]] = in[belong[v]] = false; 
                }
            } 
        }

        int cnt1 = 0, cnt2 = 0;
        ff(i, bcnt) {
            if (out[i]) ++cnt1;
            if (in[i]) ++cnt2;
        }
        int ans = max(cnt1, cnt2);
        if (bcnt==1) ans = 0;
        printf("%d\n%d\n", cnt2, ans);
    }
    return 0;
}
