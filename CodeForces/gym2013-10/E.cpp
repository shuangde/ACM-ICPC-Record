
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

int main() {

    freopen("ghanophobia.in", "r", stdin);
    int T, cas=1;
    scanf("%d%*c", &T);
    while (T--) {
        int a, b;
        /*
        char str[100];
        scanf("%d", &a);
        gets(str);
        //puts(str);
        char *p = str;
        while (*p != ':') ++p;
        ++p;
        sscanf(p, "%d", &b);
        */
        scanf("%d:%d",&a,&b);
        a += 1, b += 6;
        printf("Case %d: ", cas++);
        if (a > b) puts("YES");
        else if (a < b) puts("NO");
        else {
            a++, b += (b-6);
            if (a == b)
                puts("PENALTIES");
            else if (a < b) puts("NO");
            else puts("YES");
        }
    }
    return 0;
}
