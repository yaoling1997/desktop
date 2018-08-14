#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
const double eps= 1e-8;
const int maxn= 510;
map<int,int> M;
int a[maxn*maxn],c[maxn],d[maxn],ans[maxn];
int cnt,n,i,j,la,x,y,z,p,q,ooo,oo2,oo3;
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n*n;i++){
		scanf("%d",&a[i]);
		if (!M.count(a[i])){
			M[a[i]]= 1;
			c[++cnt]= a[i];
		}else 
			M[a[i]]++;		
	}
	sort(c+1,c+cnt+1);
	for (i= cnt;i>0;i--){
		ooo= M[2];
		oo3= M[4];
		if (!M[c[i]]) continue;
		z= M[c[i]];
		y= 0;
		for (j= i+1;j<=cnt;j++)
			if (gcd(c[i],c[j])==c[i]){
				oo2= M[c[j]];
				y+= sqrt(M[c[j]])+eps;
			}
		y*= 2;
		p= (-y+sqrt(y*y+4*z))/2+eps;
		M[c[i]]= p*p;
		for (j= 1;j<=p;j++)
			ans[++la]= c[i];
		for (j= i+1;j<=cnt;j++){
			x= gcd(c[i],c[j]);
			if (x==c[i]) continue;
			q= sqrt(M[c[j]])+eps;
			M[x]-= p*q*2;
		}
	}
	for (i= 1;i<=n;i++)
		printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}
