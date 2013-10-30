
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

int cover[30];
int n, ans, maxSta;

int solve(int s) {
    int cnt = 0;
    int cc = 0;
    for (int i=0; i < n; ++i) {
        if ((s>>i)&1) {
            ++cnt;
            cc |= cover[i];
        }
    }
    if (cc == maxSta) {
        ans = min(ans, cnt); 
    }
}

int main(){

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &n);
        memset(cover, 0, sizeof(cover));
        for (int i = 0; i < n; ++i) {
            int k; scanf("%d", &k);
            cover[i] |= (1<<i);
            for (int j = 0; j < k; ++j) {
                int v; 
                scanf("%d", &v);
                v--;
                cover[i] |= (1<<v);
            }

        }
        maxSta = (1<<n)-1;
        ans = INF;
        for (int s = 1; s <= maxSta; ++s) {
            solve(s);
        }
        printf("%d\n", ans);
    }
    return 0;
}
