
//shuangde
// 进制转换+二分, 有trick点
#include <iostream>
#include <cstdio>
#include <cstring>
#define cmax(a,b) a=max(a, (b))
using namespace std;

typedef long long LL;


LL Dec(char *str, int R) {
	LL ret = 0;
	for (int i = 0; str[i]; ++i) {
		if (isdigit(str[i])) {
			ret = ret * R + str[i] - '0'; 
		} else {
			ret = ret * R + str[i] - 'a' + 10;
		}
	}
	return ret;
}

LL binary(LL target, char* str, LL l, LL r) {
	LL ret = -1;
	while (l <= r) {
		LL m = (l+r) >> 1;
		LL res = Dec(str, m);
		if (res < 0 || res >= target) {
			if (res == target) {
				ret = m;
			}
			r = m - 1;
		} else l = m + 1;
	}
	return ret;
}

LL check(LL target, char* str) {
	int r = 0;
	for (int i = 0; str[i]; ++i) {
		if (isdigit(str[i])) cmax(r, str[i]-'0'+1);
		else cmax(r, str[i]-'a'+11);
	}
	return binary(target, str, r, max(target,(LL)r));
}

int main() {

	char N[2][20], ch[20];
	int tag, radix;

	scanf("%s%s%d%d", N[0], N[1], &tag, &radix);
	if (tag == 2) swap(N[0], N[1]);

	LL r = check(Dec(N[0], radix), N[1]);
	if (r != -1) cout << r;
	else printf("Impossible");

    return 0;
}
