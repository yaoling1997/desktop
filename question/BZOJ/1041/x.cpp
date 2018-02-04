#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8;
const int maxn= 3001;
double y;
ll c,a,b,d,ans,i,j,lim,lim2,x,z;
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld",&c);
	lim= sqrt(2*c)+eps;
	for (i= 1;i<=lim;i++)
		if (2*c%i==0){
			x= 2*c/i;
			lim2= sqrt(x/2)+eps;
			for (j= 1;j<=lim2;j++){
				y= sqrt(x-j*j);z= floor(y);
				if (fabs(z-y)<eps)
					if (z>j&&gcd(j,z)==1)
						ans++;
			}
			if (x!=i){
				x= i;
				lim2= sqrt(x/2)+eps;
				for (j= 1;j<=lim2;j++){
					y= sqrt(x-j*j);z= floor(y);
					if (fabs(z-y)<eps)
						if (z>j&&gcd(j,z)==1)
							ans++;
				}
			}
		}
	ans= ans*4+4;
	printf("%lld\n",ans);
	return 0;
}
