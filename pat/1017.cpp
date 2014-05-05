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
//	printf("%02d:%02d:%02d\n", h, m, s);
	return h*60*60 + m*60 + s;
}

void print(int x) {
	x += 8*60*60;
	printf("%02d:%02d:%02d ", x/3600, (x/60)%60, x%60);
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
	//for (int i = 0; i < n; ++i) printf("%d %d\n", arr[i].t, arr[i].proc);
 
	priority_queue<int,vector<int>,greater<int> >Q;

	int now = 0, tot = 0, cnt = 0;
	for (int i = 0; i < n && arr[i].t <= (17-8)*60*60;  ) {
		if (arr[i].proc > 3600){ ++i; continue; }
		if (now < arr[i].t) { 
			if (!Q.empty()) { 
				int tmp = Q.top();
				Q.pop();
				if (tmp > now) now = tmp;
			} else {
				now = arr[i].t;
				Q.push(now + arr[i].proc);
				//print(now); print(now+arr[i].proc); puts("");
				++cnt;
				++i;
			}
		} else { 
			if (Q.size() < k) {
				Q.push(now+arr[i].proc);
				tot += now - arr[i].t;
				print(now); print(now+arr[i].proc); puts("");
				++cnt;
				++i;
			} else {
				int tmp = Q.top();
				Q.pop();
				if (tmp > now) now = tmp;
			}
		}
	}

	printf("%.1f\n", tot / 60.0 / cnt );
	
	return 0;
}
