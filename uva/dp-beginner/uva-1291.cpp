/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-1291 Dance Dance Revolution
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
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
