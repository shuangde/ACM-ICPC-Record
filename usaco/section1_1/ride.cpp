/*
ID: zengshu1
PROG: ride
LANG: C++
 */

/*
Section 1.1	PROB: Your Ride Is Here
题意： 给两个字符串，每个字符串的值定义为：(s[0]-'A'+1) * (s[1]-'A'+1) * ....*(s[len-1]-'A'+1)
	  如果两个字符串的值取模46相等，就输出"GO", 否则输出"STAY"
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	char str1[200], str2[200];
	while (~scanf("%s%s", str1, str2)) {
		int sum1 = 1, sum2 = 1;
		for (int i = 0; str1[i]; ++i) sum1 *= (str1[i] - 'A' + 1);
		for (int i = 0; str2[i]; ++i) sum2 *= (str2[i] - 'A' + 1);
		if (sum1 % 47 == sum2 % 47) {
			puts("GO");
		} else {
			puts("STAY");
		}
	}
	return 0;
}

/*
data input:

------- test 1 ----
COMETQ
HVNGAT
------- test 2 ----
STARAB
USACO
------- test 3 ----
EARTH
LEFTB
------- test 4 ----
PULSAR
VENUS
------- test 5 ----
KANSAS
UTAH
------- test 6 ----
APPLE
URSA
------- test 7 ----
MSFT
MARS
------- test 8 ----
PLUTO
BKHOLE
------- test 9 ----
COWSBC
RIGHT
------- test 10 ----
DRKMTR
SNIKER
*/
