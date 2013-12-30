
// D. Table with Letters - 2
// 给个n*m的小写字母矩阵
// 问有多少个子矩阵满足：
// 子矩阵的四个角的字母都相同，且子矩阵里的字母'a'的个数不超过k

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

const int N = 410;
int n, m, limit;
char mat[N][N];
int sum[N][N];

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (~scanf("%d%d%d", &n, &m, &limit)) {

		memset(sum, 0, sizeof(sum));
		ff(i, n) {
			scanf("%s", mat[i]+1);
			ff(j, m) {
				sum[i][j] = sum[i-1][j] + (sum[i][j-1]-sum[i-1][j-1]) + (mat[i][j]=='a');
			}
		}

		int64 ans = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = i+1; j <= n; ++j) {

				vector<int>vt[27];
				for (int k = 1; k <= m; ++k) 
					if (mat[i][k] == mat[j][k]) {
						vt[mat[i][k]-'a'].push_back(k);
					}

				for (int k = 0; k < 26; ++k) if (vt[k].size() >= 2) {

					for (int p = 0; p < vt[k].size()-1; ++p) {

						int l = p, r = vt[k].size() - 1, mark = -1, aa;

						while (l <= r) {
							int m = l + r>>1;
							int tot = (sum[j][vt[k][m]]-sum[j][vt[k][p]-1])
									- (sum[i-1][vt[k][m]]-sum[i-1][vt[k][p]-1]);

							if (tot <= limit) {
								aa = tot;
								mark = m; l = m + 1;
							} else r = m - 1;
						}

						if (mark != -1) {
				//			printf("%d %d %d %d tot=%d\n", i, j, vt[k][p], vt[k][mark], aa);
							ans	+= mark - p;
						}
					}
				}
			}	
		}
		cout << ans << endl;
	}
	return 0;
}
