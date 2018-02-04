#include<bits/stdc++.h>
using namespace std;
const int maxn= 5e5;
int a[maxn],b[maxn];
int Max,cnt,i,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= n;i>=1;i--){
		if (a[i]>Max)
			Max= a[i],cnt= 1;
		else if (a[i]==Max)
			cnt++;
		if (a[i]<Max||(a[i]==Max&&cnt>1))
			b[i]= Max-a[i]+1;
	}
	for (i= 1;i<=n;i++)
		printf("%d%c",b[i], i<n?' ':'\n');
	return 0;
}
