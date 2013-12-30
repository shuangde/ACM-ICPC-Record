
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
const int64 MOD = (1e9)+7;

int n, A[100010];
int64 x;

int main(){

    /*
    freopen("input.txt", "w", stdout);
    puts("98304 2");
    for (int i = 0; i < 98304; ++i)
        printf("0 ") ;
    puts("");
    return 0;
    */

    while (cin >> n >> x) {

        map<int64, int64>po; 
        int64 sum = 0;

        rep (i, n) {
            cin >> A[i];
            sum += A[i];
        }

        rep (i, n) {
            po[sum-A[i]]++; 
        }

        int64 minx = sum;

        for (map<int64,int64>::iterator it = po.begin(); it != po.end(); ++it) {
            if (it->second >= x) {
                po[it->first+1] += it->second/x;
                it->second %= x;
            }
            if (it->second > 0) minx = min(minx, it->first);
        }

        int64 res = 1, tmp = x, n = minx%(MOD-1);;
        while (n > 0) {
            if (n&1) res = (res * tmp)%MOD;
            tmp = (tmp*tmp) % MOD;
            n >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}
