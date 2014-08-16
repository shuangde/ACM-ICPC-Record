//排序
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
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 40010;
int n, m, k;
int quota[110];
int pref[N][6];
bool vis[110][N];
vector<int>school[110];

struct Node {
    int id;
    int ge, gi, fi;
    int rank;
    bool operator < (const Node& rhs) const {
        if (fi != rhs.fi) 
            return fi > rhs.fi;
        return ge > rhs.ge;
    }
}arr[N];

int main () {
    scanf("%d%d%d", &n,&m,&k);
    for (int i = 0; i < m; ++i)
        scanf("%d", &quota[i]);
    for (int i = 0; i < n; ++i) {
        arr[i].id = i;
        scanf("%d%d", &arr[i].ge, &arr[i].gi);
        arr[i].fi = arr[i].ge+arr[i].gi;
        for (int j = 0; j < k; ++j) 
            scanf("%d", &pref[i][j]);
    }
    sort(arr, arr+n);

    int rank = 0;
    for (int i = 0; i < n; ++i) {
        if (i==0 || arr[i].fi==arr[i-1].fi
                && arr[i].ge==arr[i-1].ge)
            arr[i].rank = rank;
        else
            arr[i].rank = (rank = i);

        int id = arr[i].id;
        for (int j = 0; j < k; ++j) {
            int sch = pref[id][j];
            if (quota[sch] > 0) {
                school[sch].push_back(id); 
                quota[sch]--;
                vis[sch][arr[i].rank] = true;
                break;
            } else if (vis[sch][arr[i].rank]) {
                school[sch].push_back(id); 
                break;
            } 
        }
    }
    for (int i = 0; i < m; ++i) {
        sort(school[i].begin(), school[i].end());
        for (int j = 0; j < school[i].size(); ++j)
            printf("%s%d",j?" ":"",school[i][j]);
        puts("");
    }
    return 0;
}
