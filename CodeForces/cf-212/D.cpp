
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
#define MP(a,b) (Node){a,b} 
#define SQ ((x)*(x))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int64 INF = 1e9;
const double eps = 1e-8;

struct Edge{
    int u, v;
    int64 w;
}edge[100010];

struct Node {
    int64 first;
    int second;
    bool operator < (const Node& rhs) const {
        return first > rhs.first; 
    }
};

int n, m, p, q;
int f[100010];
int64 weight[100010];

void init() {
    memset(weight, 0, sizeof(weight));
    for (int i = 0; i <= n; ++i) {
        f[i] = i;
    }
}
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void Union(int x, int y, int64 w) {
    int a = find(x), b = find(y);
    if (a == b) {
        weight[a] += w;
        return;
    }
    f[a] = b;
    weight[b] = weight[a] + weight[b] + w;
}

int main() {

    scanf("%d%d%d%d", &n,&m,&p,&q);
    int u = -1, v;
    init();
    rep(i, m) {
        int64 w;
        cin >> u >> v >> w;
        --u, --v;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
        Union(u, v, w);

    }
    priority_queue<Node>que;
    vector<PII>ans;

    rep(i, n) if (find(i) == i){
        que.push(MP(weight[i], i));
    }

    int cnt = 0;
    while (que.size() > q) {
        ++cnt;
        Node a = que.top(); que.pop();
        Node b = que.top(); que.pop();

        int64 tmp = weight[a.second] + weight[b.second] + 1; 
        Union(b.second, a.second, min(INF, tmp));
        que.push(MP(weight[a.second], a.second));
        ans.push_back(make_pair(a.second, b.second));
        u = a.second, v = b.second;
    }

    if (que.size() != q || cnt > p) {
        puts("NO");
    } else {
        if (cnt < p) {
            bool ok = false;
            if (u!=-1) {
                puts("YES");
                for (int i = 0; i < ans.size(); ++i)
                    printf("%d %d\n", ans[i].first+1, ans[i].second+1);
                for (int i = 0; i < p-cnt; ++i)
                    printf("%d %d\n", u+1, v+1);
            } else {
                puts("NO");
            }
        } else { 
            puts("YES");
            for (int i = 0; i < ans.size(); ++i)
                printf("%d %d\n", ans[i].first+1, ans[i].second+1);
        }
    } 
    return 0;
}
