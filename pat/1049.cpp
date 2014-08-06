
// 找规律
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

LL f[] = {0,1,20,300,4000,50000,600000,
	7000000,80000000,900000000,10000000000};
LL n9[] = {0,9,99,999,9999,99999,999999,9999999,
	99999999,999999999,9999999999, 99999999999};

// 这是用来求f[]数组的方法。f[i]表示1。。。9..9(i个9)的1的数量
int dp(int n) {
	LL f[100];
	f[1] = 1;
	LL num = 9;
	for (int i = 2; i <= 10; ++i) {
		f[i] = 10*f[i-1] + num + 1;
		num = num * 10 + 9;
	}
}

int main() {
	int n;
	while (~scanf("%d", &n)) {

		vector<int>a;
		int m = n;
		while (m) {
			a.push_back(m%10);
			m /= 10;
		}
		reverse(a.begin(), a.end());

		LL ans = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == 0) {

			} else if (a[i] == 1){
				ans += f[a.size()-i-1] + 1;	
				LL tmp = 0;
				for (int j = i + 1; j < a.size(); ++j)
					tmp = tmp * 10 + a[j];
				ans += tmp;
			} else {
				ans += f[a.size()-i-1] + 1;	
				ans += n9[a.size()-i-1];
				ans += f[a.size()-i-1]*(a[i]-1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
