//每次将0和0所在位置的数字交换位置
//如果0已经在位置0上了，先将0和任意一个错位的数字交换
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 100010;
int a[N];
int loc[N];

int main () {
    int n;
    scanf("%d", &n);
    set<int>ss;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        loc[a[i]] = i;
        if (a[i] && a[i] != i) {
            ss.insert(a[i]);
        }
    }
    int cnt = 0;
    while (ss.size()) {
        if (loc[0] == 0) {
            swap(loc[0], loc[*ss.begin()]);
            ++cnt;
        }
        ss.erase(loc[0]);
        swap(loc[0], loc[loc[0]]);
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
