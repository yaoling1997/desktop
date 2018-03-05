#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
double k,d,t,sw,sc,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%lf%lf%lf",&k,&d,&t);
	sw=1./t;
	sc=1./2/t;
	ll x=k,y=d;
	if (x%y==0){
		ans=t;
	}else{
		d=x/y*y+d;
		double g= 1/(k*sw+(d-k)*sc);
		g=(ll)(g+1e-15);
		ans+=g*d;
		double x=1-g*(k*sw+(d-k)*sc);
		if (x!=0){
			if (k*sw>=x)
				ans+=x/sw;
			else {
				ans+=k;
				x-=k*sw;
				ans+=x/sc;
				x=0;
			}
		}
	}
	printf("%.14f",ans);
	return 0;
}
