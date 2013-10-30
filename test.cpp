#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 100010;
int n; int64 v;

struct Node {
    int t, p, id;
    bool operator<(const Node&rhs)const{
        return p > rhs.p;
    }
};
vector<Node>A, B;
vector<int>ans;
int pa, pb, lenA, lenB;
int64 maxx = 0, vo = 0;

int64 solve() {

    maxx = 0, vo = 0;
    while (vo + 2 <= v) {
        int tmp = A[pa].p + A[pa+1].p;
        if (tmp > B[pb].p) {
            maxx += tmp;
            ans.push_back(A[pa].id);
            if (A[pa+1].id != -1) ans.push_back(A[pa+1].id);
            vo += 2;
            pa += 2;
        } else {
            maxx += B[pb].p;
            ans.push_back(B[pb].id);
            vo += 2;
            pb++;
        }
    }

    if (v-vo && pa < lenA) {
        maxx += A[pa].p;
        ans.push_back(A[pa].id);
    }

}

int main () {

    cin >> n >> v;

    int64 sumV = 0, sumP = 0;
    for (int i = 0; i < n; ++i) {
        int t, p;
        scanf("%d%d", &t, &p);
        sumV += t;
        sumP += p;
        if (t == 1) {
            A.push_back((Node){t,p,i+1});
        } else {
            B.push_back((Node){t,p,i+1});
        }
    }

    if (v >= sumV) {
        cout << sumP << endl;
        for (int i = 1; i <= n; ++i)
            printf("%d ", i);
        puts("");
        return 0;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    pa = pb = 0;
    int lenA = A.size(), lenB = B.size();
    if (v%2 == 0) {
        if (A.size() & 1) {
            A.push_back((Node){1, 0, -1}); 
            ++lenA;
        } 
        solve();
    } else {
        if (A.size() & 1) {
            solve();
        } else {
            v -= 2;
            Node a, b;
            bool ok = false;
            if (lenA >= 2) {
                ok = true;
                a = A.back(); A.pop_back();
                b = A.back(); B.pop_back();
                lenA -= 2;
            }
            A.push_back((Node){1, -1000000, -1});
            A.push_back((Node){1, -1000000, -1});
            v -= 3;
            solve();
            if (ok) {
                if (a.p + b.p > a.p + B[pb].p) {
                    maxx += a.p + b.p;
                    ans.push_back(a.id);
                    ans.push_back(b.id);
                } else {
                    maxx += a.p + B[pb].p;
                    ans.push_back(a.id);
                    ans.push_back(B[pb].id);
                }
            } else {
            }
        }
    }

    cout << maxx << endl;
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}
