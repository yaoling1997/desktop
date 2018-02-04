#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 150,maxl= 1000;
typedef int matrix[maxn][maxn];
matrix a;
ll c[maxn];
int b[maxl],sta[maxl],stack[maxl];
ll ans,x;
int n,i,top,T,tot,j;
void init(){
	b[0]= b[1]= 1;
	for (i= 2;i<=500;i++)
		if (!b[i]){
			int p= i*i;
			while (p<=500){
				b[p]= 1;
				p+= i;
			}
		}
	for (i= 2;i<=500;i++)
		if (!b[i])
			sta[++top]= i;
}
ll get(int m){
	int i= 1,j= 1,k,r,z;
	while (i<=m && j<=n){
		r= i;
		for (k= i;k<=m;k++)
			if (a[k][j]){r= k;break;}
		if (a[r][j]){
			if (i!=r)
				for (k= 1;k<=n;k++)
					swap(a[i][k],a[r][k]);
			for (k=i+1;k<=m;k++)
				if (a[k][j]){
					for (z= j;z<=n;z++)
						a[k][z]^= a[i][z];
				}
			i++;
		}
		j++;
	}
	return i-1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	init();
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		tot= 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for (i= 1;i<=n;i++)
			scanf("%lld",&c[i]);
		for (i= 1;i<=top;i++)
			for (j= 1;j<=n;j++)
				if (c[j]%sta[i]==0){
					if (!b[i])
						b[i]= 1,tot++;
					x= c[j];
					while (x%sta[i]==0)
						a[tot][j]^= 1,x/= sta[i];
				}
		ans= get(tot);
		printf("%lld\n",(1ll<<(n-ans))-1);
	}
	return 0;
}
