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
int M= 0,i,j,p,q,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("2.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]= a[i];
	}
	a[0]= a[1];a[n+1]= a[n];
	for (i= 1;i<=n+1;i++){
		if (a[i]==a[i-1]){			
			M= max(M,q-p);
			if (a[p]==a[q]){
				for (j= p+1;j<=q-1;j++)
					b[j]= a[p];
			}else {
				int mid= (q-p)/2;
				for (j= p+1;j<=p+mid;j++)
					b[j]= a[p];
				for (j= p+mid+1;j<q;j++)
					b[j]= a[q];
			}
			p= i;
		}else {
			q= i;
		}
	}
	printf("%d\n",M/2);
	for (i= 1;i<=n;i++)
		printf("%d%c",b[i], i<n?' ':'\n');
	return 0;
}
