//最短路
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 1100;

vector<PII>adj[N];
int d[N];

void dij(int s) {
    memset(d, INF, sizeof(d));
    d[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII> >Q; 
    Q.push(MP(0, s));
    while (!Q.empty()) {
        PII x = Q.top();
        Q.pop();
        int u = x.second;
        if (d[u] != x.first) continue;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first; 
            int w = adj[u][i].second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                Q.push(MP(d[v], v)); 
            }
        }
    }
}

int main () {
    int n, m, k, ds;
    scanf("%d%d%d%d", &n,&m,&k,&ds);
    for (int i = 0; i < k; ++i) {
        char a[10], b[10];
        int d, x, y;
        scanf("%s%s%d",a,b,&d);
        sscanf(a+(a[0]=='G'),"%d", &x);
        sscanf(b+(b[0]=='G'),"%d", &y);
        x--, y--;
        if (a[0] == 'G') x += n;
        if (b[0] == 'G') y += n;
        adj[x].PB(MP(y, d));
        adj[y].PB(MP(x, d));
    }
    int minDist = -1, station;
    double avg;
    for (int i = n; i < n+m; ++i) {
        dij(i);
        //for (int j = 0; j < n; ++j) printf("%d ", d[j]); puts("");
        int minx = INF, sum = 0;
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (d[j] > ds) {
                flag = false;
                break;
            }
            sum += d[j];
            if (d[j] < minx)
                minx = d[j];
        }
        if (!flag) continue;
        if (minx > minDist || minx==minDist&&(sum*1.0/n<avg)) {
            minDist = minx;
            station = i;
            avg = sum * 1.0 / n;
        }
    }
    if (minDist == -1) {
        puts("No Solution");  
        return 0;
    }
    printf("G%d\n", station-n+1);
    printf("%.1f %.1f\n", minDist*1.0, avg);
    return 0;
}
