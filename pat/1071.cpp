//shuangde
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#define MP make_pair
#define PB push_back 
#define SQ(x) ((x)*(x)) 
using namespace std; 
typedef pair<int, int >PII;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 1010;

int main () {
    char ch = getchar();
    while (!isalnum(ch) && ch!='\n') ch = getchar();
    map<string,int>mp;
    while (ch != '\n') {
        string str="";
        while (isalnum(ch)) {
            if (isalpha(ch)) ch = tolower(ch);
            str += ch;
            ch = getchar();
        }
        mp[str]++;
        if (ch == '\n') break;
        ch = getchar();
        while (!isalnum(ch) && ch!='\n') ch = getchar();
    }
    string str;
    int cnt = -1;
    for (map<string,int>::iterator it = mp.begin();
            it != mp.end(); ++it) {
        if (it->second > cnt) 
            cnt = it->second, str = it->first;
    }
    cout << str << " " << cnt << endl;
    return 0;
}
