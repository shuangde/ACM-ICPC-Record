/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-11584 Partitioning by Palindromes
 *   @description : 简单dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 11:38 All rights reserved. 
 *======================================================*/

/*
题意：
   给一个字符串， 要求把它分割成若干个子串，使得每个子串都是回文串。问最少可以分割成多少个。

思路:
   f[i]表示以i结尾的串最少可以分割的串数。
   f[i] = min{ f[j]+1, 串[j,i]是回文串&&1<=j<=i }

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

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

const int MAXN = 1010;  
  
char str[MAXN];  
int f[MAXN];  
  
bool isPalind(int l, int r){  
    while(l<r){  
        if(str[l] != str[r]) return false;  
        ++l; --r;  
    }  
    return true;  
}  
  
int main(){  
  
    int T;  
    scanf("%d", &T);  
    while(T--){  
  
        scanf("%s", str+1);  
  
        int len = strlen(str+1);  
        memset(f, 0, sizeof(f));  
        for(int i=1; i<=len; ++i){  
            f[i] = i+1;  
            for(int j=1; j<=i; ++j)if(isPalind(j, i)){  
                f[i] = min(f[i], f[j-1]+1);  
            }  
        }  
        printf("%d\n", f[len]);  
    }  
    return 0;  
}  
