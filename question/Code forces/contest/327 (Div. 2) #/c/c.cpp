#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 6e5;
int a[maxn],b[maxn];
int ans,bl,i,n;
int max(int x,int y,int z){
	return max(max(x,y),z);
}
int min(int x,int y,int z){
	return min(min(x,y),z);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	bl= 1;
	while (bl){
		bl= 0;
		b[1]= a[1];
		b[n]= a[n];
		for (i= 2;i<n;i++){
			b[i]= a[i-1]+a[i]+a[i+1]-max(a[i-1],a[i],a[i+1])-min(a[i-1],a[i],a[i+1]);
			if (b[i]!=a[i]) bl= 1;
		}
		ans+= bl;
		for (i= 1;i<=n;i++)
			a[i]= b[i];
	}
	printf("%d\n",ans);
	for (i= 1;i<=n;i++)
		printf("%d%c",b[i], i<n?' ':'\n');
	return 0;
}
