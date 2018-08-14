#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2e2;
int a[maxn];
int n,m,i;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int sum= 0;
	for (i= 1;i<=n;i++){
		sum+= a[i];
		if (sum>=m) break;
	}
	printf("%d\n",i);
	return 0;
}
