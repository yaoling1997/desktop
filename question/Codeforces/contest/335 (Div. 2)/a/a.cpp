#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
int a[10],b[10];
int i,cnt,low;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	for (i= 1;i<=3;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<=3;i++){
		scanf("%d",&b[i]);
		a[i]-= b[i];
		if (a[i]>0)
			cnt+= a[i]/2;
		else low+= a[i];
	}
	if (cnt+low>=0) printf("Yes\n");
	else printf("No\n");
	return 0;
}
