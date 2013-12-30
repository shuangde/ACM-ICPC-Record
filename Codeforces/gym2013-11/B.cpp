
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

int n1, n2, m;
int hash1[1010], hash2[1010];

void insert(int x) {
    int cur = 0, *hash = hash1, n = n1;
    while (1) {
        int loc = x % n;
        if (hash[loc] == -1) {
            hash[loc] = x; 
            return ;
        } else {
            swap(hash[loc], x);
            if (cur == 0) {
                hash = hash2;
                n = n2;
                cur = 1;
            } else {
                hash = hash1;
                n = n1;
                cur = 0;
            } 
        }
    }
}

int main() {

    int cas = 1;
    while (~scanf("%d%d%d", &n1, &n2, &m) && n1+n2+m) {
        printf("Case %d:\n", cas++);
        memset(hash1, -1, sizeof(hash1));
        memset(hash2, -1, sizeof(hash2));
        rep(i, m) {
            int x; scanf("%d", &x);
            insert(x);
        }

        vector<PII>vt;
        rep(i, n1) {
            if (hash1[i] != -1) vt.push_back(MP(i, hash1[i]));
        }
        if (vt.size()) {
            puts("Table 1");
            for (int i = 0; i < vt.size(); ++i)
                printf("%d:%d\n", vt[i].first, vt[i].second);
        }

        vt.clear();
        rep(i, n2) {
            if (hash2[i] != -1)  vt.push_back(MP(i, hash2[i]));
        }
        if (vt.size()) {
            puts("Table 2");
            for (int i = 0; i < vt.size(); ++i)
                printf("%d:%d\n", vt[i].first, vt[i].second);
        }
    }
    return 0;
}
