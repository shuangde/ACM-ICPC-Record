/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：hdu-3033 I love sneakers!
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

int n, m, k;

struct Node{
    int price, val;
    bool operator<(const Node& rhs) const {
        return price < rhs.price; 
    }
};
bool vis[110];
vector<Node>products[12];

int f[2][10010][110];
int sum[20];

/*
   f(i, j, k)：前i组用了容量j，选了k个的最大值
   f(i, j, k) = max{ f(i, j-A[i].t, k-1), f(i-1, j-A[i].t, k-1) } + A[i].val;
 */

int main(){

    while (~scanf("%d%d%d", &n, &m, &k)) {

        for (int i = 0; i <= k; ++i)
            products[i].clear();

        memset(sum, 0, sizeof(sum));

        for (int i = 0; i < n; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            products[a].push_back((Node){b,c});
        }

        for(int i = 0; i <= k; ++i)
            sort(products[i].begin(), products[i].end());


        int ans = 0;
        int p  = 0;
        memset(f, 0, sizeof(f));

        bool flag = true;
        for(int i = 1; i <= k; ++i) {
            p = !p;

            memset(f[p], 0, sizeof(f[p]));

            if(!products[i].size()) {
                flag = false;
                break;
            }

            int size = products[i-1].size()-1;
            if(size < 0) size = 0;

            for(int k = 0; k < products[i].size(); ++k) {
                Node& tmp = products[i][k]; 

                for(int v = m; v >= tmp.val; --v) {

                    if(i==1 || f[!p][v-tmp.price][size]) {
                        f[p][v][k] = max(f[p][v][k], f[!p][v-tmp.price][size]+tmp.val);
                    }

                    if(k > 0) {
                        if(f[p][v-tmp.price][k-1]) {
                            f[p][v][k] = max(f[p][v][k], f[p][v-tmp.price][k-1]+tmp.val); 
                        }
                        if(f[p][v][k-1]) {
                            f[p][v][k] = max(f[p][v][k], f[p][v][k-1]); 
                        }
                    }
                }
            }
            if(f[p][m][products[i].size()-1] == 0) flag=false;
        } 

        for(int i = 0; i < products[k].size(); ++i) 
            ans = max(ans, f[p][m][i]);
        if(flag) printf("%d\n", ans); 
        else printf("Impossible\n");
    }
    return 0;
}
