
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
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

const int MAXN = 1000000;

int A[MAXN];
int n;

bool cross(int l1, int r1, int l2, int r2) {
    if (l2<r1 && l2 > l1 && r2>r1) return true;
    return false;
}

bool judge() {
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) if (i != j) {
            int l1=A[i-1], r1=A[i];
            int l2=A[j-1], r2=A[j];
            if (l1 > r1) swap(l1, r1);
            if (l2 > r2) swap(l2, r2);
            if (cross(l1, r1, l2, r2)) return false;
            if (cross(l2, r2, l1, r1)) return false;
        }
    }
    return true;
}

int main(){

    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &A[i]);
        if (judge()) puts("no");
        else puts("yes");
    }
    return 0;
}
