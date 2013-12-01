/*
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
#define SQ ((x)*(x))
#define CLR(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=max(a, (b))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

double miny[20], maxx[20];

int main() {

int x;
double y;

while (~scanf("%d%lf", &x, &y)) {
double tmp = y, tmp2 = y+0.9999999;

if (x==1) {
printf("%d\n", (int)y-1);
continue;
}

miny[x] = y;
for (int n = x; n >= 2; --n) {
tmp =  tmp * (n-1) / n;
tmp2 = tmp2 * (n-1) / n;
miny[n-1] = tmp;
maxx[n-1] = tmp2;
//			printf("%d: %lf\n", n-1, miny[n-1]);
}
if (maxx[1] < 1.0) {
printf("-1\n");
continue;
}
int cnt = 0;
double ave = 1, now = 1;
for (int i = 1; i <= x; ++i) {
if (i > 1) ++cnt;
if ((int)(now) < (int)miny[i]) {
cnt += (int)miny[i] - (int)now;
now = (int)miny[i];
ave = now*1.0 / i;
}
if ( (int)(now + ave) < (int)miny[i+1] ) {
double tmpNow = (int)miny[i] + 1;
double tmpAve = tmpNow * 1.0 / i;
if ((int)(tmpNow + tmpAve * (x-i)) <= (int)y) {
++cnt;
now = (int)miny[i] + 1;
ave = now*1.0 / i;
}
}
if (i != x)now += ave;
}

printf("%d\n", cnt);
}
return 0;
}
*/
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const double eps=1e-9;
int dcmp(double x){
	if(fabs(x)<eps) return 0;
	else return x<0? -1:1;
}
int main(){
	int x,ty;
	double y;
	while(~scanf("%d%d",&x,&ty)){
		int tempx=1;
		double tempy=1;
		int ans=0;
		if(ty<x){
			puts("-1");
			continue;
		}
		y=ty+0.99999999;
		while(tempx!=x){
			int hehe=y/x*tempx-tempy;
			
			tempy+=hehe;
			ans+=hehe;
			tempx++;
			ans++;
			tempy=tempy/(tempx-1)*tempx;
		}
		ans+=(int )y - (int) tempy;
		printf("%d\n",ans);
	}
	return 0;
}
