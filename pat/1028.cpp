// shuangde
// 简单排序
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstring>
using namespace std;
struct Node {
    char id[7];
    char name[9];
    int grade;
};
Node arr[100010];

bool cmp_id(const Node& lhs, const Node& rhs) {
    return strcmp(lhs.id, rhs.id) < 0;
}
bool cmp_name(const Node& lhs, const Node& rhs) {
    if (strcmp(lhs.name,rhs.name) != 0) return strcmp(lhs.name,rhs.name)<0;
    return strcmp(lhs.id, rhs.id) < 0;
}
bool cmp_grade(const Node& lhs, const Node& rhs) {
    if (lhs.grade != rhs.grade) return lhs.grade < rhs.grade;
    return strcmp(lhs.id, rhs.id) < 0;
}

bool (*func[3])(const Node&, const Node&) = {cmp_id, cmp_name, cmp_grade};

int main () {
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) 
		scanf("%s%s%d",arr[i].id, arr[i].name, &arr[i].grade);
    sort(arr, arr+n, func[c-1]);
	for (int i = 0; i < n; ++i) {
		printf("%s %s %d\n",arr[i].id,arr[i].name,arr[i].grade);
	}
    return 0;
}
