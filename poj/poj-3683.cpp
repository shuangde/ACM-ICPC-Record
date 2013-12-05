
// 2-SAT, 输出方案
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
#define asc(a,b) if(a>b)swap(a,b)
#define des(a,b) if(a<b)swap(a,b)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;

#define WHITE -1
#define RED 1
#define BLUE 0
typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 2010;
const int M = N*N;

namespace Adj {
    int size, head[N];
    struct Edge{int v,next;}E[M];
    void init() {size=0; clr(head,-1);}
    void addEdge(int u, int v){E[size].v=v;E[size].next=head[u];head[u]=size++;}
}using namespace Adj;


namespace Two_SAT {
    int low[N],dfn[N],sta[N],belong[N],idx,top,bcnt;
    bool instack[N];

    void tarjan(int u) {
        low[u] = dfn[u] = idx++;
        sta[top++] = u; instack[u] = true;
        ra(e, u) {
            int v = E[e].v;
            if (dfn[v] < 0) tarjan(v), cmin(low[u], low[v]);
            else if (instack[v]) cmin(low[u], dfn[v]);
        }
        if (low[u]==dfn[u]) {
            ++bcnt;int v;
            do {v=sta[--top]; instack[v]=false; belong[v]=bcnt;} while (u!=v);
        }
    }
    bool check(int n) {
        idx = top = bcnt = 0;
        clr(dfn, -1); clr(instack, 0);
        rep(i, 2*n) if (dfn[i] < 0) tarjan(i);
        rep(i, n) if (belong[2*i]==belong[2*i+1]) return false;
        return true;
    }
} using namespace Two_SAT;


bool isCross(int a1, int a2, int b1, int b2) {
    if (b1>=a2 || a1 >= b2) return false;
    return true;
}


int t[N][2], len[N];

void print(int i, int color) {
    if (color == RED) {
        int tt = t[i][0];
        printf("%02d:%02d %02d:%02d\n", (tt-len[i])/60, (tt-len[i])%60, tt/60, tt%60);
    } else {
        int tt = t[i][1];
        printf("%02d:%02d %02d:%02d\n", (tt-len[i])/60, (tt-len[i])%60, tt/60, tt%60);
    }
}

#define WHITE -1
#define RED 1
#define BLUE 0
vector<int>dag[N]; // 缩点后的图
int opp[N], color[N], indeg[N];
// RED 表示选择2*i, BLUE表示选择2*i+1， WHITE还未选择
void toposort(int n) {
    for (int i = 1; i <= bcnt; ++i) 
        dag[i].clear(), indeg[i] = 0;

    for (int i = 0; i < n; ++i) {
        opp[belong[2*i]] = belong[2*i+1];
        opp[belong[2*i+1]] = belong[2*i];
    }

    // 缩点重建反向DAG
    for (int i = 0; i < 2 * n; ++i) 
        for (int e = head[i]; e != -1; e = E[e].next) {
            int u = belong[i], v = belong[E[e].v];
            if (u != v) { indeg[u]++; dag[v].push_back(u); }
        } 

    queue<int>que;
    memset(color, WHITE, sizeof(color));
    for (int i = 1; i <= bcnt; ++i) 
        if (indeg[i] == 0) que.push(i);

    while (!que.empty()) {
        int u = que.front(); que.pop();
        if (color[u] != WHITE) continue;
        color[u] = RED; color[opp[u]] = BLUE;
        for (int i = 0; i < dag[u].size(); ++i) {
            int v = dag[u][i];
            if (--indeg[v] == 0) que.push(v);
        }
    }
    // 输出
    for (int i = 0; i < n; ++i) {
        if (color[belong[i*2]] == RED) { //注意是i*2
            print(i, RED);
        } else {
            print(i, BLUE);
        } 
    }
} 

int main() {

    int n;
    while (~scanf("%d", &n)) {
        init();
        rep(i, n) {
            int h, m;
            scanf("%d:%d", &h, &m); t[i][0] = h*60+m;
            scanf("%d:%d", &h, &m); t[i][1] = h*60+m;
            scanf("%d", &len[i]);
            t[i][0] += len[i];
        }
        rep(i, n) for (int j=i+1; j<n; ++j) {
            rep(a, 2) rep(b, 2) if (isCross(t[i][a]-len[i], t[i][a], t[j][b]-len[j], t[j][b])){
                addEdge(i*2+a, j*2+!b);
                addEdge(j*2+b, i*2+!a);
            }
        }
        if (check(n)) {
            puts("YES");
            toposort(n);
        } else puts("NO"); 
    }
    return 0;
}
