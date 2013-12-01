
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

struct Node {
	int id, year, mon, day;
	bool operator < (const Node& rhs) const {
		if (year != rhs.year) return year < rhs.year;
		if (mon != rhs.mon) return mon < rhs.mon;
		return day < rhs.day;
	}
}arr[110];

string name[110];

int main() {

	int n;
	while (~scanf("%d", &n)) {
		rep(i, n) {
			int day, mon, year;
			cin >> name[i] >> arr[i].day >> arr[i].mon >> arr[i].year;
			arr[i].id = i;
		}
		sort(arr, arr+n);
		cout << name[arr[n-1].id] << "\n" << name[arr[0].id] << "\n";
	}
    return 0;
}
