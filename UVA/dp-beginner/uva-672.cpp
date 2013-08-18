/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-672 Gangsters
 *   @type:  dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 110;

int n, K, T;

struct Node{
    int t, p, s;
    bool operator < (const Node& rhs)const{
        return t < rhs.t; 
    }
}arr[MAXN];

int f[MAXN][MAXN];

int main(){

    int nCase;

    scanf("%d", &nCase);

    arr[0].t = arr[0].p = arr[0].s = 0;
    while(nCase--){

        scanf("%d%d%d", &n, &K, &T);

        for(int i=1; i<=n; ++i) 
            scanf("%d", &arr[i].t);

        for(int i=1; i<=n; ++i)
            scanf("%d", &arr[i].p);

        for(int i=1; i<=n; ++i)
            scanf("%d", &arr[i].s);

        sort(arr+1, arr+1+n);

        memset(f, -1, sizeof(f));
        f[0][0] = 0;

        int ans = 0;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=K; ++j){
                for(int k=0; k<=K; ++k)if(f[i-1][k]!=-1 && abs(k-j) <= arr[i].t-arr[i-1].t){
                    if(j==arr[i].s && j){
                        f[i][j] = max(f[i][j], f[i-1][k]+arr[i].p); 
                    }else{
                        f[i][j] = max(f[i][j], f[i-1][k]); 
                    }
                    ans = max(ans, f[i][j]);
                } 
            }
        }

        printf("%d\n", ans);
        if(nCase) puts("");
    }
    return 0;
}
