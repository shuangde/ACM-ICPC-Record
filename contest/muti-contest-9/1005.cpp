/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : 1005
 *   @description :
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/20 12:49 All rights reserved. 
 *======================================================*/
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
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);

char table[] = "0123456789ABCDEF";
vector<string>vt1, vt2;

map<string, string>mp;
char str1[][5] = {
"00","01","02","03","09","7F","0B","0C","0D","0E","0F","10","11","12","13","08","18","19","1C","1D","1E","1F","0A","17","1B","05","06","07","16","04","14","15","1A","20","2E","3C","28","2B","7C","26","21","24","2A","29","3B","2D","2F","2C","25","5F","3E","3F","60","3A","23","40","27","3D","22","61","62","63","64","65","66","67","68","69","6A","6B","6C","6D","6E","6F","70","71","72","7E","73","74","75","76","77","78","79","7A","5E","5B","5D","7B","41","42","43","44","45","46","47","48","49","7D","4A","4B","4C","4D","4E","4F","50","51","52","5C","53","54","55","56","57","58","59","5A","30","31","32","33","34","35","36","37","38","39"
}; 

char str2[][5] = {
"00","01","02","03","05","07","0B","0C","0D","0E","0F","10","11","12","13","16","18","19","1C","1D","1E","1F","25","26","27","2D","2E","2F","32","37","3C","3D","3F","40","4B","4C","4D","4E","4F","50","5A","5B","5C","5D","5E","60","61","6B","6C","6D","6E","6F","79","7A","7B","7C","7D","7E","7F","81","82","83","84","85","86","87","88","89","91","92","93","94","95","96","97","98","99","A1","A2","A3","A4","A5","A6","A7","A8","A9","B0","BA","BB","C0","C1","C2","C3","C4","C5","C6","C7","C8","C9","D0","D1","D2","D3","D4","D5","D6","D7","D8","D9","E0","E2","E3","E4","E5","E6","E7","E8","E9","F0","F1","F2","F3","F4","F5","F6","F7","F8","F9"
};

int main(){

    for (int i = 0; i < 128; ++i) {
        //mp[str1[i]]  = str2[i];
        mp[str2[i]]  = str1[i];
    }


    char tmp[3]; tmp[2] = 0;
    while (~scanf("%c%c", &tmp[0], &tmp[1]) && tmp[0] != '\n') {
        cout << mp[tmp]; 
    }
    puts("");

    return 0;
}
