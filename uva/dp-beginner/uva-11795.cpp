/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-11795 Mega Man's Mission
 *   @description : 状态压缩dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:14 All rights reserved. 
 *======================================================*/

/*
题意：
   你最初只有一个武器，你需要按照一定的顺序消灭n个机器人(n<=16)。每消灭一个机器人将会得到他的武器。
   每个武器只能杀死特定的机器人。
   问可以消灭所有机器人的顺序方案总数。


思路：
   看到了n的规模这么小，就知道可以用状态压缩解决了。
   f[s]表示状态为{s}时的方案总数.
   我们设{s-1}是s状态把一个二进制位是1的变为0的所有情况，相当于集合中少了某个机器人的所有情况
   那么f[s] = sum{ 所有的{s-1}， 消灭了{s-1}个机器人时获得的武器能够杀掉少了的这个机器人}
   初始化f[0] = 1, 表示一个机器人都不杀的方案有1个
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

const int MAXN = 10010;
int n, maxState;
int p[20];
char str[20];

int kill[(1<<16)+10];
int64 f[(1<<16)+10];


int main(){
    
    int T;
    int cas = 1;
    scanf("%d", &T);
    while(T--){

        scanf("%d", &n);

        for(int i=0; i<=n; ++i){
            scanf("%s", str);
            p[i] = 0;
            for(int j=0; str[j]; ++j)
                if(str[j] == '1')
                    p[i] |= (1<<j);
        }

        maxState = (1<<n)-1;
        kill[0] = p[0];
        for(int s=1; s<=maxState; ++s){
            kill[s] = p[0];
            for(int i=0; i<n; ++i)
                if((s>>i) & 1) kill[s] |= p[i+1];
        }

        memset(f, 0, sizeof(f));
        f[0] = 1;
        for(int s=1; s<=maxState; ++s){
            f[s] = 0;
            for(int i=0; i<n; ++i)if( (kill[s^(1<<i)]>>i) & 1){
                f[s] += f[s^(1<<i)];
            }  
        }
        printf("Case %d: %lld\n", cas++, f[maxState]);
    }

    return 0;
}
