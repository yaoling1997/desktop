#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 2e6,oo= 1e9+1;
struct node{
	int x,b;
};
node F[maxn],b[maxn],c[maxn];
int a[maxn],d[maxn],e[maxn],f[maxn],use[maxn];
ll K;
int n,i,j,r,top;
bool cmp(int a,int b){return d[a]<d[b];}
void merge(node *a,int p,int q){
	if (p==q) return;
	int mid= (p+q)>>1,i,j,k;
	merge(a,p,mid);merge(a,mid+1,q);
	for (i= p;i<=q;i++) e[i]= d[i];
	for (i= p;i<=mid;i++) b[i]= a[i];
	for (j= mid+1;j<=q;j++) c[j]= a[j];
	b[i].x= c[j].x= oo;
	i= p;j= mid+1;
	for (k= p;k<=q;k++)
		if (b[i].x<=c[j].x){
			d[k]= e[i];
			a[k]= b[i++];
		}else {
			d[k]= e[j]+mid-i+1;
			a[k]= c[j++];
		}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %lld",&n, &K);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		F[i].x= a[i];F[i].b= i;
		f[i]= i;
	}
	merge(F,1,n);
	for (i= 1;i<=n;i++) e[i]= d[i];
	for (i= 1;i<=n;i++) d[F[i].b]= e[i];
	sort(f+1,f+n+1,cmp);
	for (r= 1;r<=n;r++){
		while (j<=n&&d[f[j]]<r) j++;
		if (K>=n-j+1) K-= n-j+1;
		else break;
	}
	r--;	
	if (r==n&&K) printf("Impossible!");
	else {
		for (i= 1;i<=n;i++)
			if (d[i]<=r) e[++top]= a[i];
			else if (K){
				K--;
				if (d[i]<=r+1) e[++top]= a[i];
				else f[i-r-1]= a[i],use[i-r-1]= 1;
			}else f[i-r]= a[i],use[i-r]= 1;
		sort(e+1,e+top+1);j= 0;
		for (i= 1;i<=n;i++)
			if (!use[i]) f[i]= e[++j];
		for (i= 1;i<=n;i++) printf("%d%c",f[i],i<n?' ':'\n');
	}
	return 0;
}
