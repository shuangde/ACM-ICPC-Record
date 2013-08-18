/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source：uva-442 Matrix Chain Multiplication
 *   @type: 记忆化搜索, 区间dp
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
/*

很明显看出可以递归求解，而且可转为递推区间dp求解
f(i, j) 表示在（i,j）区间中一共有几次相乘
row(i, j)表示这个区间相乘后的矩形行尺寸
col(i, j) 表示这个区间相乘后的矩形列尺寸

递归时维护这三个数组即可

那么如果str[i]='('且str[j]=')', 就递推求解子问题f(i+1, j-1)
如果只有一边是括号，那么递推求解f(i+1, j) 和 f(i, j-1)
接着枚举终点ｋ, 当这个划分合法时：
f(i, j) = f(i,k) + f(i,k+1) + row(i,k)*row(k+1,j)*col(k+1,j)

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 30;

int n;
int getRow[150];
int getCol[150];
int f[MAXN][MAXN];
int col[MAXN][MAXN];
int row[MAXN][MAXN]; 
char str[1000];


bool dfs(int i, int j) {
    if (f[i][j] != -1) return true;

    if(i == j) {
        if( isalpha(str[i])) {
            row[i][i] = getRow[str[i]]; 
            col[i][i] = getCol[str[i]];
            f[i][j] = 0;
            return true;
        }
        return false;
    }

    if (str[i]=='(' && str[j]==')') {
        bool ret = dfs(i+1, j-1); 
        if(!ret) return false;
        f[i][j] = f[i+1][j-1];
        col[i][j] = col[i+1][j-1];
        row[i][j] = row[i+1][j-1];

    } else if (str[i]=='(' && str[j]!=')'){
        bool ret = dfs(i, j-1);
        if(!ret || col[i][j-1] != getRow[str[j]]) return false; 
        f[i][j] = f[i][j-1] + row[i][j-1] * getRow[str[j]] * getCol[str[j]] ;
        row[i][j] = row[i][j-1];
        col[i][j] = getCol[str[j]];

    } else if (str[i]!='(' && str[j]==')') {
        bool ret = dfs(i+1, j);
        if(!ret || getCol[str[i]] != row[i+1][j]) return false;
        f[i][j] = f[i+1][j] + getRow[str[i]] * row[i+1][j] * col[i+1][j];
        row[i][j] = getRow[str[i]];
        col[i][j] = col[i+1][j];

    }
    for (int k = i; k < j; ++k) {
        bool ret1 = dfs(i, k);
        bool ret2 = dfs(k+1, j);
        if(ret1 && ret2 && col[i][k]==row[k+1][j]) {
            f[i][j] = f[i][k] + f[k+1][j] + row[i][k] * row[k+1][j] * col[k+1][j];
            row[i][j] = row[i][k];
            col[i][j] = col[k+1][j];
            return true;
        }
    }
    return f[i][j] != -1;
}


int main(){

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        char ch[2];
        scanf("%s", ch);
        scanf("%d%d", &getRow[ch[0]], &getCol[ch[0]]);
    }

    while (~scanf("%s", str)) {

        int len = strlen(str);
        memset(f, -1, sizeof(f));
        if (dfs(0, len-1)) {
            printf("%d\n", f[0][len-1]);     
        } else {
            puts("error");
        }
    }


    return 0;
}
