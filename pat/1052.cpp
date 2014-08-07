// 排序
// 注意给出的n个结点可能不是同一个链表的，所以要从head开始
// 手动把链表走一遍存下来再排序
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#define MP make_pair
#define PB push_back
#define SQ(x) ((x)*(x))
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;

const int N = 100010;
map<string,int>mp;

struct Node {
    char addr[6];
    int key;
    char next[6];
    bool operator < (const Node &rhs) const {
        return key < rhs.key; 
    }
};
Node list[N];

int main () {
    int n;
    char head[6];
    scanf("%d%s", &n, head);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%s",list[i].addr, &list[i].key, list[i].next);
        mp[list[i].addr] = i;
    }
    vector<Node>vt;

    while (head[0] != '-') {
        int pt = mp[head];
        vt.PB(list[pt]);
        strcpy(head, list[pt].next);
    }

    sort(vt.begin(), vt.end());
    if (vt.size() == 0) {
        puts("0 -1");
        return 0;
    }
    printf("%d %s\n", vt.size(), vt[0].addr);
    for (int i = 0; i < vt.size(); ++i) {
        printf("%s %d %s\n", vt[i].addr, vt[i].key,
                i==vt.size()-1?"-1":vt[i+1].addr);
    }
    return 0;
}
