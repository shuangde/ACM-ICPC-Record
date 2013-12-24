
/*
ID: zengshu1
PROG: beads
LANG: C++
 */

// Section 1.1 Broken Necklace

/*
你有一条由N个红色的，白色的，或蓝色的珠子组成的项链(3<=N<=350)，珠子是随意安排的。
 r代表红色的珠子,b代表蓝色的珠子,w代表白色的珠子, 假如你要在一些点打破项链,展开成一条直线，
 然后从一端开始收集同颜色的珠子直到你遇到一个不同的颜色珠子，在另一端做同样的事。
 (颜色可能与在这之前收集的不同) 确定应该在哪里打破项链来收集到最大多数的数目的子。 
注意，当收集珠子的时候，一个被遇到的白色珠子可以被当做红色也可以被当做蓝色。 

思路：直接枚举位置，然后暴力。暴力时分别枚举让白色珠子变成红色和蓝色的情况
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#define FIN(x) freopen(x, "r", stdin)
#define FOUT(x) freopen(x, "w", stdout)
using namespace std;

char str[4000];
int n;
char w;

char color(char c) {
	if (c != 'w') return c;
	return w;
}

int moveLeft(int i) {
	while (i > 0 && color(str[i]) == color(str[i-1])) --i;
	return i;
}
int moveRight(int i) {
	while (i < 3*n-1 && color(str[i]) == color(str[i+1])) ++i;
	return i;
}

int main () {

	//FIN("beads.in");
	//FOUT("beads.out");

	scanf("%d", &n);
	scanf("%s", str+n);
	for (int i = 0; i < n; ++i) str[i] = str[i+n];
	for (int i = 2*n; i < 3*n; ++i) str[i] = str[i-n];
	str[3*n] = '\0';

	int ans = 2;
	for (int i = n-2; i < 2*n-1; ++i) {
		int l = 1, r = 1;
		w = 'b'; 
		l = max(l, i - moveLeft(i) + 1);
		r = max(r, moveRight(i+1) - i);
		w = 'r'; 
		l = max(l, i - moveLeft(i) + 1);
		r = max(r, moveRight(i+1) - i);
		ans = max(ans, min(n, l+r));
	}
	printf("%d\n", ans);
	return 0;
}


/*
Here are the test data inputs:

29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb

3
rrr

77
rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr

17
wwwwwwwwwwwwwwwww

50
bbrrrbrrrrrrrrbrbbbrbrrbrrrrbbbrbrbbbbbrbrrrbbrbbb

8
rrwwwwbb

200
rrrrrrrrrrrrrrrrrrrrbbbbbbbbbbbbbbbbbbbbrrrrrrrrrrrrrrrrrrrrbbbbbbbbbbbbbbbbbbbbrrrrrrrrrrrrrrrrrrrrbbbbbbbbbbbbbbbbbbbbrrrrrrrrrrrrrrrrrrrrbbbbbbbbbbbbbbbbbbbbrrrrrrrrrrrrrrrrrrrrbbbbbbbbbbbbbbbbbbbb

350
rrbbrbbbwbwwbwbbbbwwrrbbwbrwbrwbbbrbrwrwbrwwwrrbbrrwrbbrwbwrwwwrbrwwwwwrwbwwwrrbrrbbbrbrbbbrbbbrbbwbbbbbrbrrbrwwbrrrrwbwrwrbbwbwrbrbrwwbrrbwbrwwbwwwbrbwrwbwbrbbbwrbwwrrrbwbwbbbbbrrwwwrbrwwrbbwrbbrbbrbwrrwwbrrrbrwbrwwrbwbwrrrbwrwrrbrbbwrwrbrwwwrwbwrrwwwwrrrwrrwbbwrwwrwrbwwbwrrrrbbwrbbrbwwwwwbrbbrbbrbrwbbwbwwbbbbbwwwrbwwbbbwrwwbbrrwrwbwrrwwwrrrwrrwww

333
rwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwb

*/
