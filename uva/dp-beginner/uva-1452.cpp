/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-1452 Jump
 *   @description : 约瑟夫环变形
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:16 All rights reserved. 
 *======================================================*/

/*
题意:
   把1～n按逆时针顺序排成一个圆圈，从1开始没k个数字删除掉一个，知道所有数字都删完。
   求最后删除的3个数。

思路:
   我们已经知道了，怎么可以推出最后一个被删除的编号（可参考百度百科）
   f(1) = 0, 表示最后还剩下一个时，这个编号为0
   f(n) = (f(n-1) + m) % n
   那么保存最后第1,2,3个数，一直推到第一个即可。

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

const int MAXN = 110;

int n, m;

int main(){

    int T;
    scanf("%d", &T);

    while(T--){

        scanf("%d%d", &n, &m);

        int ans1 = 0, ans2, ans3;
        for(int i=2; i<=n; ++i){
            ans1 = (ans1+m) % i;
            if(i==2){
                // 当剩下最后2个数时，编号为0，1, 推出倒数第二个删除的数当前值
                ans2 = !ans1;
            }else if(i==3){
                // 当剩下最后3个数时，编号为0，1，2, 推出倒数第三个删除的数当前值
                ans2 = (ans2+m) % i;
                bool vis[3];
                memset(vis, 0, sizeof(vis));
                vis[ans1] = vis[ans2] = true;
                for(int j=0; j<3; ++j)if(!vis[j]){
                    ans3 = j; break; 
                }
            }else{
                ans2 = (ans2+m) % i;
                ans3 = (ans3+m) % i;
            }
        }
        ans1 = (ans1+1)%n; 
        ans2 = (ans2+1)%n;
        ans3 = (ans3+1)%n;
        printf("%d %d %d\n", ans3?ans3:n, ans2?ans2:n, ans1?ans1:n);
    }

    return 0;
}
