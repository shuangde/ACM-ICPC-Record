#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 50;
const int MOD = 1000000000 + 7;
typedef int State[3][3];

int count[N];
int n, m, sum;

long long inverse(long long a) {
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

bool vis[1000000];
int main() {

    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &sum, &m);
        int n = (sum + m - 1) / m;
        for (int i = 1; i < n; ++ i) {
            count[i] = m;
        }
        count[n] = sum - (n - 1) * m;
        long long answer = 1;
        for (int i = 1; i <= sum; ++ i) 
            answer = answer * i % MOD;

        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= count[i]; ++ j) {
                long long temp = count[i] - j + 1;
                for (int k = i + 1; k <= n; ++ k) {
                    if (count[k] >= j) {
                        temp ++;
                    }
                }
                answer = answer * inverse(temp) % MOD;
            }
        }
        std::cout << answer << std::endl;
    }
    return 0;
}
