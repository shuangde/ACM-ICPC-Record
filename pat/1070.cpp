//简单贪心
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
const int N = 1010;

struct Node {
    double amount;
    double price;
    double val;
    bool operator < (const Node& rhs) const {
        return val > rhs.val; 
    }
}arr[N];

int main () {
    int n;
    double m;
    scanf("%d%lf", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &arr[i].amount);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &arr[i].price);
        arr[i].val = arr[i].price/arr[i].amount;
    }
    sort(arr, arr+n);
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (m - arr[i].amount > 0) {
            ans += arr[i].price;
            m -= arr[i].amount;
        } else {
            ans += arr[i].val * m;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
