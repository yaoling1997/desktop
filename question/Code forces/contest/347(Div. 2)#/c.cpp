#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e3;
set<ll> S;
char s[maxn],t[maxn];
ll x,y,d,ans,M;
int len,i,j,n;
ll deal(ll x,ll d){
	x-= d;
	for (;;){
		x+= d;
		if (x<M) continue;
		if (!S.count(x)){
			S.insert(x);
			return x;
		}
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	M= 1989;
	for (i= 1;i<=n;i++){
		scanf("%s",s+1);
		len= strlen(s+1);
		x= 0;
		d= 1;
		S.clear();
		for (j= len;j>=5;j--){
			x= x+d*(s[j]-'0');
			d*= 10;
			ans= deal(x,d);
		}
		printf("%I64d\n",ans);
	}return 0;
}