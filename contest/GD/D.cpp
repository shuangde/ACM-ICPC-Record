//大白p263
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ext/rope>
#define MP make_pair 
#define SQ(x) ((x)*(x))
using namespace std;
const double eps=1e-8;//精度
const int INF=0x3f3f3f3f;
typedef int int64;
typedef pair<int64,int64>PII;


struct node{
	int x;
	int y;
}arr[200005];

int two(int a[ ],int b,int n){
	int left=0,right=n;
	if(a[left]>b) return -1;

	while(left<right-1)
	{
		int mid=(left+right)/2;
		if(a[mid]<=b)
			left=mid;
		else
			right=mid;
	}
	return left;
}

int A[200010], B[200010];

int main(){

	int n,cas=1;

	while(~scanf("%d",&n) && n){

		for(int i=0;i<n;i++)
			scanf("%d%d",&arr[i].x, &arr[i].y);

		int ax,ay,bx,by,m;
		scanf("%d%d%d%d%d",&ax, &ay, &bx, &by, &m);

		vector<int>R1, R2;
		for(int i=0;i<n;i++){
			int64 ta = SQ(arr[i].x-ax) + SQ(arr[i].y-ay);
			int64 tb = SQ(arr[i].x-bx) + SQ(arr[i].y-by);
			R1.push_back(ta); R2.push_back(tb);
			A[i] = ta;
			B[i] = tb;
		}

		sort(R1.begin(), R1.end()); R1.push_back(INF); 
		sort(R2.begin(), R2.end()); R2.push_back(INF);
		sort(A, A+n); sort(B, B+n);


		printf("Case %d:\n", cas++);
		for(int i=0;i<m;i++){
			int r1, r2;
			scanf("%d%d", &r1, &r2);
			r1 *= r1;
			r2 *= r2;

		//	int sum = two(A, r1, n) + two(B, r2, n) + 2;
			int sum = 0;
			vector<int>::iterator pt;
			if (r1 >= R1[0]) {
				pt = upper_bound(R1.begin(), R1.end(), r1);
				while (*pt > r1) --pt;
				sum = pt  - R1.begin() + 1;
			}

			if (r2 >= R2[0]) {
				pt = upper_bound(R2.begin(), R2.end(), r2);
				while (*pt > r2) --pt;
				sum += pt - R2.begin() + 1;
			} 
			printf("%d\n", n-sum < 0 ? 0 : n - sum);
		}
	}
	return 0;
}
