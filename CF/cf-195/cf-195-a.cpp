/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：cf-195-a
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

int main(){

    int a, b;
    while(~scanf("%d%d", &a, &b)){
    
        int sum = abs(a) + abs(b);
        if(a>0 && b>0) printf("%d %d %d %d\n", 0, sum, sum, 0);
        else if(a<0 && b>0) printf("%d %d %d %d\n", -sum, 0, 0, sum);
        else if(a<0 && b<0) printf("%d %d %d %d\n", -sum, 0, 0, -sum);
        else printf("%d %d %d %d\n", 0, -sum, sum, 0);
    }

	return 0;
}
