
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
typedef map<int, int>::iterator iter;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 200010;
int n, m, p;
int a[N];

int main() {

	while (~scanf("%d%d%d", &n, &m, &p)) {
		map<int, int>tar;

		rep(i, n) scanf("%d", &a[i]);	

		rep(i, m) {
			int x; scanf("%d", &x);
			tar[x]++;
		}

		set<int>ans;
		for (int i = 0; i < p; ++i) {
			queue<iter>q;
			for (int j = i; j < n; j += p) {
				iter it = tar.find(a[j]);
				if (it == tar.end()) {
					while(!q.empty()) {
						q.front()->second++;
						q.pop();
					}
				} else if (it->second == 0) {
					while (!q.empty()) {
						q.front()->second++; q.pop();
						if (it->second) break;
					}
					it->second--;
					q.push(it);
				} else {
					it->second--;	
					q.push(it);
				}
				if (q.size() == m) {
					ans.insert(j-p*(m-1)+1);
					q.front()->second++; q.pop();
				}
			} 
			while (!q.empty()) {
				q.front()->second++; q.pop();	
			}
		} 

		printf("%d\n", ans.size());
		for (set<int>::iterator it = ans.begin(); it!=ans.end(); ++it)
			printf("%d " ,*it);
		puts("");
	}
	return 0;
}
