/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-672  Gangsters
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:45 All rights reserved. 
 *======================================================*/

/*
方法2：
   f[i]表示前i个人取得的最大值
   f[i] = max{ f[j]+P[i],  0<=j<i && 第j个人可进入门 && 第j个人的状态到i的状态可达 } 

   复杂度为O（n^2）
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

int f[MAXN];

bool check(int from, int to){
    return abs(arr[from].s-arr[to].s) <= abs(arr[to].t - arr[from].t);
}

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

        int ans = 0;
        
        memset(f, 0, sizeof(f));

        for(int i=1; i<=n; ++i)if(arr[i].t){
            for(int j=0; j<i; ++j)if(f[j]>=arr[j].p && check(j, i)){
                f[i] = max(f[i], f[j]+arr[i].p);
            }
            ans = max(ans, f[i]);
        }
        printf("%d\n", ans);
        if(nCase) puts("");
    }
    return 0;
}
