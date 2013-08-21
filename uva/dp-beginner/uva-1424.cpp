/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-1424 Salesmen 
 *   @description : dp
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 11:40 All rights reserved. 
 *======================================================*/

/*
题意：
   给一个n个点m条边的有向无环图，再给一个长度L的序列A，然后求图中的一条长度为L的路径B（这条路径的同一个点可以连续重复出现多次）
   问路径B和序列A不相等的数最少多少， 即Ai != Bi,  0<=i<L的数。

思路:
   刚看这题，就觉得像树形dp，最终做出来不像树形dp。。
   f[i][j]表示i点，在路径序列的前j点中的最小距离。
   那么
   j=0, f[u][0] = d(u, arr[0]);
   j>0, f[u][j] = min(f[u][j], f[v][j-1]+d(u, arr[j])), v是与u相邻的点
   f[u][j] = min(f[u][j], f[u][i-1]+d(u,arr[i])); //取重复当前点的情况
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);
const int MAXN = 210;  
  
int n, m, len,ans,arr[MAXN];  
bool vis[MAXN];  
int f[MAXN][MAXN];  
vector<int>adj[MAXN];  
  
inline int d(int a, int b){  
    if(a==b) return 0;  
    else return 1;  
}  
  
  
int main(){  
  
    int T;  
    scanf("%d", &T);  
    while(T--){  
  
        scanf("%d%d", &n, &m);  
        for(int i=0; i<n; ++i)   
            adj[i].clear();  
  
        for(int i=0; i<m; ++i){  
            int u, v;  
            scanf("%d%d", &u, &v);  
            --u; --v;  
            adj[u].push_back(v);  
            adj[v].push_back(u);  
          
        }  
        scanf("%d", &len);  
        for(int i=0; i<len; ++i){  
            scanf("%d", &arr[i]);  
            --arr[i];  
        }  
  
        memset(f, 0x3f, sizeof(f));  
  
        for(int i=0; i<len; ++i){  
            for(int u=0; u<n; ++u){  
                for(int j=0; j<adj[u].size(); ++j){  
                    int v = adj[u][j];  
                    if(i==0)   
                        f[u][i] = d(u, arr[i]);  
                    else {  
                        f[u][i] = min(f[u][i], f[u][i-1]+d(u,arr[i]));  
                        f[u][i] = min(f[u][i], f[v][i-1]+d(u,arr[i]));  
                    }  
                }   
            }  
        }  
  
        ans = INF;  
        for(int i=0; i<n; ++i)  
            ans = min(ans, f[i][len-1]);  
  
        printf("%d\n", ans);  
    }  
  
    return 0;  
}  
