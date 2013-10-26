
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
#define Lson(x) (x<<1)  
#define Rson(x) (Lson(x)|1)  
#define Mid(x,y) ((x+y)>>1)  
#define Sum(x,y) (x+y)  
using namespace std;

const double PI  = acos(-1.0);
const int INF = 0x3f3f3f3f;

typedef int Type;  

const int MAXN = 500010;

int n, k;
  
int num[MAXN];  
struct Node{  
    int left;  
    int right;  
    int maxScore;   
};  
Node node[4*MAXN];  
  
void push_up(int pos){  
    node[pos].maxScore = max(node[Lson(pos)].maxScore , node[Rson(pos)].maxScore);  
}  
  
void init(int left , int right , int pos){  
    node[pos].left = left;  
    node[pos].right = right;  
    if(node[pos].left == node[pos].right){  
        node[pos].maxScore = num[left];  
        return;  
    }  
    int mid = Mid(left , right);  
    init(left , mid , Lson(pos));  
    init(mid+1 , right , Rson(pos));  
    push_up(pos);   
}  
  
void update(int index , int val , int pos){  
    if(node[pos].left == node[pos].right){  
        node[pos].maxScore = val;  
        return;  
    }  
    int mid = Mid(node[pos].left , node[pos].right);  
    if(index <= mid)  
        update(index , val , Lson(pos));  
    else  
        update(index , val , Rson(pos));  
    push_up(pos);   
}  
  
int query(int left , int right , int pos){  
    if(node[pos].left == left && node[pos].right == right)   
        return node[pos].maxScore;  
    int mid = Mid(node[pos].left , node[pos].right);  
    if(right <= mid)  
        return query(left , right , Lson(pos));  
    else if(left > mid)  
        return query(left , right , Rson(pos));  
    else  
        return max(query(left , mid , Lson(pos)),query(mid+1 , right , Rson(pos)));  
}  
char str[MAXN];

int main(){

    while (~scanf("%d%d", &n, &k)) {

        
        scanf("%s", str+1);
        for (int i = 1; i <= n; ++i)
            num[i] = str[i] - '0';

        init(1, n, 1);

        int pt = 1;
        while (pt <= n) {

            int l = pt, r = min(n, pt + k);
            int maxx = query(l, r, 1);

            while (pt <= n && num[pt] < maxx) {
                num[pt] = -1;
                ++pt;
                --k;
            }
            ++pt;
        }
        while (k > 0) --n, --k;
        for (int i = 1; i <= n; ++i)
            if (num[i] >= 0) printf("%d", num[i]);
        puts("");
    }
    return 0;
}
