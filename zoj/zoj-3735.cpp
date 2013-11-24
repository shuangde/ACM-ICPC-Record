#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int m, n;
double mat[130][130];
double f[10010][130];
int v[10010], R;

inline int C3(int n) {
	return n*(n-1)*(n-2)/(2*3);
}
int main () {

	while (~scanf("%d", &m)) {
		R = C3(m);
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < R; ++j)
				scanf("%lf", &mat[i][j]);

		memset(f, 0, sizeof(f));
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &v[i]);
			if (i == 1) {
				for (int j = 0; j < R; ++j)  {
					f[i][j] = mat[j][v[i]];
				}
			} else {
				double maxx = 0;
				for (int j = 0; j < R; ++j) {
					double tmp = f[i-1][j] * mat[j][v[i]];
					f[i][j] = tmp;
					maxx = max(f[i-1][j], maxx);
				}
				f[i][v[i-1]] = max(f[i][v[i-1]], maxx*mat[v[i-1]][v[i]]);
			}
		}
		double ans = 0;
		for (int i = 0; i < R; ++i) ans = max(ans, f[n][i]);
		printf("%.6f\n", ans);
	}
	return 0;
}
