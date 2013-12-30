
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

const int N = 100010;
int n, m;
int A[N], ans[N];


int main() {

	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &A[i]);
	vector<PII>q;
	rep(i, m) {
		int x;
		scanf("%d", &x);	
		q.push_back(MP(x-1, i));
	}
	sort(q.begin(), q.end(), greater<PII>());
	set<int>ss;
	int pt = n - 1;
	for (int i = 0; i < m; ++i) {
		while (pt>=0 && pt >= q[i].first) ss.insert(A[pt--]);	
		ans[q[i].second] = ss.size();
	}
	rep(i, m) printf("%d\n", ans[i]);
    return 0;
}
