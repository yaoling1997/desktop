#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e3;
int a[maxn],b[maxn];
int i,j,n,la;
int gcd(int a,int b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i= 1;i<n;i++){
		b[++la]= a[i];
		if (gcd(a[i],a[i+1])==1) continue;
		b[++la]= 1;
	}b[++la]= a[n];
	printf("%d\n",la-n);
	for (i= 1;i<=la;i++)
		printf("%d%c",b[i],i<la?' ':'\n');	
	return 0;
}
