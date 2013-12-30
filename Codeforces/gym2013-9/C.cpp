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
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

const int N = 10010;
int n,m;


int inDeg[N];       // 入度
int sorted[N], pos; // 存最终排序后的结果,
vector<int>G[N];    // 拓扑关系图

void init() {  
    memset(inDeg, 0, sizeof(inDeg));
    for (int i = 0; i <= n; ++i) G[i].clear();
}  

int topoSort(){  
    queue<int>q; 
    for(int i = 1; i <= n; ++i) 
        if(inDeg[i] == 0) q.push(i);  
    pos=0; 
    bool unSure=false;  
    while ( !q.empty() ) {  
        if ( q.size() > 1 ) unSure=true;  
        int t = q.front();  
        q.pop();  
        sorted[pos++]=t;  
        for (int i = 0; i < G[t].size(); ++i){  
            int v = G[t][i];
            if (--inDeg[v] == 0)  
                q.push(v);  
        }  
    } 
    if ( pos < n ) return 1;   // 有环
    if ( unSure )  return 2; // 没有唯一解 
    return 3;    // 有唯一解
} 

int main(){

    int T;
    scanf("%d", &T);

    while (T--) {

        scanf("%d%d", &n, &m);

        init();

        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            ++inDeg[v];
            G[u].push_back(v);
        }

        int res = topoSort();
        if (res == 1) puts("recheck hints");
        else if (res == 2) puts("missing hints");
        else if (res == 3) {
            printf("%d", sorted[0]);
            for (int i = 1; i < n; ++i)
                printf(" %d", sorted[i]);
            puts("");
        }
    }
    return 0;
}
