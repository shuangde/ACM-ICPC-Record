//gcd,lcm
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
typedef long long LL;
typedef pair<LL, LL >PII;
const int INF = 0x3f3f3f3f;

const int N = 110;
PII arr[N];

int main () {
    int n;
    scanf("%d", &n);
    LL lcm;
    for (int i = 0; i < n; ++i) {
        //cin >> arr[i].first >> arr[i].second;
        scanf("%lld/%lld",&arr[i].first,&arr[i].second);
        if (i) lcm = lcm / __gcd(lcm, arr[i].second) * arr[i].second;
        else lcm = arr[i].second;
    }
    LL nu = 0;
    for (int i = 0; i < n; ++i) {
        nu = nu + lcm / arr[i].second * arr[i].first;
    }

    if (nu%lcm == 0) {
        cout << nu/lcm << endl; 
        return 0;
    }
    
    LL g = __gcd(nu, lcm);
    nu /= g;
    LL den = lcm / g;
    if (nu / den != 0) {
        printf("%lld %lld/%lld\n",nu/den, nu%den, den);
    } else {
        printf("%lld/%lld\n", nu%den, den);
    }
    return 0;
}
