/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-11404 Palindromic Subsequence
 *   @type: LCS最小字典序回文串
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意：给一个字符串，输出它的最长回文串，如果有多个结果，输出字典序最小的。

思路：
我们都知道把一个字符串逆序后和原字符串进最长公共子序列，可以计算出它的最长回文串长度。
但是这题不仅要输出回文串，而且还要求是字典序最小的，所以挺难搞的。

设str1是正序字符串，str2是逆序后的字符串
f[i][j].len 表示str1的前i位，str2的前j位，最长公共子串的长度
f[i][j].str 表示str1的前i位，str2的前j位，最长公共子串的最小字典序的字符串

状态转移和正常的LCS差不多，只不过增加了记录字典序最小的字符串

但是最终的f[i][j].str却并不一定是答案，因为计算出来的最长公共子序列不一定就是回文串

例如：
kfclbckibbibjccbej
jebccjbibbikcblcfk

bcibbibc是他们的LCS，但是却不是回文串
但是它的前len/2个一定是回文串的一部分
知道了前len/2，就可以直接构造出回文串的后半部分了
要注意长度的奇偶性问题

*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 1010;
char str1[MAXN], str2[MAXN];
int n, len;

struct Node{
    int len;
    string str;
}f[MAXN][MAXN];


int main(){

    Node a, b;

    while(gets(str1+1)){

        // reverse
        len = strlen(str1+1);
        for(int i=1; i<=len; ++i)
            str2[i] = str1[len+1-i];

        // init
        for(int i=0; i<=len; ++i) 
            f[0][i].len = 0, f[0][i].str = "";

        // LCS
        for(int i = 1; i <= len; ++i) {
            for(int j = 1; j <= len; ++j) {
                if (str1[i] == str2[j]) {
                    f[i][j].len = f[i-1][j-1].len + 1;
                    f[i][j].str = f[i-1][j-1].str + str1[i];

                } else {
                    if(f[i-1][j].len > f[i][j-1].len) {
                        f[i][j].len = f[i-1][j].len;
                        f[i][j].str = f[i-1][j].str;

                    } else if (f[i][j-1].len > f[i-1][j].len) {
                        f[i][j].len = f[i][j-1].len;
                        f[i][j].str = f[i][j-1].str;

                    } else {
                        f[i][j].len = f[i-1][j].len;
                        f[i][j].str = min(f[i-1][j].str, f[i][j-1].str);
                    }
                }
            } 
        }

        int maxx = f[len][len].len;
        string ans = f[len][len].str;

        // output
        if(maxx & 1) {
            for(int i = 0; i < maxx/2; ++i)    
                cout << ans[i];
            for(int i = maxx/2; i >= 0; --i)
                cout << ans[i];
            putchar('\n');

        } else {
            for(int i = 0; i < maxx/2; ++i)        
                cout << ans[i];
            for(int i = maxx/2-1; i >= 0; --i)
                cout << ans[i];
            putchar('\n');
        }
    }
    return 0;
}
