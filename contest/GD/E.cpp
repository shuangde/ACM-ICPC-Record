#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
char str[10000005];
int idx[50005];
char insert[105];
int version,len;

int main(){
	int n,code,v,p,c,s;

	scanf("%d",&n);

	while(n--){
		scanf("%d",&code);

		if(code==1){
			scanf("%d%s",&p,insert);
			int newv=len;
			int oldv=idx[version-1];
			for(int i=0;i<p;i++)
				str[len++]=str[oldv+i];
			for(int i=0;insert[i]!=0;i++)
				str[len++]=insert[i];
			for(int i=p;oldv+i<newv;i++)
				str[len++]=str[i+oldv];
			newv=len;
			idx[++version]=newv;

		}else if(code==2){
			scanf("%d%d",&p,&c);
			int newv=len;
			int oldv=idx[version-1];
			for(int i=0;i<p-1;i++)
				str[len++]=str[oldv+i];
			for(int i=p-1+c;oldv+i<newv;i++)
				str[len++]=str[oldv+i];
			newv=len;
			idx[++version]=newv;

		}else{
			scanf("%d%d%d",&v,&p,&c);
			int star=idx[v-1]+p-1;
			int en=idx[v-1]+p+c-1;
			for(int i=star;i<en;i++)
				putchar(str[i]);
			putchar('\n');
		}
	}
	return 0;
}
