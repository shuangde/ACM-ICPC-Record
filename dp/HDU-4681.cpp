/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：HDU-4681 String
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意：
给出3个字符串A,B,C，要你找一个字符串D, 要满足下面规定
a) D是A的子序列
b) D是B的子序列
c) C是D的子串
求D的最大长度
要注意子序列和子串的区别，子序列是不连续的，字串是连续的

思路：
可以看到"cf"在A串的[3, 6]区间内， 在B串的[2,6]区间(黄色背景)
因为所求的C是D的子串，所以在该区间内的其他字母一定不能取。
那么这个的最长长度等于红色区域和蓝色区域的最长公共子序列长度+C的长度
LCS算法的f(i, j)求的是第一个字符串的前i个和第二个字符串的前j个的最长公共字串
那么红色部分直接可以求出。
后面部分，只需要把两个字符串逆序倒置后在LCS求一次即可。

最后，求出所有的C在A,B的子序列区间，枚举一下即可得到答案

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef long long int64;
typedef pair<int,int > PII;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 1010;


vector<PII >vt1, vt2;

char A[MAXN], A2[MAXN];
char B[MAXN], B2[MAXN];
char C[MAXN];

int f1[MAXN][MAXN];
int f2[MAXN][MAXN];

int len1, len2, len3;
int a1, a2, b1, b2;


void reverse(){
    for(int i = 1; i <= len1; ++i)
        A2[i] = A[len1+1-i];
    for(int i = 1; i <= len2; ++i)
        B2[i] = B[len2+1-i];
}

void LCS(char* str1, char* str2, int f[MAXN][MAXN]){
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= len1; ++i) {
        for(int j = 1; j <= len2; ++j) {
            if(str1[i] == str2[j]) 
                f[i][j] = f[i-1][j-1] + 1;
            else 
                f[i][j] = max(f[i-1][j], f[i][j-1]);
        } 
    }
}

// 获取字串区间
void getCS(char* str, int len, vector<PII>& vt){
    for(int i = 1; i <= len; ++i) if(str[i]==C[1]){
        int p = i, j = 1;
        while(j <= len3 && p <= len) {
            if(C[j] == str[p]) {
                ++p; ++j;
            } else{
                ++p; 
            }
        }
        if(j == len3 +1) {
            vt.push_back(MP(i, p-1));   
        }
    } 

}

int main(){

    int nCase;
    int cas = 1;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%s%s%s", A+1, B+1, C+1);         

        len1 = strlen(A+1);
        len2 = strlen(B+1);
        len3 = strlen(C+1);

        LCS(A, B, f1);
        reverse();
        LCS(A2, B2, f2);

        vt1.clear();
        vt2.clear();

        getCS(A, len1, vt1);
        getCS(B, len2, vt2);

        int ans = 0;
        for(int i = 0; i < vt1.size(); ++i) {
            for(int j = 0; j < vt2.size(); ++j) {
                int a1 = vt1[i].first, a2 = vt1[i].second;
                int b1 = vt2[j].first, b2 = vt2[j].second;
                int tmp = f1[a1-1][b1-1] + f2[len1-a2][len2-b2] + len3;
                ans = max(ans, tmp);
            }
        }
        printf("Case #%d: %d\n",cas++, ans);
    }
    return 0;
}
