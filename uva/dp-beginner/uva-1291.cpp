/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-1291 Dance Dance Revolution
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *===========================================*/

/*
题意:
   给是一个跳舞机，初始状态两个脚都在0,  状态表示为(0, 0), 然后跳舞机会给你一系列舞步方向，例如2,3,4,2,3.......
   每次你必须选择一只脚移动到对应数字方向的各格子上。
   例如从初始状态(0,0),要移到1, 可以选择左脚或者右脚移上去，对应的状态为（1, 0）, （0,1）
   有一个限制，除了初始状态可以是（0, 0），之后的两只脚就不能再同时在一个格子上！
   移动脚要耗费体力， 从0移动到其它各自都是耗费2, 从1,2,3,4之间，如果是移动到相邻的格子，比如1->2, 1->4, 3->2, 4->3，耗费体力3
   如果是移动到对面的格子，比如1->3, 2->4，耗费体力4。
   如果某一步，停止不动，耗费体力1
   给一串方向，问最少用多少体力可以完成这些动作？

思路:
   f(i, j, k), 表示第i步，状态为（j，k）时花费的最少体力
   那么不难推出转移方程式：

   假设当前这个舞步是在ｓ，那么符合这一步的所有状态有：
   f(i, 0..4, s),  f(i, s, 0...4)

   然后可以根据上面的状态推出下一舞步的最少体力话费

   假设下一舞步是next

   那么

   如果f(i, j, s), (0<=j<=4)状态可达
   则可推出下一个的状态
   f(i+1, j, s) = f(i, j, k) + 1; // 停在当前不动
   f(i+1, next, s) = min{ f(i, j, s) + consume(j, next)}
   f(i+1, j, next) = min{ f(i, j, s) + consume(s, next)}

   同理，如果f(i, s, j), (0<=j<=4)状态可达
   也可推出下一个状态:
   f(i+1, s, j) = f(i, j, k) + 1; // 停在原地不动
   f(i+1, next, j) = min{ f(i, s, j) + consume(s, next)}
   f(i+1, s, next) = min{ f(i, s, j) + consume(j, next)} 

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

const int MAXN = 10010;
int n;
int dir[MAXN];
int f[MAXN][5][5];

inline int consume(int from, int to){
    if(from==to) return 1;
    if(from==0 || to==0) return 2;
    int res = abs(from-to);
    if(res == 1 || res==3) return 3;
    if(res == 2) return 4;
}

int main(){

    while(~scanf("%d", &dir[0]) && dir[0]){

        n = 1;
        while(~scanf("%d", &dir[n]) && dir[n]) ++n;

        memset(f, INF, sizeof(f));

        for(int i=0; i<=4; ++i)
            f[0][0][i] = f[0][i][0] = consume(0, i);


        for(int i=0; i<n-1; ++i){

            int s = dir[i];
            int next = dir[i+1];

            for(int j=0; j<=4; ++j) if(s!=j){
                if(f[i][s][j] != INF){
                    f[i+1][s][j] = min(f[i+1][s][j], f[i][s][j] + 1);

                    for(int k=0; k<=4; ++k){
                        f[i+1][next][j] = min(f[i+1][next][j], f[i][s][j] +consume(s, next)); 
                        f[i+1][s][next] = min(f[i+1][s][next], f[i][s][j] +consume(j, next)); 
                    } 

                }
                if(f[i][j][s] != INF){
                    f[i+1][j][s] = min(f[i+1][j][s], f[i][j][s] + 1); 

                    for(int k=0; k<=4; ++k){
                        f[i+1][next][s] = min(f[i+1][next][s], f[i][j][s] +consume(j, next)); 
                        f[i+1][j][next] = min(f[i+1][j][next], f[i][j][s] +consume(s, next)); 
                    } 
                }
            }
        } 
        int ans = INF;
        int s = dir[n-1];
        for(int i=0; i<=4; ++i)if(i!=s){
            ans = min(ans, min(f[n-1][i][s], f[n-1][s][i]));        
        }
        printf("%d\n", ans);
    }
    return 0;
}
