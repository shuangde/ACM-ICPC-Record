
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 10010;
char S1[N], S2[N];
bool vis[1000];

int main() {

	gets(S1);
	gets(S2);
	for (int i = 0; S2[i]; ++i)
		vis[S2[i]] = true;
	for (int i = 0; S1[i]; ++i) {
		if (!vis[S1[i]]) 
			putchar(S1[i]);
	}

    return 0;
}
