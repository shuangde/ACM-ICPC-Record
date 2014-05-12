// shuangde
// 简单进制转换
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

void out(int x) {
	vector<int>num;
	while (x > 0) {
		num.push_back(x%13);
		x /= 13;
	}
	for (int i = num.size(); i < 2; ++i)
		num.push_back(0);
	for (int i = num.size()-1; i >= 0; --i) {
		if (num[i] < 10) printf("%d", num[i]);	
		else if (num[i]==10) putchar('A');
		else if (num[i]==11) putchar('B');
		else if (num[i]==12) putchar('C');
	}
}

int main() {

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("#");
	out(a);out(b);out(c);
    return 0;
}
