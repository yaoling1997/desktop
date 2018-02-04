#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 3e5,oo= 1e15;
ll a[maxn],b[maxn];
ll n,k,i,j,m,p= -1,B,K,Min,ans,x;
void get(ll *b,ll &m){
	for (i= 0;i<=n;i++){
		b[i+1]+= b[i]/2;
		b[i]%= 2;
		if (b[i]<0){
			b[i]+= 2;
			b[i+1]--;
		}
	}
	m= n;
	while (b[m+1]){
		m++;
		b[m+1]= b[m]/2;
		b[m]%= 2;
		if (b[m]<0){
			if (!b[m+1]) break;
			b[m]+= 2;
			b[m+1]--;
		}
	}	
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d%I64d",&n, &K);
	for (i= 0;i<=n;i++){
		scanf("%I64d",&a[i]);
		b[i]= a[i];
	}
	get(b,m);
	if (b[m]<0){
		memset(b,0,sizeof(b));
		p= 1;
		for (i= 0;i<=n;i++)
			b[i]= -a[i];
		get(b,m);
	}
	for (Min= 0;Min<=m;Min++)
		if (b[Min]) break;
	Min= min(Min,n);
	for (i= m;i>=Min;i--){
		B= B*2+b[i];
		if (B>oo){
			printf("0");
			return 0;
		}
	}
	for (i= Min;i>=0;i--){
		x= abs(a[i]+p*B);
		if (i==n){
			if (x<=K&&x){
				ans++;
			}
		}else if (x<=K){
			ans++;
		}
		B= B*2;
		if (B>oo)
			break;			
	}
	printf("%I64d\n",ans);		
	return 0;
}
