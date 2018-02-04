#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 3001;
int c[maxn];
int p,n,m,ans,i;
void gcd(int a,int b,int &x,int &y){
	if (!b){x= 1;y= 0;return;}
	gcd(b,a%b,x,y);
	int t= x;
	x= y;
	y= t-a/b*y;
}
int lucas(int m,int n,int p){
	int re= 1,x,y;
	while (n||m){
		if (n%p>m%p) return 0;
		re= re*c[m%p]%p;
		gcd(c[m%p-n%p]*c[n%p]%p,p,x,y);
		re= re*x%p;
		n/= p;m/= p;
	}return (re+p)%p;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &p);
	c[0]= 1;
	for (i= 1;i<=p;i++)
		c[i]= c[i-1]*i%p;
	ans= lucas(m,n,p);
	printf("%d",ans);
	return 0;
}
