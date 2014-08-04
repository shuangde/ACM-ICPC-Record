// 索引，上下界二分
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,int> PII;
int stu[26*26*26*26+10];
vector<PII>table;

int Hash(char *str) {
	int ret = 0;
	for (int i = 0; i < 3; ++i)
		ret = ret * 26 + str[i] - 'A';	
	return ret * 26 + str[3] - '0';
}

int low(int x) {
	int l = 0, r = table.size(); // 左闭右开
	while (l < r) {
		int m = l + (r-l)/2;	
		if (table[m].first >= x) 
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int up(int x) {
	int l = 0, r = table.size(); // 左闭右开
	while (l < r) {
		int m = l + (r-l)/2;	
		if (table[m].first <= x) 
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int main() {
	int n, k, id = 0;
	memset(stu, -1, sizeof(stu));
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int idx, m;
		scanf("%d%d", &idx, &m);
		for (int j = 0; j < m; ++j) {
			char str[6];
			scanf("%s", str);
			int pt = Hash(str);
			if (stu[pt] == -1) {
				stu[pt] = id++;
			}
			table.push_back(make_pair(stu[pt], idx));
		}
	}

	sort(table.begin(), table.end());

	for (int i = 0; i < n; ++i) {
		char str[6];
		scanf("%s", str);
		int pt = Hash(str);
		if (stu[pt] == -1) {
			printf("%s 0\n", str);
			continue;
		}
		int idx = stu[pt];
		int l = low(idx), r = up(idx);
		printf("%s %d",str, r - l);
		for (int j = l; j < r; ++j)
			printf(" %d", table[j].second);
		puts("");

	}
	return 0;
}
