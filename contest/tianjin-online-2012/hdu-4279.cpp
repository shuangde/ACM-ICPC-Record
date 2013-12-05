
//shuangde
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long int64;

int64 sum(int64 x, int d) {
    int64 tmp = x/2-2+ d;
    return max(tmp, (int64)0);
}

int bin(int64 x) {
    int64 l = 0, r = 3073700049;
    while (l <= r) {
        int64 m = l + r>>1;
        int64 tmp = m * m;
        if (tmp < 0 || tmp > x) r = m - 1;
        else if (tmp == x) return m;
        else l = m + 1;
    }
    if (r*r > x) --r;
    return r;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int64 x, y;
        cin >> x >> y;
        int a = bin(x-1), b = bin(y);
        cout << sum(y, b&1) - sum(x-1, a&1) << endl;
    } 

    return 0;
}
