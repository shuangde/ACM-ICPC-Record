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

int main () {
    int nCase, cas = 1;
    scanf("%d", &nCase);
    LL d = LL(1)<<63; d = -d;

    while (nCase--) {
        LL a, b, c;
        cin >> a >> b >> c;
        LL d = a + b;
        printf("Case #%d: ", cas++);
        if (a>0 && b>0) {
            if (d < 0) puts("true");
            else puts(d>c?"true":"false");
        } else if (a<0 && b<0) {
            if (d>=0) puts("false");
            else puts(d>c?"true":"false");
        } else {
            puts(d>c?"true":"false");
        }
    }
    return 0;
}
