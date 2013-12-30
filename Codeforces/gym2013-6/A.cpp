
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

const int MAXN = 1510;
int f[MAXN];
int c[6];

int main(){

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        for (int i = 0; i < 6; ++i)
            scanf("%d", &c[i]);

        memset(f, 0x3f, sizeof(f));
        f[0] = 0;

        for (int i = 1; i < MAXN; ++i) {
            for (int j = 0; j < 6 && c[j]<=i; ++j) {
                f[i] = min(f[i], f[i-c[j]]+1);
            }
        }

        int maxx = 0;
        double sum = 0;
        for (int i = 1; i <= 100; ++i) {
            int tmp = 0x3f3f3f3f;
            for (int j = i; j < MAXN; ++j) {
                tmp = min(tmp, f[j] + f[j-i]);
            }
            sum += tmp;
            maxx = max(maxx, tmp);
        }
        printf("%.2f %d\n", sum/100, maxx);
    }
    return 0;
}
