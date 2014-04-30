//shuangde
// trick点： 并列排名的情况，例如有3个人，前两个人并列第一，那么第3人排名第三
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Node {
	int id;
	int c, m, e, a;
}arr[2010];

int ranks[1000010], course[1000010];

bool cmpA(const Node& a, const Node& b) {
	return a.a > b.a;
}
bool cmpC(const Node& a, const Node& b) {
	return a.c > b.c;
}
bool cmpM(const Node& a, const Node& b) {
	return a.m > b.m;
}
bool cmpE(const Node& a, const Node& b) {
	return a.e > b.e;
}
int getMark(Node& a, char ch) {
	if (ch == 'A') return a.a;
	else if (ch == 'C') return a.c;
	else if (ch == 'M') return a.m;
	else return a.e;
}

void update(int n, bool (*cmp)(const Node& a, const Node& b), const char ch) {
	sort(arr, arr+n, cmp);
	int rk = -1;
	for (int i = 0; i < n; ++i) {
		int id = arr[i].id;
		if (rk == -1) rk = 1;
		else if (getMark(arr[i],ch) != getMark(arr[i-1], ch)) rk = i + 1;
		if (ranks[id] > rk) {
			ranks[id] = rk;
			course[id] = ch;
		}
	}
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	memset(ranks, INF, sizeof(ranks));
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &arr[i].id, &arr[i].c, &arr[i].m, &arr[i].e);
		arr[i].a = arr[i].c+arr[i].m+arr[i].e;
	}
	update(n, cmpA, 'A');
	update(n, cmpC, 'C');
	update(n, cmpM, 'M');
	update(n, cmpE, 'E');
	for (int i = 0; i < m; ++i) {
		int id; 
		scanf("%d", &id);
		if (ranks[id] == INF) puts("N/A");
		else printf("%d %c\n", ranks[id], course[id]);
	}

    return 0;
}
