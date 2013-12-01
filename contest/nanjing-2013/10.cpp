
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

int main() {

	int64 a[3];
	while (cin >> a[0] >> a[1] >> a[2]) {
		sort(a, a+3);

		if (a[0]==0 && a[1] == 0) {
			// 0 0 x
			if (a[2] <= 1) printf("0\n");
			else if (a[2] == 2) printf("1\n");
			else cout << 1+(a[2]-2)*2 << endl;

		} else if (a[0] == 0 && a[1] == 1){
			// 0 1 x
			if (a[2] == 1) printf("1\n"); 
			else if (a[2] == 2) printf("3\n");
			else cout << 3+(a[2]-2)*3 << endl;

		} else if (a[0] == 0 && a[1] > 1) {
			// 0 2 2
			cout << 6 + (a[0]+a[1]+a[2]-4) * 4 << endl;

		} else if (a[0] == 1 && a[1] == 1){
			// 1 1 x
			if (a[2] == 1) puts("3");
			else if (a[2] == 2) puts("6");
			else cout << 6+(a[2]-2)*4<<endl;

		} else if (a[0] == 1 && a[1] == 2) {
			// 1 2 x
			if (a[2] == 2) puts("10");
			else cout << 10+(a[2]-2)*5 << endl;

		} else if (a[0] == 1 && a[1] > 2){
			// 1 3 x
			cout << 10 + (a[0]+a[1]+a[2]-5) * 5 << endl;

		} else {
			// 2 2 2
			cout << 15+(a[0]+a[1]+a[2]-6)*6 << endl;
		}
	}
    return 0;
}
