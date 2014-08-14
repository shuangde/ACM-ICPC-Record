//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 110;
char str[N][500];

int main () {
    int n, len = INF;
    scanf("%d%*c", &n);
    for (int i = 0; i < n; ++i) {
        gets(str[i]);
        len = min(len, (int)strlen(str[i]));
    }
    string ans;
    int l = strlen(str[0]);
    for (int i = 0; i < len; ++i) {
        bool flag = true;
        for (int j = 1; j < n; ++j)
            if (str[j][strlen(str[j])-1-i] != str[0][l-1-i]) {
                flag = false;
                break;
            }
        if (flag) {
            ans += str[0][l-1-i]; 
        } else 
            break;
    }
    if (ans.size() == 0) {
        puts("nai");
        return 0;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
