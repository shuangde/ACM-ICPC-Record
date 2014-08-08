//注意n=1的时候
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 5010;
vector<int>prime;
bool vis[N];
void init() {
    int m = sqrt(N+0.5);
    for (int i = 2; i < m; ++i)
        for (int j = i * i; j < N; j+=i) 
            vis[j] = true;
    for (int i = 2;i < N; ++i) 
        if (!vis[i]) prime.PB(i);
}

int main () {
    init();
    LL n;
    cin >> n;
    cout << n << "=";
    if (n==1) {
        cout << 1 << endl; 
        return 0;
    }
    bool first = true;
    for (int i = 0; i < prime.size() && n>0; ++i) {
        if (n%prime[i] == 0) {
            if (first) first = false;
            else putchar('*');
            printf("%d", prime[i]);
            int cnt = 0;
            while (n>0 && n%prime[i] == 0) {
                ++cnt;
                n /= prime[i];
            }
            if (cnt>1)printf("^%d", cnt);
        }
    }
    putchar('\n');
    return 0;
}
