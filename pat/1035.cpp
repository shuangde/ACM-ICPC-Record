// 简单字符串处理
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define rep(i, n) for(int i=0;i<(n);++i)
using namespace std;

typedef pair<string, string >PII;

char mod[12];

void change(char *pw) {
	for (int i = 0; pw[i]; ++i) {
		mod[i] = pw[i]; 
		if (pw[i]=='1') mod[i] = '@';
		if (pw[i]=='0') mod[i] = '%';
		if (pw[i]=='l') mod[i] = 'L';
		if (pw[i]=='O') mod[i] = 'o';
	}
	mod[strlen(pw)] = '\0';
}

int main() {

	int n;
	scanf("%d", &n);
	char team[12], pw[12];
	bool flag = false;
	vector<PII>ans;
	for (int i = 0; i < n; ++i) {
		scanf("%s%s", team, pw);
		change(pw);
		if (strcmp(pw, mod) != 0) {
			ans.push_back(MP(team, mod));
		}
	}
	if (ans.size() == 0) printf("There %s %d %s and no account is modified", n==1?"is":"are", n, n==1?"account":"accounts");
	else {
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i)	
			cout << ans[i].first << " " << ans[i].second << endl;
	}

    return 0;
}
