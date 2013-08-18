/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-1169 Robotruck
 *   @type:  dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/

/*
sumDis[i], 表示从0->1->2->....->i，即从0一直走到i个总距离
sumWeight[i], 表示前i个垃圾的总重量

假设要捡(j, i)这区间内的垃圾, 
令w(j,i) = sumWeight[i] - sumWeight[j-1]; 表示(j,i)区间垃圾的总重量

机器人的走路路径为：0->j->j+1->..->i->0,这段路的总距离为:
routeDist(j, i) = getDis(0, j) + sumDis[i] - sumDis[j] + getDis(0, i)

设f(i)表示捡完前i个垃圾走的最短距离，那么可得到状态转移
f(i) = min{ f(j-1) + routeDist(j, i),  1<=j<=i && sumWeight[i]-sumWeight[j-1] >= C }


上面式子可以改为：
f(i) = min{ f(j-1)+getDis(0,j)-sumDis[j] | 1<=j<=i && w(j,i)>=C} + sumDis[i] + getDis(0, i);

另func(j) = f(j-1)+getDis(0,j)-sumDis[j]) 
进一步简化为：
f(i) = min{ func(j) | 1<=j<=i && w(j,i)<=C} + sumDis[i] - getDis(0, i);
这样，我们只要维护一个最小值j，使得func(j)保持最小即可。
这就用到了单调队列来维护这个值

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

const int MAXN = 100010;
int C, n;
int sumDis[MAXN], sumWeight[MAXN];
int f[MAXN];

struct Node{
    int x, y, w;
}A[MAXN];

int getDis(int i, int j) {
    return abs(A[i].x-A[j].x) + abs(A[i].y-A[j].y);
}

// func(j) = f(j-1)+getDis(0,j)-sumDis[j]) 
inline int func(int j){
    return f[j-1] + getDis(0,j) - sumDis[j];
}

// w(j,i) = sumWeight[i] - sumWeight[j-1]
inline int w(int j, int i) {
    return sumWeight[i] - sumWeight[j-1];
}

int main(){

    int nCase;
    scanf("%d", &nCase);

    while(nCase--) {
    
        scanf("%d%d", &C, &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].w);
            sumDis[i] = sumDis[i-1] + getDis(i, i-1);
            sumWeight[i] = sumWeight[i-1] + A[i].w;
        }
        deque<int>que;
        for(int i = 1; i <= n; ++i) {
            while(!que.empty() && func(que.back()) >= func(i)) que.pop_back();
            que.push_back(i);
            while(!que.empty() && w(que.front(), i) > C) que.pop_front();  
            f[i] = func(que.front()) + sumDis[i] + getDis(0, i);
        }

        printf("%d\n", f[n]);
        if(nCase) putchar('\n');
    }

	return 0;
}
