#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn= 3001;
int a[maxn],m[maxn];
int i,n,ans;
void gcd(int a,int b,int &x,int &y){
	if (!b){x= 1;y= 0;return;}
	gcd(b,a%b,x,y);
	int t= x;
	x= y;
	y= t-a/b*y;
}
int china(int *a,int *m,int n){
	int M= 1,i,x= 0,p,q;
	for (i= 1;i<=n;i++) M*= m[i];
	for (i= 1;i<=n;i++){
		int w= M/m[i];
		gcd(w,m[i],p,q);
		x= (x+w*p%M*a[i])%M;
	}return (x+M)%M;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++)
		scanf("%d %d",&a[i], &m[i]);
	ans= china(a,m,n);
	printf("%d",ans);
	return 0;
}
