#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 2000000;
int i,n,a[maxn];
void qsort(int p,int q){
	int x= a[(p+q)>>1],i= p,j= q;
	do{
		while (a[j]>x) j--;
		while (a[i]<x) i++;
		if (i<=j){
			int t= a[i];
			a[i]= a[j];
			a[j]= t;
			i++;
			j--;
		}
	}while (i<=j);
	if (p<j) qsort(p,j);
	if (i<q) qsort(i,q);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		scanf("%d ",&a[i]);
	}
	qsort(1,n);
	for (i= 1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
