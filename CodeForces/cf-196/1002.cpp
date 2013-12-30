/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：cf-1002
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstring>
#include <list>
using namespace std;

typedef long long int64;

inline int gcd( int a,int b){
    while(b^=a^=b^=a%=b);
    return a;
}
int a, b, c, d;

int main(){
    int tempa, tempb, tempc, tempd;

    while(~scanf("%d%d%d%d",&a,&b,&c,&d)){

        int lcn = b / gcd(b,d)*d;

        tempa = a*lcn/b;
        tempb = lcn;
        tempc = c*lcn/d;
        tempd = lcn;

        if(tempa>=tempc){
            int ans = tempa-tempc;
            int b = gcd(ans,tempa);
            printf("%d/%d\n",ans/b,tempa/b);
            continue;
        }

        lcn=a/gcd(a,c)*c;
        tempa=lcn;
        tempb=b*lcn/a;
        tempc=lcn;
        tempd=d*lcn/c;

        int ans=tempb-tempd;
        int ggg=gcd(ans,tempb);

        printf("%d/%d\n",ans/ggg,tempb/ggg);
    }
    return 0;
}

