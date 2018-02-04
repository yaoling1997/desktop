#include<cstdio>
#include<cstdlib>
using namespace std;
const int mo= 100003;
long long n,m,i,ans;
long long xx(long long a,long long b){
	long long t= 1;
	while (b!=0){
		if (b & 1==1) t= t*a % mo;
		b=b >>1;
		a= a*a%mo;
	}
	return t;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%lld %lld",&m, &n);
	ans= (xx(m,n)-m*xx(m-1,n-1))% mo;
	if (ans<0) ans+= mo;
	printf("%lld",ans);
	return 0;
}
