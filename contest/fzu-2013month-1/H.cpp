
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

int n;
struct Node {
    int val, id;
    bool operator < (const Node& rhs) const {
        return val < rhs.val; 
    }
};
vector<Node>vt;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vt.clear();
        for (int i = 0; i < n; ++i) {
            int x;
            scanf ("%d", &x);
            vt.push_back((Node){x, i});
        }
        sort(vt.begin(), vt.end());
        map<int, int>line;
        int maxLen = 0, pt = 0;
        for (int i = 1; i <= n; ++i) {
            while (maxLen < i) {
                line[vt[pt].id] = 1;
                map<int, int>::iterator it = line.find(vt[pt].id);
                map<int, int>::iterator pre = it;
                pre--;
                if (it!=line.begin() && pre->first+pre->second == it->first) {
                    pre->second += it->second;
                    swap(pre, it);
                    line.erase(pre);
                }

                map<int, int>::iterator next = it;
                ++next;
                if (next != line.end() && it->first+it->second == next->first) {
                    it->second += next->second;
                    maxLen = max(maxLen, it->second);
                    line.erase(next);
                }
                maxLen = max(maxLen, it->second);
                ++pt;
            }
            printf("%d\n", vt[pt-1].val);
        }
    }
    return 0;
}
