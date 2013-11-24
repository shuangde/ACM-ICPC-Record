#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
#include <string>
using namespace std;

//typedef char State[25];
typedef string State;

int n;
State start;

int next[6][24] = {
	{20,1,22,3,10,4,0,7,8,9,11,5,2,13,14,15,6,17,12,19,16,21,18,23},
	{6,1,12,3,5,11,16,7,8,9,4,10,18,13,14,15,20,17,22,19,0,21,2,23},
	{1,3,0,2,23,22,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20,21,9,8},
	{2,0,3,1,6,7,8,9,23,22,10,11,12,13,14,15,16,17,18,19,20,21,5,4},
	{0,1,11,5,4,16,12,6,2,9,10,17,13,7,3,15,14,8,18,19,20,21,22,23},
	{0,1,8,14,4,3,7,13,17,9,10,2,6,12,16,15,5,11,18,19,20,21,22,23},
};

int color[25];
int count(State& st) {
	int cnt = 0;
	if (color[st[0]-'A']==color[st[1]-'A'] && 
			color[st[1]-'A']==color[st[2]-'A'] &&
			color[st[2]-'A']==color[st[3]-'A']) ++cnt;
	if (color[st[4]-'A']==color[st[5]-'A'] &&
			color[st[5]-'A']==color[st[10]-'A'] &&
			color[st[10]-'A']==color[st[11]-'A']) ++cnt;
	if (color[st[6]-'A']==color[st[7]-'A'] &&
			color[st[7]-'A']==color[st[12]-'A'] &&
			color[st[12]-'A']==color[st[13]-'A']) ++cnt;
	if (color[st[8]-'A']==color[st[9]-'A'] &&
			color[st[9]-'A']==color[st[14]-'A'] &&
			color[st[14]-'A']==color[st[15]-'A']) ++cnt;
	if (color[st[16]-'A']==color[st[17]-'A'] &&
			color[st[17]-'A']==color[st[18]-'A'] &&
			color[st[18]-'A']==color[st[19]-'A']) ++cnt;
	if (color[st[20]-'A']==color[st[21]-'A'] &&
			color[st[21]-'A']==color[st[22]-'A'] &&
			color[st[22]-'A']==color[st[23]-'A']) ++cnt;
	return cnt;
}

typedef pair<string, int>PII;
#define MP make_pair

void col_1_up(State& st) {
	char tmp1 = st[0], tmp2 = st[2];
	st[0] = st[6];  st[2] = st[12];
	st[6] = st[16]; st[12] = st[18];
	st[20] = tmp1;  st[22] = tmp2;
}


int bfs() {
	queue<PII>Q;
	string sta; 
	for(int i = 0; i < 24; ++i) sta+='A'+i;
	Q.push(MP(sta, 0));

	char str[25];
	for (int i = 0; i < 24; ++i) str[next[1][i]] = sta[i];
	str[24] = 0;

	int ret = count(sta);

	while (!Q.empty()) {
		PII x = Q.front(); Q.pop();
		if (x.second >= n) continue;
		for (int i = 0; i < 6; ++i) {
			char str[28];
			for (int j = 0; j < 24; ++j) str[next[i][j]] = x.first[j];
			str[24] = 0; string a = str;
			ret = max(ret, count(a));
			Q.push(MP(str, x.second+1));
		}
	} 
	return ret;
}

int main () {


	while (~scanf("%d", &n)) {

		for (int i = 0; i < 24; ++i)
			scanf("%d", &color[i]);

		cout << bfs() << endl;
	}
	return 0;
}
