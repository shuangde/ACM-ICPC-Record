//注意字母范围，周一~周日：A~G
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

char str1[100], str2[100];
char day[][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main () {
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    bool first = true;
    for (int i = 0; i < len1 && i < len2; ++i) {
        if (first && str1[i]>='A' && str1[i]<='G' && str1[i]==str2[i]) {
                printf("%s ", day[str1[i]-'A']); 
                first = false;
        } else if (!first && (isdigit(str1[i]) || str1[i]>='A'&&str1[i]<='N')
                && str1[i]==str2[i]) {
            if (isdigit(str1[i])) printf("%02d", str1[i]-'0');
            else printf("%02d", str1[i]-'A'+10);
            break;
        }
    }
    scanf("%s%s", str1, str2);
    len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1 && i < len2; ++i) {
        if (isalpha(str1[i]) && str1[i]==str2[i]) {
            printf(":%02d\n", i); 
            break;
        }
    }
    return 0;
}
