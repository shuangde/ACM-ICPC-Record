//注意为0时表示 *10^0
// 3 0 0.00
// 4 0.0001234 0.0001234
//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;

int len;

string change(char* str) {
    int dot = -1;
    for (int i = 0; str[i]; ++i)
        if (str[i] == '.') {
            dot = i;
            break;
        }
    string ans = "0.";
    double val;
    sscanf(str, "%lf", &val);
    if (dot == -1) {
        for (int i = 0; i < len; ++i) {
            if (i < strlen(str))
                ans += str[i];
            else
                ans += '0';
        }
        char tmp[10];
        if (val!=0)sprintf(tmp, "*10^%d", strlen(str));
        else strcpy(tmp, "*10^0");
        ans += tmp; 
    } else {
        int i;
        for (i = 0; i<strlen(str)-1&&
                (str[i]=='0'||str[i]=='.'); ++i)
            ;;;
        for (int j = i; ans.size()-2<len; ++j) {
            if (j<strlen(str) && str[j] == '.') continue;
            if (j < strlen(str))
                ans += str[j];
            else
                ans += '0';
        }
        char tmp[10];
        if (val != 0)
            sprintf(tmp, "*10^%d", dot-i>0?dot-i:dot-i+1);
        else
            strcpy(tmp, "*10^0");
        ans += tmp; 
    }
    return ans;
}

int main () {
    char str1[110], str2[110];
    scanf("%d%s%s", &len,str1,str2);
    string s1 = change(str1);
    string s2 = change(str2);
    if (s1 == s2) cout << "YES " << s1 << endl;
    else cout << "NO " <<s1 << " " << s2 << endl;
    return 0;
}
