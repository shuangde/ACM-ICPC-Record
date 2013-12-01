#include <cstdio>
#include <vector>
using namespace std;
#define N 1000001
#define F first
#define S second
#define mp make_pair
int bit[N], leftCnt[N], res[N];
vector<int> query[N], use[N], kill[N];

inline int lowbit(int x) {return x&(-x);}

void add(int x, int data){
	while (x < N){
		bit[x] += data;
		x += x&-x;
	}
}

int sum(int x){
	int ret = 0;
	while (x > 0){
		ret += bit[x];
		x -= lowbit(x);
	}
	return ret;
}


int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		leftCnt[a]++; 
		if (b+1 < N) kill[b+1].push_back(a); // 以b为右端点的左端点
	}

	for (int i = 0; i < m; ++i) {
		int k; scanf("%d", &k);
		query[i].push_back(0);
		for (int j = 0; j < k; ++j){
			int a; scanf("%d", &a);
			query[i].push_back(a);
			use[a].push_back(i);
		}
	}

	for (int i = 1; i < N; ++i) {
		add(i, leftCnt[i]); // 左端点
		for (int j = 0; j < kill[i].size(); ++j)
			add(kill[i][j], -1);
		for (int j = 0; j < use[i].size(); ++j) {
			int k = use[i][j];
			int a = *(--lower_bound(query[k].begin(), query[k].end(), i));
			res[k] += sum(i) - sum(a);
		}
	}

	for (int i = 0; i < m; ++i) 
		printf("%d\n", res[i]);

	return 0;
}
