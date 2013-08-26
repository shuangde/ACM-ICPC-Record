/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : zoj-3627 Treasure Hunt II
 *   @description : 贪心
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/25 12:18 All rights reserved. 
 *======================================================*/
/*
题意:
   直线上有n个城市, 第i个城市和i+1个城市是相邻的.  每个城市都有vi的金币.
   Alice和Bob站在城市p, 他们每天可以选择走向一个相邻的城市, 也可以选择不走. 他们是单独行动的.
   他们经过一个城市就可以获得相应的金币(不能重复获得)
   作为一个队伍, 他们的最远距离不能操作M, 问T天内, 他们最多一共能拿多少金币?

思路:
   由于每次只能走一步，那么一定是一个人往左走，一个人往右走，因为如果两个人一起往同一个方向走，
   那么就和一个人一起走的效果是一样的。
   这里题目还有一个限制：两个人的相差距离不能超过m，那么，就可以让两个人先走到相距m米处，然后
   两个人同时一起往左边走，或者同时一起往右边走，这样就能保证两人的距离一直保持在m米内，又保证
   尽量获取更大长度区间的金币。
   所以，枚举两个人最开始走到相距m处的左右两点位置，然后再看剩下的时间还可以再继续一起往左或者
   往右继续走多远，最终取最大值的情况即可。
   需要注意边界的处理.

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

const int MAXN = 100010;
int n, m, t, p;

int64 val[MAXN];
int64 sum[MAXN];


int64 func(int64 *sum, int p) {

    int64 ans = val[p];
    for (int r = min(n, p + t); r >= p; --r) {
        int l = max(1, max(1, r - m));
        l = max(p-t, l);
        int rest_t = t - max(p-l, (r-p));
        int l1 = max(1, l - rest_t);
        int r1 = min(n, r + rest_t);
        ans = max(ans, max(sum[r]-sum[l1-1], sum[r1]-sum[l-1]));
    }
    return ans;
}

int main( ){

    while (~scanf("%d%d", &n, &p)) {

        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> val[i];
            sum[i] = sum[i-1] + val[i];
        }
        scanf("%d%d", &m, &t);
        int64 ans = func(sum, p);
        for (int i = 1; i <= n/2; ++i) 
            swap(val[i], val[n+1-i]);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + val[i];
        ans = max(ans, func(sum, n+1-p));
        cout << ans << endl;
    }
    return 0;
}
