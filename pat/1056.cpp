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
typedef long long int64;

const int N = 1010;
int n, k;
PII w[N*2];
int order[N];
int Rank[N];
vector<PII>vt[N];

int main () {
    int n, g;
    scanf("%d%d", &n, &g);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i].first);
        w[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &order[i]);
        vt[0].PB(w[order[i]]);
    }
    int idx = 0;
    while (vt[idx].size() != 1) {
        int i = 0;
        while (i < vt[idx].size()) {
            int k = i;
            for (int j = 0; j < g && i < vt[idx].size(); ++j) {
                if (vt[idx][i].first > vt[idx][k].first)
                    k = i;
                ++i;
            }
            vt[idx+1].PB(vt[idx][k]);
        }
        ++idx;
    }
    int r = 1;
    for (int i = idx; i >= 0; --i) {
        int cnt = 0;
        for (int j = 0; j < vt[i].size(); ++j) {
            if (Rank[vt[i][j].second]) continue;
            ++cnt;
            Rank[vt[i][j].second] = r;
        }
        r += cnt;
    }
    for (int i = 0; i < n; ++i)
        printf("%s%d",i?" ":"", Rank[i]);
    return 0;
}
