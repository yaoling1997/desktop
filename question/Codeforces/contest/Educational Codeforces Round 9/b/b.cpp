#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 6e5;
char s[maxn];
ll preA[maxn],preB[maxn],sufA[maxn],sufB[maxn],p[maxn];
ll i,n,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld",&n);
	for (i= 1;i<=n;i++)
		scanf("%lld",&p[i]);
	scanf("%s",s+1);
	for (i= 1;i<=n;i++){
		preA[i]= preA[i-1];
		preB[i]= preB[i-1];
		if (s[i]=='A') preA[i]+= p[i];
		else preB[i]+= p[i];
		sufA[n-i+1]= sufA[n-i+2];
		sufB[n-i+1]= sufB[n-i+2];
		if (s[n-i+1]=='A') sufA[n-i+1]+= p[n-i+1];
		else sufB[n-i+1]+= p[n-i+1];
	}
	for (i= 0;i<=n;i++){
		ans= max(ans,preB[n]-preB[i]+preA[i]);
		ans= max(ans,sufB[1]-sufB[n-i+1]+sufA[n-i+1]);
	}
	printf("%lld",ans);
}
