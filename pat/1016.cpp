//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
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

const int N = 1010;

struct Node {
	char name[22];
	char time[15];
	bool state;
	bool operator < (const Node& rhs) const {
		if (strcmp(name, rhs.name)) return strcmp(name,rhs.name) < 0;
		return strcmp(time, rhs.time) < 0;	
	}
}arr[N];

struct Record {
	char start_t[15];
	char end_t[15];
	int tot_time;
	int tot_toll;
};

vector<Record>ans[N];
char record_name[N][22];
int record_month[N];

int n, toll[24*60+10];
bool vis[N];

int getMinutes(char *str) {
	int m, d, hh, mm;
	sscanf(str, "%d:%d:%d:%d", &m, &d, &hh, &mm);
	return d*24*60 + hh * 60 + mm;
}

int dis(char *from, char *to) {
	int sec1 = getMinutes(from), sec2 = getMinutes(to);
	return sec2 - sec1;
}

int cost(char *str) {
	int sec = getMinutes(str);
	int ret = 0;
	int i;
	for (i = 0; i < sec/60; ++i)
		ret += toll[i%24]*60;
	ret += toll[i%24]*(sec%60);
	return ret;
}

int main() {

	for (int i = 0; i < 24; ++i)
		scanf("%d", &toll[i]);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char state[15];
		scanf("%s%s%s", arr[i].name, arr[i].time, state);
		arr[i].state = state[1]=='n' ? 1 : 0;
	}

	sort(arr, arr+n);

	memset(vis, 0, sizeof(vis));

	int idx = 0;
	for (int s = 0; s < n - 1; ++s) {
		if (s && strcmp(arr[s].name, arr[s-1].name)==0) continue;

		int t = s + 1;
		for ( ; t < n && strcmp(arr[t].name, arr[t-1].name)==0; ++t) ;; 

		for (int i = s; i < t - 1; ++i) if (arr[i].state && !arr[i+1].state){
			Record tmp;
			strcpy(tmp.start_t, arr[i].time+3);
			strcpy(tmp.end_t, arr[i+1].time+3);
			tmp.tot_time = dis(arr[i].time, arr[i+1].time);
			tmp.tot_toll = cost(arr[i+1].time) - cost(arr[i].time);
			ans[idx].push_back(tmp);
			++i;
		}
		strcpy(record_name[idx], arr[s].name);
		sscanf(arr[s].time, "%d", &record_month[idx]);
		++idx;
	}

	for (int i = 0; i < idx; ++i) {

		if (ans[i].size() == 0) continue;
		printf("%s %02d\n", record_name[i], record_month[i]);
		int tot = 0;
		for (int j = 0; j < ans[i].size(); ++j) {
			printf("%s %s %d $%.2f\n", ans[i][j].start_t, ans[i][j].end_t, 
					ans[i][j].tot_time, ans[i][j].tot_toll/100.0);
			tot += ans[i][j].tot_toll;	
		}
		printf("Total amount: $%.2f\n", tot/100.0);
	} 

	return 0;
}
