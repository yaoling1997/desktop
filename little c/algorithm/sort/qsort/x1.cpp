#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 3000001;
int a[maxn],i,n;
bool cmp (int a,int b){
	return a<b;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		scanf("%d ",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for (i= 1;i<=n;i++){
		printf("%d ",a[i]);
	}
	int t= a[1];
	a[1]= a[2];
	a[2]= t;
	sort(a+1,a+n+1);
	printf("\n");
	for (i= 1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
