#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int maxn= 300;
int b[maxn];
ll f[maxn][maxn],a[maxn],stb[maxn];
ll ans,m,M;
int n,T,x,la,i,j,cnt,now,lb;
void init(){
	memset(f,0,sizeof(f));
	M= 0;
}
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (i= 2;i<=100;i++)
		if (!b[i]){
			stb[++lb]= i;
			int p= i*i;
			while (p<=100){
				b[p]= 1;
				p+= i;
			}
		}
	
	while (T--){
		scanf("%d",&n);
		init();
		if (n==1){
			printf("%d %d\n",1, 1);
			continue;
		}
		for (i= 1;i<=lb;i++){
			int base= 1;
			for (j= 1;j<=n;j++)
				f[i][j]= f[i-1][j];
			while (base<=n){
				f[i][base]= base;
				for (j= base;j<=n;j++){
					f[i][j]= max(f[i][j],f[i-1][j-base]*base);
					M= max(M,f[i][j]);
				}
				base*= stb[i];
			}
		}
		la= 0;m= M;
		for (i= 2;i*i<=m&&m>1;i++)
			if (m%i==0){
				a[++la]= 1;
				while (m%i==0){
					a[la]*= i;
					m/= i;
				}
			}
		if (m!=1) a[++la]= m;
		int sum= 0;
		for (i= 1;i<=la;i++) sum+= a[i];
		for (i= 1;i<=n-sum;i++) a[++la]= 1;
		sort(a+1,a+la+1);
		now= 0;
		printf("%lld",M);
		for (i= 1;i<=la;i++){
			now++;
			for (j= now;j<now+a[i]-1;j++)
				printf(" %d",j+1);
			printf(" %d",now);
			now= now+a[i]-1;
		}printf("\n");
	}return 0;
}
