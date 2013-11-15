
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

typedef pair<char, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 200010;
char str[MAXN];

int main() {

    while (gets(str + 1)) {
        str[0] = 'A';
        int p = 1, len = strlen(str+1); 
        vector<PII>ch;
        while (p < len+1) {
            if (str[p] != str[p-1]) {
                ch.push_back(MP(str[p], 1));
            } else {
                ch[ch.size()-1].second++; 
            }
            ++p;
        }
        int pre = 0;
        int cnt = 0;
        string str = "";
        for (int i = 0; i < ch.size(); ++i) {
            int j;
            for (j = 0; j < ch[i].second && j < (1+(pre!=2)); ++j) {
                putchar(ch[i].first);
            }
            if (j == 2) pre=2;
            else pre=1;
        }
        puts("");
    }
    return 0;
}
