//剪枝，题目最多给10W个数据，但是每次询问要求最多输出最大的m(m<=100)
//所以每个年龄最多保留100个即可，总共有200*100=2W个有用数据
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
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
int n, k;
struct Node {
    char name[9];
    int age;
    int worth;
    bool operator < (const Node& rhs) const {
        if (worth != rhs.worth) return worth > rhs.worth;
        if (age != rhs.age) return age < rhs.age;
        return strcmp(name, rhs.name) < 0;
    }
}arr[N];
vector<int>vt;
vector<int>adj[210];
vector<int>ans[1010];
int used[210];
int cnt[1010];
bool vis[1010];

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%s%d%d", arr[i].name,&arr[i].age,&arr[i].worth);
    sort(arr, arr+n);
    for (int i = 0; i < n; ++i) {
        ++used[arr[i].age];
        if (used[arr[i].age] > 100) continue;
        vt.PB(i);
    }
    for (int i = 0; i < k; ++i) {
        int m, a, b;
        scanf("%d%d%d", &m, &a, &b);
        cnt[i] = m;
        ans[i].reserve(m);
        for (int j = a; j <= b; ++j)
            adj[j].PB(i);
    }
    int finish = 0;
    for (int x = 0; x < vt.size(); ++x) {
        int i = vt[x];
        int age = arr[i].age;
        if (finish == k) break;
        for (int j = 0; j < adj[age].size(); ++j) {
            int v = adj[age][j]; 
            if (vis[v]) continue;
            ans[v].PB(i);
            if (ans[v].size() == cnt[v]) {
                vis[v] = true;
                ++finish;
            } 
        }
    }
    for (int i = 0; i < k; ++i) {
        printf("Case #%d:\n", i+1);
        if (ans[i].size() == 0) puts("None");
        else {
            for (int j = 0; j < ans[i].size(); ++j){
                int p = ans[i][j];
                printf("%s %d %d\n", arr[p].name,arr[p].age,
                        arr[p].worth);
            }
        }
    }
    return 0;
}
