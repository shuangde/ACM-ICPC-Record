/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : C2
 *   @description :
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/10/16 15:09 All rights reserved. 
 *======================================================*/
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

const int MAXN = (1e5+10)*3;
int n, m;
int f[MAXN], ans[MAXN];

int find(int x) {
    return x==f[x] ? x : f[x] = find(f[x]);
}

int main(){

    while (~scanf("%d%d", &n, &m)) {

        for (int i = 1; i <= n+2; ++i)
            f[i] = i;

        memset(ans, 0, sizeof(ans));

        for (int i = 0; i < m; ++i) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            for (int j = find(l); j <= r; j = find(j+1)) {
                if (j != x) {
                    ans[j] = x;
                    f[j] = j + 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}
