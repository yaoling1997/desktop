#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll mo= 1e9+7,maxn= 1e6+10;
ll size[maxn],next[maxn];
ll cnt,re,ans,x,k,p,i;
void go(ll o){
	if (next[o]) return;
	x= o*k%p;
	next[o]= x;
	size[cnt]++;
	go(x);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d%I64d",&p, &k);
	if (k==0){
		ans= 1;
		for (i= 1;i<p;i++)
			ans= ans*p%mo;
		printf("%I64d",ans);
		return 0;
	}else if (k==1){
		ans= 1;
		for (i= 0;i<p;i++)
			ans= ans*p%mo;
		printf("%I64d",ans);
		return 0;
	}
	for (i= 1;i<p;i++){
		if (next[i]) continue;
		cnt++;
		go(i);
	}
	ans= 1;re= p;
	for (i= 1;i<=cnt;i++){
		ans= ans*re%mo;
	}
	printf("%I64d\n",ans);
	return 0;
}
