//哈希+计数
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

const int N = 1010;

int cnt[800*600+2];
map<int,int>Hash;

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    int idx = 0;
    int ans, maxx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            if (Hash[x] == 0)
                Hash[x] = ++idx;
            cnt[Hash[x]]++;
            if (cnt[Hash[x]] > maxx)
                maxx = cnt[Hash[x]], ans = x;
        }
    }
    printf("%d\n", ans);
    return 0;
}
