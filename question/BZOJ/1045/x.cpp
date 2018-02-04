#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn= 3000001;
ll a[maxn],c[maxn];
ll w,ans;
int n,i;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		ans= w= 0;
		for (i= 1;i<=n;i++){
			scanf("%lld",&a[i]);
			w+= a[i];
			a[i]+= a[i-1];
		}
		w/= n;
		for (i= 1;i<n;i++)
			c[i]= a[i]-i*w;
		sort(c+1,c+n+1);
		w= c[(n+1)/2];
		for (i= 1;i<=n;i++)
			ans+= abs(w-c[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
