/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：cf-1001
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;

int arr[100];

int main(){

    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < m; ++i) 
            scanf("%d", &arr[i]);

        sort(arr, arr+m);
        int ans = INF;
        for(int i = m-1; i >=n-1; --i) {
            ans = min(ans, arr[i]-arr[i-n+1]);
        }
        printf("%d\n", ans);
    }
	return 0;
}
