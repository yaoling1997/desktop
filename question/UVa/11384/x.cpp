#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int dfs(int n){
	if (n==1) return 1;
	return dfs(n/2)+1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		printf("%d\n",dfs(n));
	}
	return 0;
}
	
