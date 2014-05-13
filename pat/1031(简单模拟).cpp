// shuangde
// 简单模拟 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define rep(i,n) for (int i=0;i<n;++i)

char str[100];

int main () {

    gets(str);
    int h, w, n = strlen(str);
    for (w = 3; w <= n; ++w) {
        if((n + 2 - w)&1) continue;
        h = (n + 2 - w)/2;
        if (h<=w) break;
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i < h - 1) {
                if (j==0) {
                    putchar(str[i]);
                } else if (j == w-1) {
                    putchar(str[n-1-i]);
                } else {
                    putchar(' ');	
                }
            } else {
                putchar(str[h-1+j]);	
            }
        }
        putchar('\n');
    }
    return 0;
}
