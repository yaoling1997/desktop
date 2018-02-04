#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
ll a[11];
ll K,ans,K1;
int T,n,cnt,i;
int getlen(ll K){
	int x= 0;
	if (K==0) x++;
	while (K){
		x++;
		K/= 10;
	}return x;
}
void count(ll &K){
	K*= K;
	cnt= getlen(K);
	K/= a[max(0,cnt-n)];
	ans= max(ans,K);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	a[0]= 1;
	for (i= 1;i<=9;i++)
		a[i]= a[i-1]*10;
	for (int a1= 1;a1<=T;a1++){
		scanf("%d %lld",&n, &K);
		if (K==0){
			printf("0\n");
			continue;
		}
		cnt= getlen(K);
		ans= K1= K/= a[max(0,cnt-n)];
		for (;;){
			count(K);count(K);
			count(K1);
			if (K==K1) break;
		}printf("%lld\n",ans);
	}return 0;
}
