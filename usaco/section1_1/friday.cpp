
/*
ID: zengshu1
PROG: friday
LANG: C++
 */
//	Friday the Thirteenth
/*
要求计算1900年1月1日至1900+N-1年12月31日中十三号落在周一到周日的次数，N为正整数且不大于400.
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int nowWeekDay, nowDay, nowMonth, nowYear;

int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapYear(int n) {
	return n%4==0&&n%100!=0 || n%400==0;
}

void add() {
	nowWeekDay = (nowWeekDay+1) % 7;
	++nowDay;
	if(nowDay > mon[nowMonth]+(nowMonth==1 && isLeapYear(nowYear))) nowDay=1, ++nowMonth;
	if (nowMonth == 12) {
		nowMonth = 0;
		++nowYear;
	}
}

int main () {
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int cnt[7] = {0};
	nowYear = 1900, nowMonth = 0, nowWeekDay = 0, nowDay = 1;
	int end = nowYear+n-1;
	while (nowYear <= end) {
		if (nowDay == 13) {
			cnt[nowWeekDay]++;
		}
		add();
	}
	printf("%d %d", cnt[5], cnt[6]);
	for (int i = 0; i < 5; ++i) printf(" %d", cnt[i]);
	puts("");
	return 0;
}

/*
Brute force is a wonderful thing. 400 years is only 4800 months, so it is perfectly practical to just walk along every month of every year, calculating the day of week on which the 13th occurs for each, and incrementing a total counter.

Here are the test data inputs:
1
2
5
13
45
100
256
400
*/
