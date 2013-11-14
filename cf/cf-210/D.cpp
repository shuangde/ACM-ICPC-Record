
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

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int MAXN = 2010;
int n, k;
int arr[MAXN];
int f[MAXN];

bool ok(int maxDiff) {
    rep(i, n) f[i] = i;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(arr[i]-arr[j]) <= maxDiff*(i-j)) {
                f[i] = min(f[i], f[j]+i-j-1); 
            } 
        }
    }
}

int main() {
    
    while (cin >> n >> k) {
		int maxDiff = -INF;
        rep(i, n) {
			cin >> arr[i]; 
			if (i) maxDiff = max(maxDiff, abs(arr[i]-arr[i-1]));
		}
		int l = 0, r = maxDiff;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (ok(m)) {
			}	
		}
    }
    return 0;
}
