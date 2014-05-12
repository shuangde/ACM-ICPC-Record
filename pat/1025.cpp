
//shuangde
// 简单排序，需要注意registration id用字符串
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long LL;

struct Node {
	//LL id;	
	string id;
	int score;
	int finalRank;
	int localRank;
	int loc;
	bool operator < (const Node& rhs) const {
		if (score != rhs.score) return score > rhs.score;
		return id < rhs.id;
	}
};
vector<Node>vt;

int main() {

	int n, k, tot = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		tot += k;
		vector<Node>loc;
		for (int j = 0; j < k; ++j) {
			Node tmp;
			cin >> tmp.id;
			scanf("%d", &tmp.score);	
			tmp.loc = i + 1;
			loc.push_back(tmp);
		}
		sort(loc.begin(), loc.end());
		for (int j = 0; j < k; ++j) {
			loc[j].localRank = (j==0 ? 1 :
					(loc[j].score==loc[j-1].score?loc[j-1].localRank:j+1));
			vt.push_back(loc[j]);
			//printf("%lld %d %d\n", loc[j].id, loc[j].score, loc[j].localRank);
		}
	}
	sort(vt.begin(), vt.end());
	printf("%d\n", tot);
	for (int i = 0; i < vt.size(); ++i) {
		vt[i].finalRank = (i==0 ? 1 :
				(vt[i].score==vt[i-1].score?vt[i-1].finalRank:i+1));
		cout << vt[i].id;
		printf(" %d %d %d\n", vt[i].finalRank, vt[i].loc, vt[i].localRank);
	}
	return 0;
}

