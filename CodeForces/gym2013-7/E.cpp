
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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int N=3000;
int n, w[110];
bool g[110][110];


struct Edge {
    int u, v, w;
    bool operator < (const Edge& rhs) const {
        return w > rhs.w; 
    }
}E[100000];

int f[110];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){

    int T;
    scanf("%d", &T);
    while (T--) {
        int u, cost, num;
        scanf("%d", &n);
        memset(g, 0, sizeof(g));
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &u, &cost, &num);
            w[u] = cost;
            for (int j = 0; j < num; ++j) {
                int v; 
                scanf("%d", &v);
                g[u][v] = g[v][u] = true;
            }
        }
        int idx = 0, sum = 0;
        for (int u = 0; u < n; ++u)
            for (int v = u + 1; v < n; ++v) if (g[u][v]) {
                E[idx].u = u, E[idx].v = v, E[idx++].w = w[u] + w[v];
                sum += w[u] + w[v];
            }

        for (int i = 0; i < n; ++i)
            f[i] = i;

        sort(E, E+idx);
        int maxMst = 0;
        for (int i = 0; i < idx; ++i) {
            int a = find(E[i].u), b = find(E[i].v);
            if (a != b) {
                f[a] = b;
                maxMst += E[i].w;
            }
        }
        printf("%d\n", sum - maxMst);
    }
    return 0;
}
