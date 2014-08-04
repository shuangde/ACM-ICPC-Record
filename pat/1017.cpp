#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;

const int N = 10010;
struct Record {
	int t;
	int proc;
	bool operator < (const Record &rhs) const {
		return t < rhs.t;
	}
}arr[N];

int getSec(char *str) {
	int h, m, s;
	sscanf(str,"%d:%d:%d",&h,&m,&s);
	return h*60*60 + m*60 + s;
}

int main () {

	int n, k;
	scanf("%d%d", &n, &k);
	char t[15];
	for (int i = 0; i < n; ++i) {
		scanf("%s%d", t, &arr[i].proc);
		arr[i].proc *= 60;
		arr[i].t = getSec(t) - 60*60*8;
	}

	sort(arr, arr+n);

	priority_queue<int,vector<int>,greater<int> >Q;

	int tot = 0, cnt = 0;
	const int deadLine = (17-8)*60*60;

	for (int i = 0; i < n && arr[i].t <= deadLine; ++i) {
		if (i < k) {
			Q.push(max(0, arr[i].t) + arr[i].proc);	
			if (arr[i].t < 0) tot += -arr[i].t;
			++cnt;
		} else {
			int tmp = Q.top(); Q.pop();
			Q.push(max(tmp, arr[i].t) + arr[i].proc);
			tot += (arr[i].t >= tmp) ? 0 : (tmp - arr[i].t);
			++cnt;
		}
	}

	if (tot) printf("%.1f\n", tot / 60.0 / cnt );
	else puts("0.0");

	return 0;
}

