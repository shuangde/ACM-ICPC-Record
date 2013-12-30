
// D. Preparing for the Contest,  贪心+优先队列+二分
// 题意:
// 有m只病毒，每只病毒的破坏值为ai, 要雇佣n个人去杀死这些病毒，每个人的费用位ci,
// 同时，每个人还有一个武力值bi，只有当bi>=ai时，这个人才能杀死那只病毒。
// 每个人一天只能杀死一只病毒，多个人可以同时一起杀.
// 问不超过s的花费去雇佣这些人，且需要花费的最少天数的方案是什么？

//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <ext/rope>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define asc(a,b) if(a>b)swap(a,b)
#define des(a,b) if(a<b)swap(a,b)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;
using namespace __gnu_cxx;

typedef pair<int, int >PII;
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;

int n, m, s;
int who[100010], tmpWho[100010];

struct Node {
	int val, cost, pos;
	bool operator<(const Node& rhs) const {
		return cost > rhs.cost;	
	}
};

vector<PII>a;
vector<Node>b;

bool cmp(const Node&lhs, const Node&rhs) {
	return lhs.val > rhs.val;
}

bool ok(int t, int * who) {
	priority_queue<Node>Q;
	priority_queue<PII,vector<PII>,greater<PII> >ans;
	int pt = 0, used = 0;
	for (int i = m - 1; i >= 0; --i) {
		while (pt<n && b[pt].val >= a[i].first) {
			Q.push(b[pt++]);
		}
		if (ans.size() && ans.top().first < t) {
			PII x = ans.top(); ans.pop();
			who[a[i].second] = x.second;
			x.first++;
			ans.push(x);

		} else {
			if (Q.empty()) return false;
			Node tmp = Q.top(); Q.pop();
			if (tmp.cost + used > s) {
				return false;
			} else {
				used += tmp.cost;
				who[a[i].second] = tmp.pos + 1;
				ans.push(MP(1, tmp.pos+1));
			}
		}
	}
	return true;
}

bool solve() {
	bool flag = false;
	int l = 1, r = m;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ok(mid, tmpWho)) {
			flag = true;
			r = mid - 1;
			memcpy(who, tmpWho, sizeof(tmpWho));
		} else l = mid + 1;
	}
	return flag;
}

int main() {

	scanf("%d%d%d", &n, &m, &s);
	rep(i, m) {
		int x; scanf("%d", &x);
		a.PB(MP(x, i));
	}

	rep(i, n) {
		int x; scanf("%d", &x);
		b.PB((Node){x, 0, i});
	}
	rep(i, n) {
		int x; scanf("%d", &x);
		b[i].cost = x;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);

	if (!solve()) puts("NO");
	else {
		puts("YES");
		rep(i, m) printf("%d ", who[i]); 
	}
	return 0;
}
