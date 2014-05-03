
// 题意没有描述清楚，只要开始时间在17:00之前就可以进行服务
// 哪怕服务结束时间超过17:00
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;

const double PI  = acos(-1.0);
const double eps = 1e-8;
const int dir4[4][2]={1,0,-1,0,0,1,0,-1};
const int dir8[8][2]={1,0,-1,0,0,1,0,-1,1,-1,1,1,-1,1,-1,-1};
const int INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;

int n, m, k, q;
int pt[1010], cost[1010], queId[1010], ss[1010];
queue<int>que[1010];
priority_queue<PII,vector<PII>, greater<PII> >Q;


int main() {

	scanf("%d%d%d%d", &n, &m, &k, &q);
	
	int cur = 0;
	for (int i = 0; i < k; ++i) { 
		scanf("%d", &pt[i]);
		if (i < n*m) {
			que[i%n].push(i);
			queId[i] = i%n;
			if (i < n) {
				Q.push(MP(pt[i], i));
				ss[i] = 0;
			}
			++cur;
		}
	}

	int tot = -1;
	while (!Q.empty()) {

		PII tmp = Q.top();
		Q.pop();
		if (tot < tmp.first) {
			tot = tmp.first;
		}

		cost[tmp.second] = tot;
		int pos = queId[tmp.second];
		que[pos].pop();

		if (cur < k) {
			que[pos].push(cur);
			queId[cur++] = pos;
		}

		if (!que[pos].empty()) {
			ss[que[pos].front()] = tot;
			Q.push(make_pair(pt[que[pos].front()]+tot, que[pos].front()));
		}
	}

	for (int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		if (ss[x-1] >= 540) puts("Sorry");
		else printf("%02d:%02d\n", 8+cost[x-1]/60, cost[x-1]%60);
	}
	return 0;
}

