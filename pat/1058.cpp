//简单进制
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
int a[3], b[3];
int mod[3] = {INF, 17, 29};

int main () {
    scanf("%d.%d.%d", &a[0],&a[1],&a[2]);
    scanf("%d.%d.%d", &b[0],&b[1],&b[2]);
    for (int i = 2; i >= 0; --i) {
        b[i] += a[i];
        if (i) {
            b[i-1] += b[i]/mod[i];
            b[i] %= mod[i];
        }
    }
    printf("%d.%d.%d\n",b[0],b[1],b[2]);
    return 0;
}
