/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-1427 Parade
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
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);
const int MAXN = 10005;

int n, m, k;
int mat[105][MAXN];
int t[105][MAXN];
int f[105][MAXN];
int l[MAXN], r[MAXN];
int sumVal[MAXN], sumT[MAXN];


inline int getSum(int* sum, int i, int j) {
    return sum[i] - sum[j];
}

// 读入加速  
inline int nextInt(){  
    char c = getchar();  
    while(!isdigit(c) && c!='-') c = getchar();  
    int sigma = 1;
    if(c=='-') {
        sigma = -1; 
        c = getchar();
    }
    int x = 0;  
    while(isdigit(c)){  
        x = x*10+c-'0';  
        c=getchar();  
    }  
    return x*sigma;  
}

int main(){

    while (~scanf("%d%d%d", &n, &m, &k) && n+m+k) {


        for (int i = 1; i <= n + 1; ++i) 
            for (int j = 2; j <= m + 1; ++j) 
                mat[i][j] = nextInt();

        for (int i = 1; i <= n + 1; ++i)
            for (int j = 2; j <= m + 1; ++j)
                t[i][j] = nextInt();

        // init
        memset(f[n+2], 0, sizeof(f[n+2]));

        for (int i = n + 1; i >= 1; --i) {
            deque<int>que;
            // from left to right
            sumVal[0] = sumT[0] = 1;
            int front = 0, rear = 0;
            for (int j = 1; j <= m + 1; ++j) {
                sumVal[j] = sumVal[j-1] + mat[i][j];
                sumT[j] = sumT[j-1] + t[i][j];

                int tmp = f[i+1][j] - sumVal[j];
                while(!que.empty() && f[i+1][que.back()]-sumVal[que.back()] <= tmp) 
                    que.pop_back();
                que.push_back(j);
                while (!que.empty() && getSum(sumT, j, que.front()) > k) 
                    que.pop_front();

                if (i < n + 1)
                    l[j] = max(f[i+1][j], f[i+1][que.front()] - sumVal[que.front()] + sumVal[j]);
                else
                    l[j] = max(-INF, sumVal[j] - sumVal[que.front()]);

            }

            // clear
            while (!que.empty()) que.pop_back();

            // from right to left
            sumVal[m+2] = sumT[m+2] = 0;
            for (int j = m + 2; j >= 2; --j) {
                sumVal[j] = sumVal[j+1] + mat[i][j];
                sumT[j] = sumT[j+1] + t[i][j];

                int tmp = f[i+1][j-1] - sumVal[j];

                while (!que.empty() && f[i+1][que.back()-1]-sumVal[que.back()] <= tmp) 
                    que.pop_back();
                que.push_back(j);
                while (!que.empty() && getSum(sumT, j, que.front()) > k) 
                    que.pop_front();

                if (i < n + 1)
                    r[j] = max(f[i+1][j-1], f[i+1][que.front()-1] - sumVal[que.front()] + sumVal[j] );
                else 
                    r[j] = max(-INF, sumVal[j]- sumVal[que.front()]);
                ///////////////////////////
                f[i][j-1] = max(l[j-1], r[j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= m +1; ++i)
            ans = max(ans, f[1][i]);
        printf("%d\n", ans);
    }

    return 0;
}
