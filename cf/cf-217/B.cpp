#include <cstdio> 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    
    int n;
    scanf("%d", &n);
    vector<int>vt[n];
    for (int i = 0; i < n; ++i) {
        int m; scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            int x; scanf("%d", &x);
            vt[i].push_back(x);
        }
        sort(vt[i].begin(), vt[i].end());
    }
    
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) if(i!=j && vt[j].size() <= vt[i].size()){
            int k, pt = 0;
            for (k = 0; k < vt[i].size() && pt < vt[j].size(); ++k) if(vt[i][k] == vt[j][pt]) ++pt;
            if (pt == vt[j].size()) { 
                ok = false; break;
            }
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
