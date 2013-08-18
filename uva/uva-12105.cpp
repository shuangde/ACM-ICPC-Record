/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-12105
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

#include<iostream> 
#include<string> 
#include<iomanip> 
#include<algorithm> 
using namespace std; 

char str[1010];
int modDigit[52]; //最多50位
int n, m;

int cost[10] = {6,2,5,5,4,5,6,3,7,6};

inline void init() {
    modDigit[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        modDigit[i] =  (modDigit[i-1] * 10) % m;
    }
}

/*
f(i, j): 表示前i个火柴，拼成j位整数的最大值
f(i, j) = max{
            max {f(i-cost[k], j-1,在某位上插入k) | 0<=k<=9},
            max {f(i-cost[k], j, 某位替换成k) | 0<=k<=9l}
            }
*/

int f[102][50][50];


int main() {


    while (~scanf("%d%d", &n, &m)) {
        init();

        memset(f, -1, sizeof(f));


        for(int i = 0; i <= n; ++i) {
            for(int j = 1; j <= n/2; ++j) { //最多n/2位
               
                for(int k = 0; k <= 9; ++k) {
                     
                }

            }         
        }
    }
    return 0;
}
