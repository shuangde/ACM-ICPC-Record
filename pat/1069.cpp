//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

int main () {
    char str[5];
    int x;
    scanf("%d", &x);
    sprintf(str, "%04d", x);
    if (str[0]==str[1] && str[2]==str[3] && str[1]==str[2]) {
        printf("%s - %s = 0000\n", str, str); 
        return 0;
    }
    while (1) {
        char a[5], b[5];
        strcpy(a, str);
        strcpy(b, str);
        sort(a, a+4, greater<char>());
        sort(b, b+4);
        int x, y;
        sscanf(a, "%d", &x);
        sscanf(b, "%d", &y);
        printf("%04d - %04d = %04d\n", x, y, x-y);
        if (x - y == 6174) break;
        sprintf(str, "%04d", x-y);
    }
    return 0;
}
