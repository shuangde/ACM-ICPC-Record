//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

char str[100010];

int main () {

    double a;
    int b;
    scanf("%s", str);
    int i;
    for (i=0; str[i]!='E'; ++i) ;;
    sscanf(str+i+1, "%d", &b);
    if (b > 0) {
        string ans;
        if (str[0] == '-') putchar('-');
        int i;
        for (i = 1; str[i]!='.'; ++i)
            ans += str[i];
        int cnt = 0;
        for (i++; str[i]!='E'&&cnt<b; ++i) {
            ++cnt;
            ans += str[i];
        }
        if (str[i] != 'E') {
            ans += '.';
            for (; str[i]!='E'; ++i) {
                ++cnt;
                ans += str[i];
            }
        } else {
            while (cnt < b) ans +='0', ++cnt;
        }
        i = 0;
        for ( ; i < ans.size()&&ans[i]=='0'&&ans[i+1]!='.'; ++i) ;;
        for ( ; i < ans.size(); ++i)
            cout << ans[i];

    } else {
        b = -b;
        string ans;
        int i;
        for (i=0; str[i]!='E'; ++i) ;;
        for (--i; str[i]!='.'; --i)
            ans += str[i];
        int cnt = 0;
        for (--i; i>=1&&cnt<b; --i) {
            ++cnt;
            ans += str[i];
        }
        if (i >= 1) {
            ans += '.';
            for ( ; i >= 1; --i)
                ans += str[i];
        } else {
            while (cnt < b) ans += '0', ++cnt;
            ans += ".0";
        }
        if (str[0] == '-') ans += '-';
        for (i=ans.size()-1; i>=0; --i)
            cout << ans[i];
    }
    puts("");
    return 0;
}
