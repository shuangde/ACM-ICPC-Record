/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-10453 Make Palindrome
 *   @type: 记忆化搜索， 区间dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意: 
    给一个字符串，要求添加最少个字符，把它变成回文串，并输出。

思路：
    f(i, j) 表示区间(i, j) 内的字符串添加的最少个数，变成回文串
    那么, 如果str[i]==str[j], f(i, j) = f(i+1, j-1) + 1
    f(i, j) = min{f(i+1, j), f(i, j-1)} + 1;
    题目要输出方案，那么只要再开一个数组,根据状态转移递归输出即可

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

const int MAXN = 1010;
char str[MAXN];
int len;
int f[MAXN][MAXN];

// 记忆化搜索版本, f数组初始化INF
int dfs(int i, int j) {
    if (i>j || i==j) 
        return f[i][j] = 0;
    if (f[i][j] != INF) 
        return f[i][j];
    int& ans = f[i][j];
    if (str[i] == str[j]) 
        ans = dfs(i+1, j-1);
    ans = min(ans, min(dfs(i+1, j), dfs(i, j-1))+1);
    return f[i][j];
}

// 递推区间dp
void dp() {
    memset(f, 0, sizeof(f));
    for (int d = 2; d <= len; ++d) 
        for (int l = 0; l+d-1 <= len; ++l) {
            int r = l + d - 1;    
            int& ans = f[l][r] = INF;
            if(str[l] == str[r]) 
                ans = f[l+1][r-1];
            ans = min(ans, min(f[l+1][r], f[l][r-1])+1);
        } 
}

void output(int i, int j) {
    if (i > j) return;
    if (i==j) { printf("%c", str[i]); return; }
    if (str[i] == str[j]) {
        printf("%c", str[i]);
        output(i+1, j-1);
        printf("%c", str[i]);
    } else if (f[i][j] == f[i+1][j] + 1) {
        printf("%c", str[i]);
        output(i+1, j);
        printf("%c", str[i]);
    } else {
        printf("%c", str[j]);
        output(i, j-1);
        printf("%c", str[j]);
    }
}

int main(){

    while (gets(str)) {

        len = strlen(str);
        dp();
        printf("%d ", f[0][len-1]);
        output(0, len-1);
        putchar('\n');
    }
    return 0;
}
