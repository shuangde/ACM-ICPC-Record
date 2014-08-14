//排序
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

const int N = 10010;
int p[10];
int s[N][10];
bool submit[N][10];
bool vis[N];

struct Node {
    int user_id;
    int score;
    int solve_num;
    bool operator < (const Node& rhs) const {
        if (score != rhs.score) return score > rhs.score;
        if (solve_num != rhs.solve_num) return solve_num > rhs.solve_num;
        return user_id < rhs.user_id;
    }
}arr[N];

int main () {
    int n, k, m;
    scanf("%d%d%d", &n,&k,&m);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &p[i]);

    for (int i = 0; i < m; ++i) {
        int user, problem, score;
        scanf("%d%d%d",&user,&problem,&score);
        submit[user][problem] = true;
        if (score == -1) continue;
        vis[user] = true;
        arr[user].user_id = user;
        if (score > s[user][problem]) {
            arr[user].score += score - s[user][problem];
            s[user][problem] = score;
            if (score == p[problem])
                arr[user].solve_num++;
        }
    }

    vector<Node>vt;
    for (int i = 1; i <= n; ++i) if (vis[i]){
        Node tmp;
        tmp.user_id = i;
        tmp.score = arr[i].score;
        tmp.solve_num = arr[i].solve_num;
        vt.push_back(tmp);
    }
    sort(vt.begin(), vt.end());
    int rank = 1;
    for (int i = 0; i < vt.size(); ++i) {
        if (i == 0) printf("1");
        else {
            if (vt[i].score == vt[i-1].score) printf("%d", rank); 
            else printf("%d", rank = i + 1);
        }
        printf(" %05d %d",vt[i].user_id, vt[i].score);
        for (int j = 1; j <= k; ++j) {
            if (submit[vt[i].user_id][j])
                printf(" %d",s[vt[i].user_id][j]);
            else 
                printf(" -");
        }
        puts("");
    }
    return 0;
}
