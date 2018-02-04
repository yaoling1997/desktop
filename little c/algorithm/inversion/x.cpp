#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3e5;
struct node{
	int v,x,h;
};
node a[maxn],b[maxn];
int n,i,ans;
bool cmp(node a,node b){
	return a.h<b.h;
}
void merge(int p,int q){
	if (p>=q) return;
	int mid= (p+q)>>1,i= p,j= mid+1,k= p;
	merge(p,mid);
	merge(mid+1,q);
	while (i<=mid||j<=q){
		if (i>mid) b[k]= a[j],j++;
		else if (j>q) b[k]= a[i],i++;
		else if (a[i].v<=a[j].v) b[k]= a[i],i++;
		else a[j].x+= mid-i+1,b[k]= a[j],j++;
		k++;
	}	
	for (i= p;i<=q;i++) a[i]= b[i];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i].v);
		a[i].h= i;
	}
	merge(1,n);
	sort(a+1,a+n+1,cmp);
	for (i= 1;i<=n;i++)
		ans+= a[i].x;
	printf("%d\n",ans);
	for (i= 1;i<=n;i++)
		printf("%d%c",a[i].x,i<n?' ':'\n');
	return 0;
}
