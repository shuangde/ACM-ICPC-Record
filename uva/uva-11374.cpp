#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std; 
const int INF = 0x3f3f3f3f;

namespace Dij{

    const int N = 510;   // 最大点数
    const int M = N * N; // 最大边数
    typedef pair<int, int> PII;

    struct Edge {
        int v, w, next;
    }edge[M];

    int vn, size, head[N];

    void init(int numNode) {
        vn = numNode; size = 0; 
        memset(head, -1, sizeof(head));
    }

    void addEdge(int u, int v, int w) {
        edge[size] = (Edge){v, w, head[u]}; 
        head[u] = size++;
    }

    void dij(int src, int* d, int* pre) {
        for (int i = 0; i <= vn; ++i) d[i] = INF, pre[i] = -1;
        d[src] = 0;
        priority_queue<PII, vector<PII>, greater<PII> >Q;
        Q.push( make_pair(0, src) );
        while (!Q.empty()) {
            PII x = Q.top(); 
            Q.pop();
            int u = x.second;
            if (d[u] != x.first) continue;
            for (int e = head[u]; e != -1; e = edge[e].next) {
                int v = edge[e].v, w = edge[e].w;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    pre[v] = u;
                    Q.push( make_pair(d[v], v) );
                }
            }
        }
    }
}
using namespace Dij;

int n, S, E, m, k;
int d[510], g[510], pre1[510], pre2[510];


void out(int v, int* pre, bool& first) {
    if (pre[v] != -1)  out(pre[v], pre, first);
    if (first) first = false; 
    else printf(" ");
    printf("%d", v);
}

int main(){
    
    bool firstLine = true;
    while(~scanf("%d%d%d%d",&n,&S,&E,&m)){

        if (firstLine) firstLine = false;
        else puts("");

        init(n);

        rep(i, m) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w); addEdge(v, u, w);
        }

        dij(S, d, pre1);
        dij(E, g, pre2);

        int ans = d[E], from = -1, to;
        
        scanf("%d", &k);
        rep(i, k) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            int tmp = d[u] + w + g[v];
            if (tmp < ans) {
                ans = tmp;
                from = u, to = v;
            }
            tmp  = d[v] + w + g[u];
            if (tmp < ans) {
                ans = tmp;
                from = v, to = u;
            }
       }
        bool first = true;
        if (from != -1) {
            out(from, pre1,first); 
            int u = to;
            while (u != -1) {
                printf(" %d", u); 
                u = pre2[u]; 
            }
            puts("");
            printf("%d\n", from);
        } else {
            out(E, pre1, first);
            puts("\nTicket Not Used");
        }
        printf("%d\n", ans);
    }
    return 0;
}
