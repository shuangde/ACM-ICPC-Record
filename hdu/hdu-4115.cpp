
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

const int N = 20010;
const int M = 20010;

// 适用所有整形和浮点型,int、long long、float、double
template <class T> inline void rd(T &ret) {
    char c;  int sgn;  T bit = 0.1;
    while (c != '-' && c != '.' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1; ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    if(c == ' ' || c == '\n'){ ret *= sgn; return ; }
    while (c = getchar(), c >= '0' && c <= '9') ret += (c - '0') * bit, bit /= 10;
    ret *= sgn;
}

namespace Adj {
    int size, head[N];
    struct Edge {
        int v, next; // 可根据题目需求变化，例如增加权值w
    }E[M*8];
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

int low[N], dfn[N], belong[N], sta[N], idx, top, bcnt;
bool instack[N];

void tarjan(int u) {
    low[u] = dfn[u] = idx++;
    sta[top++] = u; 
    instack[u] = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        if (dfn[v] < 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++bcnt; 
        int v;
        do {
            v = sta[--top];
            instack[v] = false;
            belong[v] = bcnt;
        } while ( u != v );
    }
}
void findScc(int n) {
    idx = top = bcnt = 0;
    memset(dfn, -1, sizeof(dfn));
    memset(instack, 0, sizeof(instack));
    for(int i = 0; i < n; ++i)
        if (dfn[i] < 0) tarjan(i);
}

bool check(int n) {
    findScc(2*n);
    for (int i = 0; i < n; ++i)
        if (belong[i*2] == belong[i*2+1]) return false;
    return true;
}

int arr[N];

int main() {

    int T,cas=1, n, m; rd(T);
    while (T--) {

        scanf("%d%d", &n, &m);
        init();
        rep(i, n) {
            rd(arr[i]); --arr[i];
        }

        rep(i, m) {
            int x, y, c; 
            scanf("%d%d%d", &x, &y, &c); 
            --x; --y;;
            int a[2], b[2];
            a[0] = arr[x]; a[1] = (arr[x]+1)%3;
            b[0] = arr[y]; b[1] = (arr[y]+1)%3;
            rep(i, 2) rep(j, 2) if ((a[i] != b[j]) != c) {
                addEdge(x*2+i, y*2+!j); addEdge(y*2+j, x*2+(!i));
            }
        }
        printf("Case #%d: ", cas++);
        printf("%s\n", check(n)?"yes":"no");
    }
    return 0;
}
