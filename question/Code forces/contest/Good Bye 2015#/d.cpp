#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn= 5e3+10,mo= 1e9+7;
ll f[maxn][maxn],sum[maxn][maxn];
char s[maxn];
ull h[maxn],D[maxn];
ull B= 37;
ll ans;
int n,i,j;
ll S(int a,int b){
	if (a<0) return 0;
	return sum[a][b];
}
bool ok(int a,int b,int c,int d){
	if (c<0) return 0;
	if (h[b]-h[a-1]*D[b-a+1]==h[d]-h[c-1]*D[d-c+1]) return 0;
	int l= 0,r= b-a+1;
	while (l+1<r){
		int m= (l+r)>>1;
		if (h[a+m-1]-h[a-1]*D[m]==h[c+m-1]-h[c-1]*D[m]) l= m;
		else r= m;
	}
	return s[a+l]>s[c+l];
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	D[0]= 1;
	for (i= 1;i<=n;i++){
		h[i]= h[i-1]*B+s[i]-'0';
		D[i]= D[i-1]*B;
	}
	f[0][0]= sum[0][0]= 1;
	for (i= 1;i<=n;i++){
		for (j= i;j<=n;j++){
			sum[i][j]= sum[i-1][j];
			if (s[i]=='0') continue;
			f[i][j]= ((S(i-1,i-1)-S(2*i-j-1,i-1))%mo+mo)%mo;
			if (ok(i,j,2*i-j-1,i-1))
				f[i][j]= (f[i][j]+f[2*i-j-1][i-1])%mo;
			sum[i][j]= (sum[i][j]+f[i][j])%mo;
		}
	}
	for (i= 1;i<=n;i++)
		ans= (ans+f[i][n])%mo;
	printf("%lld\n",ans);
	return 0;
}
