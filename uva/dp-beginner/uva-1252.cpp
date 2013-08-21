/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-1252 Twenty Question
 *   @type:  记忆化搜索
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意:
   有n个长度为m的二进制串，每个都是不同的。
   为了把所有字符串区分开，你可以询问，每次可以问某位上是0还是1。
   问最少提问次数，可以把所有字符串区分开来。

思路:
   f[s1][s2]: 表示提问的问题是{s1}集合，答案是{s2}时，还需要问几次才可以全部区分开

   当问题集合为{s1}时， 如果还不能区分所有答案，那么就需要继续再问一个问题，
   那么可以推出下一个问题的集合为：
   nextQuestions = { s1 | (1<<k),  当s1的k位上为0的时候 }

   那么可以得到：
   f[s1][s2] = 0, 如果和答案s2相同的个数小于等于1，那么已经可以全部区分开了，还要询问0次
   f[s1][s2] = { min(f[nextQuestions][s1], f[nextQuestions][s1^(1<<k)]), 当s1的k位上为0时}

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

const int MAXN = 130;
int n, m;

int p[MAXN];
int f[(1<<11)+10][(1<<11)+10];

int dfs(int s1, int s2){
    if(f[s1][s2] != INF) return f[s1][s2];

    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if( (p[i] & s1) == s2)
            ++cnt;

    if(cnt <= 1){
        f[s1][s2] = 0;
        return 0;
    }

    for(int i=0; i<m; ++i){
        if( s1&(1<<i) ) continue;
        int nextQuest = s1 | (1<<i);
        int& d = f[s1][s2];
        d = min(d, max(dfs(nextQuest, s2), dfs(nextQuest, s2^(1<<i)))+1);
    }
    return f[s1][s2];
}

int main(){

    char str[130];
    while(~scanf("%d%d", &m, &n) && n+m){

        for(int i = 0; i < n; ++i){
            scanf("%s", str);
            p[i] = 0;
            for(int j = 0; str[j]; ++j)
                if(str[j] == '1') 
                    p[i] |= 1<<j;
        }
        memset(f, INF, sizeof(f));
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}
