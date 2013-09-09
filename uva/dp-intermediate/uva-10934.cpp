/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10934 10934 Dropping water balloons
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/09 12:49 All rights reserved. 
 *======================================================*/
/*
题目：
你有k个一模一样的水球，在一个n层楼的建筑物上进行测试，你想知道水球最低从几层楼往下丢可以让水球破掉。由于你很懒，所以你想要丢最少次水球来测出水球刚好破掉的最低楼层。（在最糟情况下，水球在顶楼也不会破）你可以在某一层楼丢下水球来测试，如果水球没破，你可以再捡起来继续用。

Input
输入的每一行包含多组测试，每组测试为一行。每组测试包含两个整数 k 和 n， 1 <= k <= 100 而 n 是一个 64 位的整数（没错，这栋建筑物的确很高），最后一组k = 0，n=0 代表结束，这组测试不用处理。

Output
对于每次测试，输出在最糟情况下，测出水球破掉楼层的最少次数。如果他多于63次，就输出“More than 63 trials needed.”


思路：
这题题目挺容易读懂的，但是读懂题目后，却发现不知道问题要求的是什么，迫不得已看了下discuss，果然有人和我一样对题意“似懂非懂”


*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

int64 f[110][65];

inline void init() {
    memset(f, 0, sizeof(f));
    for (int i = 1; i < 64; ++i) {
        for (int j = 1; j < 64; ++j) { 
            f[i][j] = f[i][j-1] + f[i-1][j-1] + 1;
            if (j < 11)
            printf("%lld ", f[i][j]);
        }
        puts("");
    }
}
int main(){

    init();
    int k;
    int64 n;

    while (~scanf("%d%lld", &k, &n) && k) {

        if (k > 63) k = 63;
        for (int i = 0; i <= 63; ++i) {
            if (f[k][i] >= n) {
                printf("%d\n", i); 
                goto next;
            } 
        }
        puts("More than 63 trials needed.");
        next: ;
    }

    return 0;
}
