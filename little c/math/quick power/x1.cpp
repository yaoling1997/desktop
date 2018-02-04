#include<cstdio>
#include<cstdlib>
#include<cstring>
#define ll long long
using namespace std;
const int maxn= 1e5+20;
char b[maxn];
int i;
ll a,c,ans,len;
ll ksc(ll a,ll b,ll mo){
	ll re= 0;
	while (b){
		if (b & 1) re= (re+a)%mo;
		b>>= 1;a= (a+a)%mo;
	}
	return re;
}
ll ksm(ll a,ll b,ll mo){
	ll re= 1;
	while (b){
		if (b & 1) re= ksc(re,a,mo);
		b>>= 1;a= ksc(a,a,mo);
	}
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld\n",&a);
	scanf("%s",b+1);
	//while ((b[++len]= getchar())!='\n');
	len--;
	scanf("%lld",&c);
	len= strlen(b+1);
	a%= c;ans= 1;
	for (i= len;i>0;i--){
		ans= ksc(ans,ksm(a,b[i]-'0',c),c);
		a= ksm(a,10,c);
	}
	printf("%lld",ans);
	return 0;
}
