//dfs+排序
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;

const int N = 110;
int n, m, s;
int w[N], tmp[N];
int val[1010];
int weight[1010];
vector<string>ans;

vector<int>adj[N];

void dfs(int u,int sum,string path) {
    sum += w[u];
    path += val[w[u]];
    if (sum > s) return ;
    if (sum == s) {
        if (adj[u].size() == 0)
            ans.PB(path);
        return ;
    }
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i]; 
        dfs(v, sum, path);
    }
}

int main () {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
        tmp[i] = w[i];
    }
    sort(tmp, tmp+n);
    
    int idx = 0;
    memset(val, -1, sizeof(val));
    for (int i = 0; i < n; ++i) {
        if (val[tmp[i]] == -1) {
            val[tmp[i]] = idx;
            weight[idx++] = tmp[i];
        }
    } 
    for (int i = 0; i < m; ++i) {
        int u, num, v;
        scanf("%d%d", &u, &num);
        for (int j = 0; j < num; ++j) {
            scanf("%d", &v);
            adj[u].PB(v);
        }
    }
    dfs(0, 0, "");
    sort(ans.begin(), ans.end(), greater<string>());
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) 
            printf("%s%d",j?" ":"",weight[ans[i][j]]);
        puts("");
    }
    return 0;
}
