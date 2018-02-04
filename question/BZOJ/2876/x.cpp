#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const double eps= 1e-12;
const int maxn= 1e5,oo= 1e6;
double S[maxn],K[maxn],V[maxn],v[maxn];
double E,ans,x;
int n,i;
void go(int i,double M){
	double l,r,yl;
	if (V[i]<0)
		l= 0,r= +oo;
	else l= V[i]*2/3,r= +oo;	
	yl= 2*K[i]*M*l*l*(l-V[i])+1;
	while (r-l>eps){
		double m= (l+r)/2,x= 2*K[i]*M*m*m*(m-V[i])+1;
		if (yl*x<0) r= m;
		else l= m,yl= x;
	}v[i]= l;
}
double count(){
	int i;double re= 0;
	for (i= 1;i<=n;i++)
		re+= K[i]*S[i]*(v[i]-V[i])*(v[i]-V[i]);
	return re;
}
void solve(){
	int i;
	double l= -oo,r= 0;
	while (r-l>eps){
		double m= (l+r)/2;
		for (i= 1;i<=n;i++)
			go(i,m);
		if (count()>E) r= m;
		else l= m;
	}
	ans= 0;
	for (i= 1;i<=n;i++)
		ans+= S[i]/v[i];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %lf",&n, &E);
	for (i= 1;i<=n;i++)
		scanf("%lf %lf %lf",&S[i], &K[i], &V[i]);
	solve();
	printf("%.8lf",ans);
	return 0;
}
