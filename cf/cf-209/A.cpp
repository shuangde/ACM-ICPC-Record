
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

const int MAXN = 1000010;
int n, m;
int mat[100][100];


int main(){

    while (~scanf("%d%d", &n, &m)) {

        bool ok = false;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                scanf("%d", &mat[i][j]);
                if (mat[i][j]) {
                    ++cnt;
                    if (i==0 || j==0 || i==n-1 || j==m-1) {
                        ok = true;
                    }
                }
            }
        if (ok) printf("%d\n", 2);
        else printf("4\n");
    }
    return 0;
}
