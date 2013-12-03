
// 强连通分量
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
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 4010;
const int M = 200010 + N;


// 适用所有整形和浮点型,int、long long、float、double
template <class T>
inline void rd(T &ret) {
    char c;  int sgn;  T bit = 0.1;
    while (c != '-' && c != '.' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    if(c == ' ' || c == '\n'){ ret *= sgn; return ; }
    while (c = getchar(), c >= '0' && c <= '9') ret += (c - '0') * bit, bit /= 10;
    ret *= sgn;
}

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

int dfn[N],low[N],sta[N],belong[N],top,idx,bcnt;
bool inStack[N];
vector<int>scc[N];

void tarjan(int u) {
    dfn[u] = low[u] = idx++;
    sta[top++] = u; inStack[u] = true;
    ra(e, u) {
        int v = E[e].v;
        if (dfn[v] < 0) {
            tarjan(v);
            cmin(low[u], low[v]);
        } else if (inStack[v])
            cmin(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++bcnt; int v;
        scc[bcnt].clear();
        do {
            v = sta[--top];
            scc[bcnt].push_back(v);
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

int main() {

    int n;
    while (~scanf("%d", &n)) {
        initAdj();
        ff(i, n) {
            int k; //scanf("%d", &k);
            rd(k);
            rep(j, k) {
                int v; //'scanf("%d", &v);
                rd(v);
                addEdge(i, v+n);
            }
        }
        ff(i, n) {
            int x; //scanf("%d", &x); 
            rd(x);
            addEdge(x+n, i);
        }

        findScc(2*n);

        ff (i, n) {
            vector<int>vt;
            ra(e, i) {
                int v = E[e].v;
                if (belong[i] == belong[v])
                    vt.push_back(v-n);
            }

            sort(vt.begin(), vt.end());
            printf("%d", vt.size());
            rep(i, vt.size()) printf(" %d", vt[i]);
            puts("");
        }
    }
    return 0;
}
