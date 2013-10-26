// CF #208 C

//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;
int n;
int cmd[MAXN];
int belong[MAXN];

struct Node {
    int data, id, belong;
    bool operator < (const Node &rhs) const {
        return data > rhs.data;
    }
};
vector<Node>vt;
bool vis[MAXN];
int cnt[MAXN];
int f[MAXN];
int addNum, outNum;
int idx;
stack<int>st;
queue<int>que;
deque<int>dq;

int find(int x) {
    return x==f[x] ? x : f[x]=find(f[x]);
}

void init() {
    for (int i = 0; i <= idx; ++i)
        f[i] = i;
}

int add(int x) {
    if (addNum % 3 == 0) {
        puts("pushStack");
        st.push(x);
    } else if (addNum%3 == 1) {
        puts("pushQueue");
        que.push(x);
    } else if (addNum%3 == 2) {
        puts("pushFront");
        dq.push_back(x);
    }
    ++addNum;
}

void output() {
    printf("%d", min(addNum-outNum, 3));
    for (int i = 0; outNum < addNum && i < 3; ++i) {
        if (outNum%3==0) { printf(" popStack"); st.pop();}
        else if(outNum%3==1) { printf(" popQueue"); que.pop(); }
        else { printf(" popFront"); dq.pop_front(); }
        ++outNum;
    }
    puts("");
}

int main(){

    while (~scanf("%d", &n)) {
        idx = 0;
        vt.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &cmd[i]); 
            if (!cmd[i]) {
                ++idx;
            } else { 
                vt.push_back((Node){cmd[i], i, idx}); 
            }
        }

    
        sort(vt.begin(), vt.end());
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));

        init();
        for (int i = 0; i < vt.size(); ++i) {
            for (int j = vt[i].belong; j < idx; j = find(j+1)) {
                if (cnt[vt[i].belong] < 3) {
                    vis[vt[i].id] = true;
                    ++cnt[vt[i].belong];
                    break;
                } else {
                    f[j] = j + 1; 
                }
            }
        }

        while (!st.empty()) st.pop();
        while (!que.empty()) que.pop();
        while (!que.empty()) dq.pop_front();

        addNum = 0, outNum = 0;
        for (int i = 0; i < n; ++i) {
            if (cmd[i]) {
                if (vis[i]) {
                    add(cmd[i]); 
                } else {
                    dq.push_front(i);
                    puts("pushBack");
                }
            } else {
                output();
            }
        }
    }
    return 0;
}
