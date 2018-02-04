#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3000000,oo= 99999999;
int n,i,a[maxn],b[maxn],c[maxn];
void msort(int p,int q){
	int i,j,k,mid= (p+q)>>1;
	if (q>p){
		msort(p,mid);
		msort(mid+1,q);
		for (i= p;i<=mid;i++) b[i-p+1]= a[i];
		for (i= mid+1;i<=q;i++) c[i-mid]= a[i];
		b[mid-p+2]= oo;
		c[q-mid+1]= oo;
		i= 1;j=1;
		for (k= p;k<=q;k++){
			if (b[i]<c[j]){
				a[k]= b[i];
				i++;
			}else {
				a[k]= c[j];
				j++;
			}
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		scanf("%d ",&a[i]);
	}
	msort(1,n);
	for (i= 1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
