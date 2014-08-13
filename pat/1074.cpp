//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 1000000;
int data[N];
int Next[N];

int main () {
    int head, n, k;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; ++i) {
        int addr, d, nxt;
        scanf("%d%d%d",&addr,&d,&nxt); 
        data[addr] = d;
        Next[addr] = nxt;
    }
    int cnt = 0;
    stack<int>st;
    vector<int>vt;
    while (1) {
        if (st.size() == k) {
            while (!st.empty()) {
                vt.push_back(st.top());
                st.pop();
            }
        }
        if (head == -1) {
            stack<int>st2;
            while (!st.empty()) {
                st2.push(st.top());
                st.pop();
            }
            while (!st2.empty()) {
                vt.push_back(st2.top()); 
                st2.pop();
            }
            break;
        }
        st.push(head);
        head = Next[head];
    }
    for (int i = 0; i < vt.size(); ++i) {
        printf("%05d %d ", vt[i],data[vt[i]]);
        if (i == vt.size()-1) puts("-1");
        else printf("%05d\n", vt[i+1]);
    }
    return 0;
}
