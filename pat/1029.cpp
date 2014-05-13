// shuangde
// 简单排序
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstring>
#define rep(i,n) for (int i=0;i<n;++i)
using namespace std;
typedef long long LL;

LL a[1000010];
LL b[1000010];

int main () {
    int n, m;
    scanf("%d", &n);
	rep(i, n) {
        scanf("%lld", &a[i]);	
	}
    scanf("%d", &m);
	rep(i, m) {
        scanf("%lld", &b[i]);	
	}
    int i = 0, j = 0;
    int idx = 0;
	LL ans;
    int mid = (n+m)/2-1+((n+m)&1); 
	while ((i < n || j < m) && idx <= mid) {
        ++idx;
        if (j>=m || i<n&&a[i]<=b[j])
            ans = a[i], ++i;
		else
            ans = b[j], ++j;
	}
    printf("%lld\n", ans);
    return 0;
}
