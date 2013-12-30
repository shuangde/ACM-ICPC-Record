
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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int MAXN = 300010;
int n;
int arr[MAXN], minx;
int f[MAXN], l[MAXN], r[MAXN];
bool vis[MAXN];
set<int>ans[MAXN];

int main(){

    while (~scanf("%d", &n)) {
        int minx = INF;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            minx = min(minx, arr[i]);
        }

        if (minx == 1) {
            printf("1 %d\n%d\n", n-1, 1); 
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            int j; for (j = i - 1; j >= 1 && arr[j]%arr[i]==0; j = l[j]-1) ;
            l[i] = j + 1;
        }
        for (int i = n; i >= 1; --i) {
            int j; for (j = i + 1; j <= n && arr[j]%arr[i]==0; j = r[j]+1) ;
            r[i] = j - 1;
        }

        int maxLen = -1, cnt = 0;
        for (int i = 1; i <= n; i = r[i] + 1) {
            int tmp = r[i]-l[i];
            if (tmp > maxLen) {
                cnt = 1;
                maxLen = tmp;
            } else if (tmp == maxLen) 
                ++cnt;
        }
        printf("%d %d\n", cnt, maxLen);
        for (int i = 1; i <= n; i = r[i] + 1) if (r[i]-l[i] == maxLen)
            printf("%d ", l[i]);
        puts("");
        /*
        // 方法二:
        for (int i = 0; i <= n; ++i) ans[i].clear();

        int maxLen = 0;
        for (int mid = 1; mid <= n; ) {
            int l = mid, r = mid;
            while (l>1 && arr[l-1]%arr[mid]==0) --l;
            while (r<n && arr[r+1]%arr[mid]==0) ++r;
            maxLen = max(maxLen, r-l);
            ans[r-l].insert(l);
            mid = r + 1;
        }

        printf("%d %d\n", ans[maxLen].size(), maxLen);
        for (set<int>::iterator it = ans[maxLen].begin(); it!=ans[maxLen].end(); ++it)
            printf("%d ", (*it));
        puts("");
        */
    }
    return 0;
}
