/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：1003
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const long long mod=1000000009;

typedef long long int64;
int n,m,k;

int64 power(long long m , long long n , long long k){ 
    long long ans = 1; 
    while(n){ 
        if(n&1) ans = (ans * m) % k; 
        n >>= 1;
        m = (m * m) % k; 
    } 
    return ans; 
} 

int main(){

    while(~scanf("%d%d%d",&n,&m,&k)){
        int a=n%k;
        int b=n/k;
        int64 ans=b*(k-1)+a, temp=k, add=1+k;
        int count=m-ans;

        if(count){
            ans=a+(b-count)*(k-1);
            ans+=2*k*(power(2,count,mod)-1);
        }

        cout << ans%mod << endl;
    }
    return 0;
}
