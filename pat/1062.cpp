//排序
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
const int N = 100010;

int n, l, h;
struct Node {
    int id, vir, tal;
    int rank; //3圣人，2君子，1愚人，0,小人
    bool operator<(const Node& rhs) const {
        if (rank != rhs.rank) return rank > rhs.rank; 
        if (vir+tal!=rhs.vir+rhs.tal) return vir+tal>rhs.vir+rhs.tal;
        if (vir != rhs.vir) return vir > rhs.vir;
        return id < rhs.id;
    }
};
vector<Node>vt;

int main () {
    scanf("%d%d%d", &n,&l,&h);
    for (int i = 0; i < n; ++i) {
        int id, vir, tal;
        scanf("%d%d%d", &id,&vir,&tal);
        if (vir>=l&&tal>=l) {
            vt.PB((Node){id,vir,tal});
            if (vir>=h&&tal>=h) {
                vt[vt.size()-1].rank = 3; 
            } else if (vir>=h&&tal<h) {
                vt[vt.size()-1].rank = 2; 
            } else if (vir<h&&tal<h) {
                if (vir>=tal)
                    vt[vt.size()-1].rank = 1; 
                else
                    vt[vt.size()-1].rank = 0; 
            }
        }
    }
    sort(vt.begin(), vt.end());
    printf("%d\n", vt.size());
    for (int i = 0; i < vt.size(); ++i)
        printf("%08d %d %d\n", vt[i].id, vt[i].vir, vt[i].tal);
    return 0;
}
