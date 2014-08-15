//哈希二次探测法
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 100000;
vector<int>prime;
bool vis[N+10];
int Hash[N];
int size, n, tSize;

void init() {
    int m = (int)sqrt(N+0.5);
    for (int i = 2; i < m; ++i) {
        for (int j = i*i; j < N; j+=i)
            vis[j] = true;
    }
    for (int i = 2; i < N; ++i)
        if (!vis[i]) prime.push_back(i);
}

int insert(int x) {
    int pos = x % tSize;
    for (int i = 0; i < tSize; ++i) {
        if (Hash[(pos+i*i)%tSize] == -1) {
            Hash[(pos+i*i)%tSize] = x;
            return (pos+i*i)%tSize;
        }
    }
    return -1;
}

int main () {
    init();
    scanf("%d%d", &size,&n);
    tSize = *(lower_bound(prime.begin(),prime.end(), size));
    memset(Hash, -1, sizeof(Hash));
    bool first = true;
    while (n--) {
        int x;
        scanf("%d", &x);
        int res = insert(x);
        printf("%s", first?(first=false,""):" ");
        if (res!=-1) printf("%d", res);
        else printf("-");
    }
    puts("");
    return 0;
}
