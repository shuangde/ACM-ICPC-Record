// 题意：给一个长度最多10W的1～9的字符串
// 相邻的两个数相加等于9的，可以把它们合并成一个数字9
// 问合并成最多个9的方案，有几种？
// 例如，14545181，可以合并成19919,19991,19991 三种

// 思路，对于一串连续相邻的可以合并成9的数字  例如，454545454,
// 如果是偶数个组成， 那么只有一种方案，如果是奇数个，有cnt/2+1种，
// 所有相乘即使答案

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
#define PB push_back
#define SQ(x) ((x)*(x))
#define clr(a,b) memset(a, (b), sizeof(a))
#define cmax(a,b) a=max(a, (b))
#define cmin(a,b) a=min(a, (b))
#define asc(a,b) if(a>b)swap(a,b)
#define des(a,b) if(a<b)swap(a,b)
#define rep(i, n) for(int i=0;i<(n);++i)
#define ff(i, n) for(int i=1;i<=(n);++i)
#define ra(e, u) for(int e=head[(u)];e!=-1;e=E[e].next)
#define rv(u, j) for(int j=0;j<adj[u].size();++j)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int N = 100010;
char str[N];

int main() {

    while (gets(str)) {
        int len = strlen(str);
        int64 ans = 1;
        int cnt = 0, start=str[0]-'0';
        for (int i = 1; i < len; ++i) {
            if (((str[i]-'0')+(str[i-1]-'0')) == 9) {
                ++cnt; 
            } else {
                if (cnt >= 2 && cnt%2==0) {
                    ans *= (cnt/2+1); 
                }
                start = str[i] - '0';
                cnt = 0;
            }
        }
        if (cnt >= 2 && cnt%2==0) {
            ans *= (cnt/2+1);
        }
        cout << ans << endl;
    }
    return 0;
}
