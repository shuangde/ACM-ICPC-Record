//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 100010;
vector<int>adj[N];
int cnt[N];
int n;
double p, r;

double dfs(int u, double p) {
    if (adj[u].size() == 0) {
        return p * cnt[u];
    }
    double ret = 0;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        ret += dfs(v, p*(1+r/100));
    }
    return ret;
}

int main () {
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i = 0; i < n; ++i) {
        int m, v;
        scanf("%d", &m);
        if (m == 0) {
            scanf("%d", &cnt[i]);
            continue;
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v);
            adj[i].push_back(v);
        }
    }
    printf("%.1f\n", dfs(0, p));
    return 0;
}
