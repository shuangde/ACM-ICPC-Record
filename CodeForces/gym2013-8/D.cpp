
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

int n, r;

int main(){

    scanf("%d%d" ,&n, &r);
    map<int64, int>cnt;
    map<int64, int>path;

    for (int i = 0; i < r; ++i) {

        int64 l;
        cin >> l;

        while (l >= 1) {
            path[l] = 1;
            if ((l^1)!=0) cnt[l^1] = 1;
            l >>= 1;
        }
    }
    vector<int64>vt;
    map<int64, int>::iterator it;

    for (it=cnt.begin(); it!=cnt.end(); ++it) {
        if (path.find((*it).first) == path.end()) {
            vt.push_back((*it).first);
        }
    }
    sort(vt.begin(), vt.end());
    for (int i = 0; i < vt.size(); ++i) {
        if (i) cout << " " << vt[i];
        else cout << vt[i];
    }
    puts("");
    return 0;
}
