#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1e3+10;
ll a[maxn][maxn];
ll x,y,ans,M= 1000,n,i;
ll count1(ll x,ll y){
	ll re= 0;
	while (x<=M&&y<=M){
		re+= a[x][y];
		x++;y++;
	}
	return re;
}
ll count2(ll x,ll y){
	ll re= 0;
	while (x<=M&&y>0){
		re+= a[x][y];
		x++;
		y--;
	}return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++){
		scanf("%lld %lld",&x, &y);
		a[x][y]= 1;
	}
	for (i= 1;i<=1000;i++){
		x= count1(1,i);
		ans+= x*(x-1)/2;
		if (i!=1){
			x= count1(i,1);
			ans+= x*(x-1)/2;
			x= count2(i,M);
			ans+= x*(x-1)/2;			
		}
		x= count2(1,i);
		ans+= x*(x-1)/2;
	}
	printf("%lld",ans);
	return 0;
}
