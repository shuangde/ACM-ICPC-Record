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
#define SQ(x) ((x)*(x))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

struct Bird {
    int64 x, y, r;
    int64 size;
}A[200];

struct Pile {
    int64 x, y;
    int64 num;
}B[500];
bool vis[500];
int n, m, nodeNum;
int64 willy, tot;



#define N 1010
#define M 1000010

struct MaxFlow {

    struct Edge {
        int u, v, next;
        int64 s;
    } edge[M];

    int head[N], size, path[M];

    void init() {
        size = 0;
        memset(head, -1, sizeof (head));
    }

    void addEdge(int u, int v, int64 s) {
        edge[size].u = u;  edge[size].v = v;  edge[size].s = s;
        edge[size].next = head[u];
        head[u] = size++;
        edge[size].u = v;  edge[size].v = u;  edge[size].s = 0;
        edge[size].next = head[v];
        head[v] = size++;
    }

    int64 Edmonds_Karp(int source, int sink) {
        int64 maxFlow = 0;
        queue<int> que;

        while (true) {
            memset(path, -1, sizeof(path)); // path[i]増广路径上指向顶点i的边在edge[]的位置
            que.push( source );
            while ( !que.empty() ) { // 寻找增广路径
                int u = que.front();
                que.pop();
                for (int e = head[u]; e!=-1 && path[sink]==-1; e = edge[e].next)
                    if (edge[e].s>0 && path[edge[e].v]==-1) {
                        path[edge[e].v] = e;
                        que.push(edge[e].v);
                    }
            }
            if (path[sink] == -1) break; // 找不到増广路
            int64 flow = INF;
            int e = path[sink];
            while (true) {
                flow = flow > edge[e].s ? edge[e].s : flow;
                if (edge[e].u == source) break;
                e = path[ edge[e].u ];
            }
            maxFlow += flow;
            e = path[sink];
            while (true) {
                edge[e].s -= flow;
                edge[e^1].s += flow;
                if (edge[e].u == source) break;
                e = path[ edge[e].u ];
            }
        }
        return maxFlow;
    }
} mf;

int main(){  
    int n, m;  
    while(~scanf("%d%d", &n, &m)){  
        int i, a, b, f;  
        mf.init();
        for(i = 0;i < n;i++){  
            scanf("%d%d%d", &a, &b, &f);  
            mf.addEdge(a, b, f);
        }  
        printf("%lld\n", mf.Edmonds_Karp(1, m));  
    }  
    return 0;  
}  
