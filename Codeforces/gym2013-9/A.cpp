// shuangde
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
#include<vector>
using namespace std;

typedef long long int64;
const int N = 1000010;
bool vis[N];

vector<int64>prime;
int64 cnt[N];

void init () {
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i < N; ++i) {
        for (int j = i * 2; j < N; j += i)
            vis[j] = true;
        if (!vis[i]) prime.push_back(i);
    }
}

int main(){
    init();
    int T; 
    int64 n, k;
    scanf("%d",&T);
    while(T--){
        cin>>n>>k;

        memset(cnt, 0, sizeof(cnt));
        vector<int64>exp;

        int64 x = k;
        for (int i = 0; i < prime.size() && x > 1; ++i) {
            if (x % prime[i] == 0) {
                exp.push_back(0);
                int idx = exp.size() - 1;
                while (x % prime[i] == 0) {
                    exp[idx]++;
                    x /= prime[i];
                }

                int64 tmp = prime[i];
                cnt[idx] += n / tmp;
                while (n / prime[i] >= tmp) {
                    tmp *= prime[i];
                    cnt[idx] += n/tmp;
                }
            }
        }
        if (x > 1) {
            exp.push_back(1);
            int idx = exp.size() - 1;
            int64 tmp = x;
            cnt[idx] += n / tmp;
            while (n / x >= tmp) {
                tmp *= x;    
                cnt[idx] += n / tmp;
            } 
        }
        int64 ans = (int64)1e18;
        for (int i = 0; i < exp.size(); ++i) {
            ans = min(ans, cnt[i]/exp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
