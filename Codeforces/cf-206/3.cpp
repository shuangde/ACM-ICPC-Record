#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN  = 1e5+10;
int n, l,  r, Ql, Qr;
int w[MAXN], sum[MAXN], tot;

int solve() {
    if (n==1) {
        return min(l*w[1], r*w[1]); 
    } 
    if (n==2) {
        int tmp1 = l*w[1] + r*w[2];
        int tmp2 = min(l*sum[2] + Ql, r*sum[2] + Qr);
        return min(tmp1, tmp2);
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n-1; ++i) {
        // 如果是正中间
        if (i == n-i) {
            ans = min(ans, sum[i]*l + (sum[n]-sum[i])*r);
        // 如果左边比较少
        } else if (i < n-i){
            int tmp = sum[i]*l+(sum[n]-sum[i])*r +  Qr * (n-i-i-1);
            ans = min(ans, tmp);
        // 如果右边比较少
        } else {
            int tmp = sum[i]*l+(sum[n]-sum[i])*r +  Ql * (i+i-n-1);
            ans = min(ans, tmp);
        }
    }
    ans = min(ans, sum[n]*l+Ql*(n-1));
    ans = min(ans, sum[n]*r+Qr*(n-1));
    return ans;
}
int main () {

    while (~scanf("%d%d%d%d%d", &n, &l, &r, &Ql, &Qr)) {
         
        sum[0] = tot = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &w[i]);
            sum[i] = sum[i-1] + w[i];
        }
        printf("%d\n", solve());
    }
    return 0;
}
