
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
#define SQ ((x)*(x))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

map<string, int>hash;
int n;
bool g[210][210];
string str[210];

vector<int>adj[210];

int main() {

    int cas = 1;
    while (~scanf("%d", &n) && n) {
    
        memset(g, 0, sizeof(g));
        for (int i = 0; i < 210; ++i)
            adj[i].clear();
        hash.clear();

        vector<PII>E;
        int idx = 1;
        rep(i, n) {
            string a, b;
            cin >> a >> b;
            if (hash.find(a) == hash.end()) {
                hash[a] = idx++; 
                str[idx-1] = a;
            }
            if (hash.find(b) == hash.end()) {
                hash[b] = idx++; 
                str[idx-1] = b;
            }
            int u = hash[a], v = hash[b];
            g[u][v] = true;
            adj[v].push_back(u);
            E.push_back(MP(u, v));
        }
        for (int k = 1; k < idx; ++k)
            for (int i = 1; i < idx; ++i) {
                for (int j = 1; j < idx; ++j) {
                    g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
                } 
            } 
        vector<pair<string, string> >ans;
        for (int i = 0; i < E.size(); ++i) {
            int u = E[i].first, v = E[i].second;
            for (int j = 0; j < adj[v].size(); ++j) if (adj[v][j] != u){
                if (g[u][adj[v][j]]) {
                    ans.push_back(MP(str[u], str[v]));
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        printf("Case %d: %d", cas++, ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            cout << " " << ans[i].first << "," << ans[i].second;
        }
        puts("");
    }
    return 0;
}
