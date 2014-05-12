// shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

char str[20];
int k;
vector<int>num;
int tmp[1000];

void out() {
	for (int j = num.size()-1; j >= 0; --j)
		printf("%d", num[j]);
	putchar('\n');
}

void add() {
	copy(num.begin(), num.end(), tmp);
	for (int i = 0; i < num.size(); ++i) 
		num[i] += tmp[num.size()-1-i];
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] >= 10) {
			if (i+1==num.size()) num.push_back(num[i]/10);
			else num[i+1] += num[i]/10;
			num[i] %= 10;
		}	
	}
}

bool check() {
	for (int i = 0; i <= num.size()/2; ++i) 
		if (num[i] != num[num.size()-1-i]) return false;
	return true;
}

int main() {

	scanf("%s%d", str, &k);
	for (int i = 0; str[i] ; ++i) 
		num.push_back(str[i]-'0');

	int i = 0;
	while (!check() && i < k) {
		add();
		++i;
	}

	out();
	printf("%d\n", i);

	return 0;
}
