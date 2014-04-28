#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;


int main () {
	
	int a, b;
	scanf("%d%d", &a, &b);
	char str[100];
	sprintf(str, "%d", a+b);
	int len = strlen(str);
	int i = 0;

	if (str[0] == '-') { putchar(str[i++]); }
	bool first = true;
	for ( ; i < len; ++i) {
		if ((len-i)%3==0 && !first) putchar(',');
		first = false;
		putchar(str[i]);
	}
	puts("");

	return 0;
}
