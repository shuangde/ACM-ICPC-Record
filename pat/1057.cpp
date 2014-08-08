//树状数组+二分
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
typedef long long int64;

const int N = 100010;
int c[N], n;
stack<int>st;

inline int lowbit(int x) {return x&(-x);}
void add(int x, int data) {
    while (x < N) {
        c[x] += data;
        x += lowbit(x);
    }
}
int sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
int getMedian() {
    int l = 0, r = N - 1;
    int tot = sum(r);
    int tar = tot%2==0?tot/2:(tot+1)/2;
    while (l < r) {
        int m = l + (r-l)/2;
        int tmp = sum(m);
        if (tmp < tar) l = m + 1;
        else r = m;
    }
    return l;
}

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        char cmd[15];
        scanf("%s", cmd);
        if (cmd[1] == 'o') { // pop
            if (st.size() > 0) {
                printf("%d\n", st.top());
                add(st.top(), -1);
                st.pop();
            } else {
                puts("Invalid"); 
            }
        } else if (cmd[1] == 'u') {// push
            int x;
            scanf("%d", &x);
            st.push(x);
            add(x, 1);
        } else { // peekMedian
            if (st.size() == 0) {
                puts("Invalid"); 
            } else {
                printf("%d\n", getMedian());
            }
        }
    }
    return 0;
}
