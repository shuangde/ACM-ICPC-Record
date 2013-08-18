/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：poj-1837 Balance
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
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

const int MID = 11000;
int C, G; 
int pos[30];
int weight[30];

int f[2][MID*2];

int main(){

    scanf("%d%d", &C, &G);

    for(int i = 0; i < C; ++i)
        scanf("%d", &pos[i]);

    int sum = 0;
    for(int i = 0; i < G; ++i) {
        scanf("%d", &weight[i]);
        sum += weight[i];
    }

    memset(f, 0, sizeof(f));
    f[0][MID] = 1;

    int p  = 0;
    int ans = 0;
    for(int i = 0; i < G; ++i) {
        p = !p;
        memset(f[p], 0, sizeof(f[p]));
        for(int j = 0; j < C; ++j) {
            int w = weight[i] * pos[j]; 

            for(int v = -15 * sum; v <= 15 * sum; ++v) {
                int now = v + MID;
                if(f[!p][now] && now+w>=0 && now+w<MID*2){
                    f[p][now+w] += f[!p][now];
                }
            }
        }
    }
    printf("%d\n", f[p][MID]);
    return 0;
}
