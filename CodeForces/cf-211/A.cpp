
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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const double eps = 1e-8;

char num[][10] = {
"O-|-OOOO",
"O-|O-OOO",
"O-|OO-OO",
"O-|OOO-O",
"O-|OOOO-",
"-O|-OOOO",
"-O|O-OOO",
"-O|OO-OO",
"-O|OOO-O",
"-O|OOOO-",
};

int main() {

    char str[20];
    while ( gets(str)){
        int p = 0;
        while (p < strlen(str)-1 && str[p] == '0') ++p;

        for (int i = strlen(str)-1; i>=p; --i) {
            puts(num[str[i]-'0']); 
        }
    }

    return 0;
}
