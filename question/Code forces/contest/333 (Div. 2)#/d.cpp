#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const double eps= 1e-8;
const ll maxn= 3e5,oo= 1e9;
ll sta[maxn],stb[maxn];
ll a[maxn],K[maxn],left[maxn],right[maxn];
ll n,q,ans,i,x,y,l,r,la,add;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d%I64d",&n, &q);
	for (i= 1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for (i= 1;i<n;i++)
		K[i]= abs(a[i+1]-a[i]);
	for (ll Q= 1;Q<=q;Q++){
		scanf("%I64d%I64d",&l, &r);
		r--;
		ans= 0;
		sta[0]= oo;
		stb[0]= l-1;
		la= 0;
		for (i= l;i<=r;i++){
			while (sta[la]<=K[i]) la--;
			left[i]= stb[la]+1;
			sta[++la]= K[i];
			stb[la]= i;
		}
		sta[0]= oo;
		stb[0]= r+1;
		la= 0;
		for (i= r;i>=l;i--){
			while (sta[la]<K[i]) la--;
			right[i]= stb[la]-1;
			sta[++la]= K[i];
			stb[la]= i;
		}
		for (i= l;i<=r;i++){
			add= 1;
			add+= i-left[i];
			add+= right[i]-i;
			add+= (i-left[i])*(right[i]-i);
			ans+= add*K[i];
		}
		printf("%I64d\n",ans);
	}return 0;
}
