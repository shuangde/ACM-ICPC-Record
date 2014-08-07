//栈操作
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;

int n, m, k;
int arr[1010];

bool check() {
    stack<int>st;
    int cur = 1;
    int i = 0;
    while (i < m) {
        if (st.size() > n) return false;
        if (st.size() && st.top() == arr[i]) {
            st.pop();
            ++i;
        } else 
            st.push(cur++);
    }
    return st.size() == 0;
}

int main() {

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j)
            scanf("%d", &arr[j]);
        puts(check()?"YES":"NO");
    }
    return 0;
}

