#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int>num;

bool solve(int n, int d) {
	num.clear();	
	while (n > 0) {
		num.push_back(n%d);
		n /= d;
	}
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] != num[num.size()-1-i]) return false;
	}
	return true;
}


int main () {

	int n, d;
	scanf("%d%d", &n, &d);
	if (n == 0) {
		printf("Yes\n0\n");
		return 0;
	}
	printf("%s\n", solve(n, d) ? "Yes" : "No");
	for (int i = num.size()-1; i >= 0; --i) {
		printf("%d", num[i]);
		if (i) putchar(' ');
	}
	return 0;
}
