#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 2e6,mo= 1e9+7;
ll h[maxn],s[maxn];
ll n,ans,i,j,l,r;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d",&n);
	for (i= 1;i<=n;i++)
		scanf("%I64d",&h[i]);
	s[n-1]= min(h[n]-1,h[n-1]-1);
	for (l= n-2;l>0;l--){
		s[l]= min(h[l]-1,min(h[l+1]-1,h[l+2]-1))*s[l+1]%mo;
		s[l]= (s[l]+min(h[l+1]-1,h[l]-1))%mo;
	}
	for (i= 1;i<=n;i++)
		ans= (ans+h[i]-1)%mo;
	for (l= 1;l<n;l++)
		ans= (ans+min(h[l]-1,h[l+1]-1)*s[l])%mo;
	printf("%I64d",ans);
	return 0;
}
