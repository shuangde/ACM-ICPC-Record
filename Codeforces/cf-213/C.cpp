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
#include <cstdlib>
// 生成0~x-1
#define random(x) (rand()%x)
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

int64 a;
char s[4010];


int main() {


    while (cin >> a) {

        scanf("%s", s); 

        int len = strlen(s);
        map<int, int>cnt;

        for (int i = 0; i < len; ++i) {
            int sum = 0;
            for (int j = i; j < len; ++j) {
                sum += s[j] - '0';
                if (sum > a) break;
                if (a && sum>0 && a % sum == 0) {
                    cnt[sum]++;
                } else if (!a) {
                    cnt[sum]++;     
                }
            } 
        }
        int64 ans = 0;
        int64 add = 0;
        
        if (a) {
            for (map<int,int>::iterator it = cnt.begin(); it!=cnt.end() && it->first*it->first <= a ; ++it) {
                if (it->first == a/it->first) {
                    add = (int64)it->second * (int64)cnt[a/it->first];
                    break;
                } else {
                    ans += (int64)it->second * (int64)cnt[a/it->first];
                }
            }
            cout << ans*2+add << endl;
        } else {
            int64 tot = ((int64)(len+1)*len)/2;
            int64 tmp = cnt[0];
            ans = tmp * (tot-tmp) * 2 + tmp*tmp;
            cout << ans << endl; 
        }
    }
    return 0;
}
