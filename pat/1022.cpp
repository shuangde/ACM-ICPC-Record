//shuangde
// STL的运用
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;

map<string, set<string> >list[5];
char str[820], id[12];

int main() {

	int n, m;
	scanf("%d%*c", &n);
	for (int i = 0; i < n; ++i) {
		int y; 
		// id
		gets(id);
		// title
		gets(str);
		list[0][str].insert(id);
		// author
		gets(str);
		list[1][str].insert(id);
		// keyword
		char ch;
		do {
			int idx = 0;
			while (ch = getchar()) {
				if (ch == ' ' || ch == '\n') break;
				str[idx++] = ch;
			}
			str[idx] = '\0';
			list[2][str].insert(id);
		} while (ch != '\n');
		// publisher
		gets(str);
		list[3][str].insert(id);
		// year
		gets(str);
		list[4][str].insert(id);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int idx; scanf("%d: ", &idx); idx--;
		gets(str);
		printf("%d: %s\n", idx+1, str);
		map<string,set<string> >::iterator map_it = list[idx].find(str);
		if (map_it == list[idx].end()) {
			puts("Not Found");
			continue;
		} 
		set<string> &ss = map_it->second;
		if (ss.size() == 0) {
			puts("Not Found");
			continue;
		}
		for (set<string>::iterator it = ss.begin(); it!=ss.end(); ++it){
			cout << *it << endl;
		}
	}
    return 0;
}
