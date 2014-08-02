// 遍历 
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
using namespace std;


map<string,int>mp;
map<int,string>name;
int w[2010][2010];
bool vis[2010][2010], gone[2010];
int deg[2010];
int idx;
int n, k;

struct Gang {
	string name;
	int num;
	bool operator < (const Gang& rhs) const {
		return name < rhs.name;	
	}
}; 

int dfs(int u, int& cnt, int& sum, int& head) {
	if (!gone[u])
		++cnt;
	gone[u] = true;
	if (deg[u] > deg[head])
		head = u;
	for (int i = 0; i < idx; ++i) if (!vis[u][i] && w[u][i]>0) {
		vis[u][i] = vis[i][u] = true;;
		sum += w[u][i]; 
		dfs(i, cnt, sum, head);
	}
}

int main() {

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		char str1[5], str2[5];
		int t;
		scanf("%s%s%d", str1, str2, &t);
		if (mp.find(str1) == mp.end()) 
			name[idx]=str1, mp[str1] = idx++;
		if (mp.find(str2) == mp.end())
			name[idx]=str2, mp[str2] = idx++;
		int a = mp[str1], b = mp[str2];
		w[a][b] += t;
		w[b][a] += t;
		deg[a]  += t;
		deg[b]  += t;
	}

	vector<Gang>ans;
	for (int i = 0; i < n; ++i) {
		if (gone[i]) continue;
		int cnt = 0, sum = 0, head = i;
		dfs(i, cnt, sum, head);
		//cout << name[i] << " " << cnt << " " << sum << endl;
		if (cnt > 2 && sum > k)
			ans.push_back((Gang){name[head], cnt});
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].name << " " << ans[i].num << endl;

    return 0;
}
