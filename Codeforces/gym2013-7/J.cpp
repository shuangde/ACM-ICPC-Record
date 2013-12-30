
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

char str[1000];

int main(){

    int n;
    while (~scanf("%d", &n)) {
        scanf("%s", str);
        int cnt = 0;
        int i = 0;
        while (i < n) {
            if (str[i] == 'S')
                ++cnt;
            else {
                ++cnt;
                ++i;
            }
            ++i;
        }
        printf("%d\n", min(n, cnt + 1));
    }

    return 0;
}
