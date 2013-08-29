/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *  hello world!
 *
 *   @source      : test
 *   @description :
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/24 16:03 All rights reserved. 
 *======================================================*/
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

int main(){

    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        double sum = 0;
        for (int i = 0; i < 12; ++i) {
            double x;
            scanf("%lf", &x);
            sum += x;
        }

        sum /= 12.0;

        char buf[100];
        sprintf(buf, "%.2f", sum+0.0005);
        int i = strlen(buf) - 1;

        while(buf[i] == '0') {
            buf[i] = 0;
            --i;
        }

        if (buf[i] == '.') buf[i] = 0;
    }
    int64 a=100, b=1111;
    __gcd(a, b);

	return 0;
}
