// 水题
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
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

struct Item {
	string name;
	string gender;
	string id;
	int grade;
};

int main() {

	int n;
	scanf("%d", &n);

	Item boy, girl;
	boy.grade = 101, girl.grade = -1;

	for (int i = 0; i < n; ++i) {
		Item tmp;
		cin >> tmp.name >> tmp.gender >> tmp.id >> tmp.grade;
		if (tmp.gender[0]=='F') {
			if (tmp.grade > girl.grade)
				girl = tmp;
		} else {
			if (tmp.grade < boy.grade)
				boy = tmp;
		}
	}

	if (girl.grade == -1) puts("Absent");
	else cout << girl.name << " " << girl.id << endl;
	if (boy.grade == 101) puts("Absent");
	else cout << boy.name << " " << boy.id << endl;
	if (girl.grade == -1 || boy.grade == 101)
		cout << "NA";
	else printf("%d\n", girl.grade-boy.grade);
    return 0;
}
