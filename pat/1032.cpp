// shuangde
// 最长后缀
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <stack>
using namespace std;


int dir[1000002];


int main () {
	int addr1, addr2;
	int n;
	cin >> addr1 >> addr2 >> n;
	for (int i = 0; i < n; ++i) {
		char str[110];
		int ad1, ad2;
		scanf("%d%s%d",&ad1,str,&ad2);
		dir[ad1] = ad2;
	}
	stack<int>st1, st2;
	st1.push(addr1);
	st2.push(addr2);
	while (addr1 != -1) {
		st1.push(addr1);
		addr1 = dir[addr1];
	}
	while (addr2 != -1) {
		st2.push(addr2);
		addr2 = dir[addr2];
	}
	int ans = -1;
	while (!st1.empty() && !st2.empty()) {
		if (st1.top() == st2.top()) {
			ans = st1.top();
			st1.pop();
			st2.pop();
		} else 
			break;
	}
	if(ans != -1)printf("%05d\n", ans);
	else puts("-1");
	return 0;
}
