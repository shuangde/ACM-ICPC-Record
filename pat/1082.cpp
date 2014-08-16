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
typedef long long LL;
typedef pair<LL, LL >PII;
const int INF = 0x3f3f3f3f;

char str[12];
string chn[10] = {"ling","yi","er","san","si",
    "wu","liu","qi","ba","jiu"};
string jz[3] = {"Qian","Bai","Shi"};
vector<string>ans;

void read(char* num) {
    int r;
    for (int i = 0; i < 4; ++i) {
        if (num[i] == '0') {
            if (i!=3 && ans.size() && ans.back()!=chn[0] && ans.back()!="Fu") {
                ans.PB(chn[0]);
            }
        } else {
            ans.PB(chn[num[i]-'0']);
            if (i!=3) ans.PB(jz[i]);
        }
    }
}

int main () {

    scanf("%s", str);
    int r;
    sscanf(str, "%d", &r);
    if (r==0) {
        puts("ling");
        return 0;
    }
    char *p = str;
    if (str[0] == '-') ans.PB("Fu"), p++;
    int len = strlen(p);
    if (len==9) {
        ans.PB(chn[p[0]-'0']);
        ans.PB("Yi");
        ++p;
    }
    char num[10] = {0};
    len = strlen(p);
    if (len != 8) {
        int i, j = 7;
        for (i = len - 1; i >= 0; --i) 
            num[j--] = p[i];
        while (j >= 0) {
            num[j--] = '0';
        }
    } else {
        for (int i = 0; i < 8; ++i) 
            num[i] = p[i];
    }
    sscanf(num, "%4d", &r);
    if (r) {
        read(num);
        while (ans.size() && ans.back()=="ling")
            ans.pop_back();
        ans.PB("Wan");
    } else if(ans.size() && ans.back()!="Fu"){
        ans.PB("ling");
    }
    read(num+4);
    while (ans.size() && ans.back()=="ling")
        ans.pop_back();
    for (int i = 0; i < ans.size(); ++i) {
        printf("%s", i?" ":""); 
        cout << ans[i];
    }
    puts("");
    return 0;
}
