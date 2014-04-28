#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long mod = (1e9)+7;

double a[1010], b[1010];

int main(){
    int k1, k2, maxx = 0;
    scanf("%d", &k1);
  for (int i = 0; i < k1; ++i) {
        int x; double y;
        scanf("%d%lf", &x, &y);
        a[x] = y;
        maxx = max(maxx, x);
  }

 scanf("%d", &k2);
  for (int i = 0; i < k2; ++i) {
        int x; double y;
        scanf("%d%lf", &x, &y);
        b[x] = y;
        maxx = max(maxx, x);
  }
    int cnt = 0;
  for (int i = 0; i <= maxx; ++i) {
        a[i] += b[i];
        if (a[i] != 0) ++cnt;
  }
    printf("%d", cnt);
    for (int i = maxx; i >= 0; --i)
        if (a[i]) printf(" %d %.1f", i, a[i]);
  return 0;
}
