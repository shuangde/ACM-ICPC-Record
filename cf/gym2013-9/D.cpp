
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
#define MP make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

int A[20];
char mat[100][100];
map<PII, int> pt;
bool vis[100];

void init() {
    for (int i = 0; i < 5; ++i) {
        scanf("%s", mat[i]);
    }
    memset(A, 0, sizeof(A));

    if (mat[0][4] != 'x') A[1] = mat[0][4] - 'A' + 1;
    pt[MP(0,4)] = 1;

    int idx = 2;
    for (int i = 0; i < 9; ++i) {
        if (mat[1][i] != '.') {
            if (mat[1][i] != 'x' ) A[idx] = mat[1][i] - 'A' + 1;
            pt[MP(1,i)] = idx;
            ++idx;
        }
    }

    if (mat[2][2] != 'x') A[idx]= mat[2][2] - 'A' + 1;
    pt[MP(2,2)] = idx++;

    if (mat[2][6] != 'x') A[idx]= mat[2][6] - 'A' + 1;
    pt[MP(2,6)] = idx++;

    for (int i = 0; i < 9; ++i)
        if (mat[3][i] != '.') {
            if (mat[3][i] != 'x') A[idx] = mat[3][i] - 'A' + 1;
            pt[MP(3,i)] = idx++;
        }

    if (mat[4][4] != 'x') A[idx] = mat[4][4] - 'A' + 1;
    pt[MP(4,4)] = idx++;

   // cout << idx << endl;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= 12; ++i) {
       // printf("%d\n", A[i]);
        if (A[i]) vis[A[i]] = true;
    }
}

bool check() {
    int sum = A[2] + A[3] + A[4] + A[5];
    int cnt = (bool)A[2] + (bool)A[3] + (bool)A[4] + (bool)A[5];
    if (cnt==4&&sum!=26 || cnt<4 && sum >=26) return false;

    sum = A[1] + A[3] + A[6] + A[8];
    cnt = (bool)A[1] + (bool)A[3] + (bool)A[6] + (bool)A[8];
    if (cnt==4&&sum!=26 || cnt<4 && sum >=26) return false;

    sum = A[1] + A[4] + A[7] + A[11];
    cnt = (bool)A[1] + (bool)A[4] + (bool)A[7] + (bool)A[11];
    if (cnt==4&&sum!=26 || cnt<4 && sum >=26) return false;

    sum = A[8] + A[9] + A[10] + A[11];
    cnt = (bool)A[8] + (bool)A[9] + (bool)A[10] + (bool)A[11];
    if (cnt==4&&sum!=26 || cnt<4 && sum >=26) return false;

    sum = A[2] + A[6] + A[9] + A[12];
    cnt = (bool)A[2] + (bool)A[6] + (bool)A[9] + (bool)A[12];
    if (cnt==4&&sum!=26 || cnt<4 && sum >=26) return false;

    sum = A[5] + A[7] + A[10] + A[12];
    cnt = (bool)A[5] + (bool)A[7] + (bool)A[10] + (bool)A[12];
    if (cnt==4&&sum!=26 || cnt<4 && sum >=26) return false;

    return true;
}

bool dfs(int cur) {

    if (cur == 13) {
        return true;
    }

    if (A[cur]) {
        return dfs(cur+1);

    } else {
        for (int i = 1; i <= 12; ++i) if (!vis[i]){
            vis[i] = true;
            A[cur] = i;
            if (check() && dfs(cur+1)) return true;
            A[cur] = 0;
            vis[i] = false;
        }
    }
    return false;
}

int main(){

    init();
    dfs(1);
    for (map<PII, int>::iterator it = pt.begin(); it!=pt.end(); ++it) {
        mat[it->first.first][it->first.second] = A[it->second] + 'A' - 1;
    }
    rep (i, 5) puts(mat[i]);
    return 0;
}
