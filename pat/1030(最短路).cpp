// shuangde
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define rep(i,n) for (int i=0;i<n;++i)

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int N = 510;
int n, m, S, D;
int d[N], cost[N], pre[N];

struct Node {
    int v, w, c;
    Node(){}
    Node(int _v, int _w, int _c):v(_v),w(_w),c(_c){}
};
vector<Node>adj[N];

void dij(int src) {
    priority_queue<PII,vector<PII>,greater<PII> >Q;

    memset(d, INF, sizeof(d));
    memset(cost, INF, sizeof(cost));
    d[src]    = 0;
    cost[src] = 0;
    pre[src]  = -1;

    Q.push(make_pair(src, 0));
    
    while (!Q.empty()) {
        PII x = Q.top(); 
        Q.pop();
        int u = x.first;
        if (x.second != d[u]) continue;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v   = adj[u][i].v;
            int w   = adj[u][i].w;
            int c   = adj[u][i].c;
	        int tmp = d[u] + w;
	        if (tmp < d[v] || tmp==d[v]&&cost[u]+c<cost[v]) {
                d[v]    = tmp;
                cost[v] = cost[u] + c; 
                pre[v]  = u;
                Q.push(make_pair(v, d[v]));
	        }
        }
    }
}

void print_path(int u) {
	if (pre[u] != -1) {
        print_path(pre[u]);	
        putchar(' ');
	}
    printf("%d", u);
}

int main () {

    scanf("%d%d%d%d", &n, &m, &S, &D);
    rep(i, m) {
        int u, v, w, c;
        scanf("%d%d%d%d", &u,&v,&w,&c);	
	    adj[u].push_back(Node(v,w,c)); 
	    adj[v].push_back(Node(u,w,c));
    }

    dij(S);
    print_path(D);
    printf(" %d %d\n", d[D], cost[D]);
    
    return 0;
}
