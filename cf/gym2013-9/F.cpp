
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
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

char str[5000000];
int cnt[1000];
int ans;

int solve() {
    int cnt_ok = 0;
    int maxx = -1, max_cnt = 0;
    for (int k = 0; k <= 25; ++k) {
        int tmp = (4+k)%26 + (int)'A';
        if (cnt[tmp] > maxx) {
            maxx = cnt[tmp];
            max_cnt = 1;
            ans = k;
        } else if (cnt[tmp] == maxx) {
            max_cnt++; 
        }
    }
    return max_cnt == 1;
}

int main(){
    int T;
    scanf("%d%*c", &T);

    while (T--) {
        gets(str);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; str[i]; ++i) 
            if (str[i] != ' ')  {
                ++cnt[str[i]];
            }
        if (solve()) {
            printf("%d ", ans);
            for (int i = 0; str[i]; ++i) 
                printf("%c", str[i]!=' ' ? (str[i]-'A'-ans+26)%26+'A' : ' ');
            puts("");
        } else { 
            puts("NOT POSSIBLE");
        }

    }
    return 0;
}
