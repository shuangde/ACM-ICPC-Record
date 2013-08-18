/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：hdu-2577
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

char str[MAXN];
int f[MAXN][2];

int main(){

    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        
        scanf("%s", str+1);

        f[0][0] = 0;
        f[0][1] = 1;

        int len = strlen(str+1);

        for(int i = 1; i <= len; ++i) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                f[i][0] = min(f[i-1][0]+1, f[i-1][1]+2);
                f[i][1] = min(f[i-1][0]+2, f[i-1][1]+2);
            } else {
                f[i][0] = min(f[i-1][0]+2, f[i-1][1]+2);
                f[i][1] = min(f[i-1][0]+2, f[i-1][1]+1);
            }
        }
        printf("%d\n", min(f[len][0], f[len][1]+1));

    }
	return 0;
}
