
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

int n, k;
int A[200000];

int main(){

    while (~scanf("%d%d", &n, &k)) {
        int idx = 0;
        for (int i = 1; i <= n; ++i, idx += 2) {
            A[idx] = 2*i;
            A[idx+1] = 2*i-1;
        }

        idx = 0;
        for (int i = 0; i < k; ++i, idx+=2) {
            swap(A[idx], A[idx+1]);
        }

        printf("%d", A[0]);
        for (int i = 1; i < 2 * n; ++i) {
            printf(" %d", A[i]);
        }
        puts("");
    }
    return 0;
}
