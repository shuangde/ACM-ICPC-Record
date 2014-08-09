//求集合交集，并集
//也可用STL的set_intersection求交集
//set_union求并集
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 100010;

vector<int>vt[55];
double ans[55][55];

int main () {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        map<int,bool>vis;
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            if (!vis[x]) {
                vt[i].PB(x);
                vis[x] = true;
            }
        }
        sort(vt[i].begin(), vt[i].end());
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x = 0, y = 0;
            int com = 0, dif = 0;
            while (x<vt[i].size() && y<vt[j].size()) {
                if (vt[i][x] == vt[j][y])
                    ++x, ++y, ++com;
                else if (vt[i][x] < vt[j][y])
                    ++x, ++dif;
                else if (vt[i][x] > vt[j][y])
                    ++y, ++dif;
            }
            dif += vt[i].size()-x+vt[j].size()-y;
            ans[i][j] = com*1.0/(com+dif);
        } 
    }
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        printf("%.1f%%\n", ans[a-1][b-1]*100);
    }
    return 0;
}
