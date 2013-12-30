#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;

const int MAXN  = 1010;
int c1, c2, c3, c4;
int num1[MAXN];
int num2[MAXN];
int f1[MAXN], f2[MAXN];
int f[MAXN];
int n, m;


int main () {

    while (~scanf("%d%d%d%d", &c1, &c2, &c3, &c4)) {
    
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &num1[i]);

        for (int i = 1; i <= m; ++i)
            scanf("%d", &num2[i]);
        
        f1[0] = f2[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f1[i] = f1[i-1] + min(num1[i]*c1, c2); 
        }
        f1[n] = min(f1[n], c3);

        for (int i = 1; i <= m; ++i) {
            f2[i] = f2[i-1] + min(num2[i]*c1, c2); 
        }
        f2[m] = min(f2[m], c3);
        printf("%d\n", min(c4, f1[n]+f2[m]));
    }
    return 0;
}
