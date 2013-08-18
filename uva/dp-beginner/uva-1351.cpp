/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-1351 String Compression
 *   @type:  区间dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题目大意：
给一个字符串，可以把连续相同的部分进行缩写成k(S)的形式，S是一个字符串，k表示有连续相同的S
例如，abgogogogo，可以缩写成ab4(go). 还可以嵌套缩写，比如
“nowletsgogogoletsgogogo”， 缩写成“now2(lets3(go))”

思路：
区间dp
f(i, j)表示字符串的i~j位的最小位数
那么
f(i, j) = min{
             min{ f(i,k)+f(k+1, j), i<=k<j }, 
             min{ digitNum(k)+f[l][l+k-1]+2, 如果字符串可以由前k个字符串重复组成的 }
            }

*/
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

const int MAXN = 210;
char str[MAXN];
int f[MAXN][MAXN], len;


// 判断字符串区间[l,r]之否由[l,l+k-1]字串连续组成的
bool check(int l, int r, int k){
    int len = r-l+1;
    int i = 0;
    while(i < k){
        for(int p=1; l+p*k+i<=r; ++p){
            if(str[l+i] != str[l+p*k+i])
                return false;
        }
        ++i;
    }
    return true;
}

// 计算数字ｘ有几位
inline int digitNum(int x){
    int cnt = 0;
    while(x > 0){ ++cnt; x /= 10; }
    return cnt;
}

int main(){

    int nCase;
    scanf("%d", &nCase);

    while(nCase--){
        
        scanf("%s", str+1);
        len = strlen(str+1);

        for(int i = 1; i <= len; ++i)
            f[i][i] = 1;

        for(int d = 2; d <= len; ++d) {
            for(int l = 1; l+d-1 <= len; ++l) {

                int r = l + d - 1;

                f[l][r] = INF;
                int& ret = f[l][r];

                for(int k=l; k<r; ++k)
                    ret = min(ret, f[l][k]+f[k+1][r]); 

                for(int k = 1; k <= d/2; ++k) {
                    if(d%k!=0) continue;
                    if(check(l, r, k)){
                        ret = min(ret, digitNum(d/k) + f[l][l+k-1] + 2); 
                    }
                }
            }
        }
        printf("%d\n", f[1][len]);
    }
	return 0;
}
