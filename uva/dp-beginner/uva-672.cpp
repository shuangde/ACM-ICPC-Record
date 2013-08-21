/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-672 Gangsters
 *   @type:  dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
题意：
   有个酒店的门会改变尺寸，变化范围是【0，k】，这个门每秒钟尺寸可以变大1，可以减小1，也可以不变。
   现在有n个人，他们的尺寸为si，每个人在ti时刻想要进入酒店，只有在ti时刻酒店门的尺寸恰好和这个人的尺寸大小相等，这个人才可以进入。
   每个人有一个值Pi，当某人进入酒店，酒店就会增加Pi值。
   在[0,T]这段时间内（0秒时酒店的门尺寸状态是0），求让一些人进入酒店，使得总Pi值最大。



思路：
   开始时，以为同一时间两个人不能同时进入，结果WA了很久。 其实如果是同一时间，两个人的尺寸
   是相同的，门的状态也是相同的，那么两个人可以同时进入。

方法1：
   先把所有人按照时间t从小到大排序。
   首先，由题意可知，在t秒内，如果要从状态i到j，只有abs(i-j) <= t 才可行

   f[i][j]表示: 前i个人，门状态为j时的最大值。

   初始化f[0][1..K] = -1, f[0][0] = 0;
   f[i][j] = max{ f[i-1][k]+P[i], 当f[i-1][k]!=-1 && 状态k->j可行}
   如果j等于S[i],那么f[i][j]还要再加上P[i].

   这个方法复杂度为O（n*k*k）
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

int n, K, T;

struct Node{
    int t, p, s;
    bool operator < (const Node& rhs)const{
        return t < rhs.t; 
    }
}arr[MAXN];

int f[MAXN][MAXN];

int main(){

    int nCase;

    scanf("%d", &nCase);

    arr[0].t = arr[0].p = arr[0].s = 0;
    while(nCase--){

        scanf("%d%d%d", &n, &K, &T);

        for(int i=1; i<=n; ++i) 
            scanf("%d", &arr[i].t);

        for(int i=1; i<=n; ++i)
            scanf("%d", &arr[i].p);

        for(int i=1; i<=n; ++i)
            scanf("%d", &arr[i].s);

        sort(arr+1, arr+1+n);

        memset(f, -1, sizeof(f));
        f[0][0] = 0;

        int ans = 0;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=K; ++j){
                for(int k=0; k<=K; ++k)if(f[i-1][k]!=-1 && abs(k-j) <= arr[i].t-arr[i-1].t){
                    if(j==arr[i].s && j){
                        f[i][j] = max(f[i][j], f[i-1][k]+arr[i].p); 
                    }else{
                        f[i][j] = max(f[i][j], f[i-1][k]); 
                    }
                    ans = max(ans, f[i][j]);
                } 
            }
        }

        printf("%d\n", ans);
        if(nCase) puts("");
    }
    return 0;
}
