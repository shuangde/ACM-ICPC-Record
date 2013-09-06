/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-11456 Trainsorting
 *   @description : dp, LIS
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/09/06 22:09 All rights reserved. 
 *======================================================*/

/*
题意
   艾琳是个开火车的机师，她也负责车厢的调度。她喜欢把车厢依重量由大到小排列，把最重的车厢摆在火车的前方。
   不幸的是，排列车厢并不容易。你不能直接把一截车厢拿起来放在别处。把一截车箱插入现有的列车中间并不切实际。一截车厢仅能接在列车的前面或后面。
   车厢以事先排定的顺序抵达车站。当一截车厢抵达时，艾琳可以把它接在列车的前方或后方，或根本不要这截车厢。列车越长越好，但是其中的车厢要依重量排列。
   依车厢抵达的顺序给你车厢的重量，艾琳所能接出的最长火车是多长？

思路
   这题算是经典的类型题吧。
   假设第一个车厢选择第i个放进去，那么接下来，放在i的右边的一定是比i的重量小的，为了让右边方向尽量长，
   就要在序列中第i个到最后一个选最长递减序列的顺序放。
   要放在i的左边的，一定是比i的重量要大的，同理，为了让左边方向尽量长，应该找以i为第一个(不能让其他代替)的最长递增
   序列。

   如果用枚举第一个车厢的朴素的方法算，并用nlogn的算法求最长递增（减）序列，那么复杂度达到n*n*logn
   而n最大2000, 计算量达到2000*2000*11 = 4000W+,显然超时。

   所以需要转换一下，只需要逆序计算最长递增（减）序列，对于第i个，当它插入LIS序列时，可以得到以它为开始的最长递增（减）
   序列的长度，等于在LIS序列第一个到插入位置的个数，就是他的最长递增（减）序列的长度了

   可能没讲清楚，代码好理解。

   注意，求最长递减序列时，我把每个数字转化成了负数，这样就变成了求最长递增序列，做起来更方便。

 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 2010;
int n;
int arr[MAXN];

int main(){

    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        vector<int>vt1, vt2;
        vector<int>::iterator iter;

        int ans = 0;

        for (int i = n - 1; i >= 0; --i) {

            int len1, len2;

            iter = lower_bound(vt1.begin(), vt1.end(), arr[i]);
            if (iter == vt1.end()) { 
                vt1.push_back(arr[i]);
                len1 = vt1.size();
            } else{
                *iter = arr[i]; 
                len1  = iter - vt1.begin() + 1;
            }

            iter = lower_bound(vt2.begin(), vt2.end(), -arr[i]);
            if (iter == vt2.end()) {
                vt2.push_back(-arr[i]);
                len2 = vt2.size();
            } else {
                *iter = -arr[i]; 
                len2 = iter - vt2.begin() + 1;
            }

            ans = max(ans, len1 + len2 - 1);
        }
        printf("%d\n", ans);
    }

    return 0;
}
