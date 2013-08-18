/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：cf-195-c
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

const int MAXN = 1e5+10;
int A[MAXN];

int main(){


    int n;

    while(~scanf("%d", &n)){
    
        for(int i=0; i<n; ++i)
            scanf("%d", &A[i]); 

        int v = -1;
        int64 sum;
        for(int i=0; i<31; ++i){
            
            sum = (1<<(i+1))-1; 

            for(int j=0; j<n; ++j){
                if( (A[j]>>i)&1 ){
                    sum &= A[j]; 
                }
            }
            if( sum == (1<<i)){
                v = i; 
            }
        }

        vector<int>vt;
        for(int i=0; i<n; ++i) {
            if( (A[i]>>v) & 1){
                vt.push_back(A[i]); 
            }
        }
        /*
        sort(vt.begin(), vt.end());
        vt.erase(unique(vt.begin(), vt.end()), vt.end()); 
        */
        printf("%d\n", vt.size());
        bool first = true;
        for(int i=0; i<vt.size(); ++i)
            if(first){first=false; printf("%d", vt[i]);}
            else printf(" %d", vt[i]);
        puts("");

    }


    return 0;
}
