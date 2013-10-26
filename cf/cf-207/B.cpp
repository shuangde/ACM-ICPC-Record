#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+10;
int n, m;

int d[N][3];
int cnt[N];
int col[N];

int add(int x) {
    return (x+1)%3;
}

int main () {

    int x, y, z;
    while (~scanf("%d %d", &n, &m)) {

        memset(cnt, 0, sizeof(cnt));
        memset(col, -1, sizeof(col));

        int x, y, z;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &z); 
            if (col[x]==-1 && col[y]==-1 && col[z]==-1) {
                col[x] = 0; col[y] = 1; col[z] = 2; 
            } else if (col[x]==-1 && col[y]==-1) {
                col[x] = add(col[z]);
                col[y] = add(col[x]);
            } else if (col[x]==-1 && col[z] == -1) {
                col[x] = add(col[y]);
                col[z] = add(col[x]);
            } else if (col[y]==-1 && col[z]==-1) {
                col[y] = add(col[x]);
                col[z] = add(col[y]);
            }
        }
        printf("%d", col[1]+1);
        for (int i = 2; i <= n; ++i) {
            printf(" %d", col[i]+1); 
        }
        puts("");
    }
    return 0;
}
