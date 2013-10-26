
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

const int MAXN = 100010;

string word[MAXN*2];
char str[MAXN];
int wc;
int n;
int len;

bool judge() {
    int idx = 0;
    len = strlen(str);
    int i;
    for ( i = 0; i < wc && idx < len; ++i) {
        int j;
        for (j = 0; j < word[i].length() && idx < len; ++j) {
            while (idx < len && str[idx] != word[i][j]) {
                ++idx;
            }
            ++idx;
        }
        if (j != word[i].length()) return false;
    }
    return i==wc;
}


int main(){

    while (~scanf("%d", &n)) {
        wc = 0;
        for (int i = 0; i < n; ++i) {
            word[wc++] = "<3";
            cin >> word[wc++];
        }
        word[wc++] = "<3";
        scanf("%s", str);
        if (judge()) puts("yes");
        else puts("no");
    }
    return 0;
}
