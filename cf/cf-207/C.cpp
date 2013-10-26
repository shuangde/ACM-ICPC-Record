#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

const int MAXN =  (1e5+10)*3;
set<int>q;
int n, m;
int ans[MAXN];

int main () {

    while (~scanf("%d%d", &n, &m)) {

        q.clear();
        for (int i = 1; i <= n; ++i)
            q.insert(i); 

        memset(ans, 0, sizeof(ans));
        set<int>::iterator it, tmp;

        for (int i = 1; i <= m; ++i) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            
            it = q.lower_bound(l);

            for ( ; it != q.end() && (*it) <= r; ) {
                tmp = it;
                ++it;
                if (*tmp != x) {
                    ans[*tmp] = x;
                    q.erase(tmp);
                }
            }
        }
        printf("%d", ans[1]);
        for (int i = 2; i <= n; ++i) {
            printf(" %d", ans[i]); 
        }
        puts("");
    }
    return 0;
}
