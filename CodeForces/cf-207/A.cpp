#include<cstdio>

int n, x, y;
int num[110];


int main () {
    while (~scanf("%d", &n)) {
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
            tot += num[i];
        } 
        scanf("%d%d", &x, &y);
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (sum >=x && sum <= y && tot-sum>=x && tot-sum<=y) {
                //ans = i + 1;
                printf("%d\n", i+2);
                return 0;
                break;
            }
            sum += num[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
