
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
#define SQ ((x)*(x))
#define rep(i, n) for(int i=0;i<n;++i)
#define ff(i, n) for(int i=1;i<=n;++i)
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

const int MAXN = 1000010;
int n;

char key[MAXN], text[MAXN];
char str[MAXN];
string ans;

char mat[5][5];
map<int, PII>hash;
bool vis[500];

void find(char a, char b) {
    // 同行
    PII ap = hash[a], bp = hash[b];
    if (ap.first == bp.first) {
        int nextA = (ap.second+1)%5;
        int nextB = (bp.second+1)%5;
        ans += mat[ap.first][nextA];
        ans += mat[ap.first][nextB];

    // 同列
    } else if (ap.second == bp.second) {
        int nextA = (ap.first+1)%5;
        int nextB = (bp.first+1)%5;
        ans += mat[nextA][ap.second];
        ans += mat[nextB][ap.second];

    } else {
        int x = ap.first, y = bp.second;
        ans += mat[x][y];

        x = bp.first, y = ap.second;
        ans += mat[x][y];
        //printf("%c %c\n", a, b);
    }
}


void add(char& ch) {
    if (ch == 'Z') ch = 'A';
    else ch++;
    if(ch == 'J') ++ch;
}
void outmat(){
    cout <<endl;
    cout <<"-------------"<<endl;
    rep(i,5) {
        rep(j, 5) cout <<mat[i][j];
        puts("");
    }
    cout <<"-------------"<<endl;
}
int main() {
    int T;
    scanf("%d%*c", &T);
    for (int cas = 1; cas <= T; ++cas) {
        printf("Case %d: ", cas); 

        hash.clear();
        gets(key);
        gets(text);

        memset(vis, 0, sizeof(vis));
        int len = strlen(key), pt = 0;
        for (int i = 0; i < len; ++i) if (isalpha(key[i])) {
            key[i] = toupper(key[i]);
            if (vis[key[i]]) continue;
            int x = pt/5, y = pt%5;
            mat[x][y] = key[i];
            hash[key[i]] = MP(x, y);
            vis[key[i]] = true;
            ++pt;
        }
        for (char ch = 'A'; ch <= 'Z'; ++ch) if (ch!='J'){
            if (!vis[ch]) {
                int x = pt/5, y = pt%5;
                hash[ch] = MP(x, y);
                mat[x][y] = ch;
                vis[ch] = true;
                pt++;
            }
        }

        //outmat();

        len = strlen(text);
        char add_ch = 'A';
        ans = "";

        int idx = 0;
        for(int i = 0; i < len; ++i) if (isalpha(text[i])) {
            text[i] = toupper(text[i]); 
            str[idx++] = text[i]; 
        }

        str[idx] = 0;

        for (int j = 0; j < idx; ++j) {
            char a, b;
            if (j == idx-1) {
                a = toupper(str[j]); b = add_ch; add(add_ch);
                if (a == b) b = add_ch, add(add_ch);
                find(a, b);
            } else {
                if (str[j] == str[j+1]) {
                    a = str[j]; b = add_ch; add(add_ch);
                    if (a == b) b = add_ch, add(add_ch);
                } else {
                    a = str[j]; b = str[j+1]; 
                    ++j;
                }
                find(a, b);
            }
        }
        // outmat(); puts(text);
        cout << ans << endl;

    }
    return 0;
}
