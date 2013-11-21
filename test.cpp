#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
// 0~x-1
#define random(x) (rand()%x)
using namespace std;

const int N = 1e9;
typedef long long int64;


int64 a, b, c, d, p, m;
int64 one, two, three, four; 

int64 gcd(long long a,long long b){
        while(b^=a^=b^=a%=b);
            return a;
}

int64 countDown(int64 x, int64 y) {
    int64 tmp = x - m + p;
    int64 start = tmp%p==0 ? x : x+(p-tmp%p);
    tmp = y - m + p;
    int64 end   = tmp%p==0 ? y : y-(tmp%p);
    if (start > end) return 0;
    start = start-a-c+1; end = end-a-c+1;
    return (start+end)*((end-start)/p+1)/2;
}

int64 countUp(int64 x, int64 y) {
    int64 tmp = x - m + p;
    int64 start = tmp%p==0 ? x : x+(p-tmp%p);
    tmp = y - m + p;
    int64 end   = tmp%p==0 ? y : y-(tmp%p);
    if (start > end) return 0;
    start -= b;  end -= b;
    start = d - start + 1; end = d - end + 1;
    return (start+end)*((start-end)/p+1)/2;
} 

int64 countMid(int64 x, int64 y) { 
    int64 tmp = x - m + p;
    int64 start = tmp%p==0 ? x : (x+(p-tmp%p));
    tmp = y - m + p;
    int64 end   = tmp%p==0 ? y : y-(tmp%p);
    if (start > end) return 0;
    return ((end-start)/p+1) * (d-c+1);
}

int main(){

    cout << "Hello world!" << endl;
    return 0;

    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {

        cin >> a >> b >> c >> d >> p >> m;

        if (b-a < d-c) {
            swap(a, c); swap(b, d);
        }
        one = a+c, two = a+d, three = b+c, four = b+d;
        int64 res;
        if (two != three) {
            res = countDown(one, two) + countMid(two+1, three) + countUp(three+1, four);
        } else {
            res = countDown(one, two) + countUp(two+1, four);
        }
        int64 tot = (b-a+1)*(d-c+1);
        int64 div = gcd(res, tot);
        printf("Case #%d: ", cas);
        cout << res/div << "/" << tot/div << endl;
    }
    return 0;
}
