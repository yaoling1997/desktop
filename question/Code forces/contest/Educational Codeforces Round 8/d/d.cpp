#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 3e3,mo= 1e9+7;
char a[maxn],b[maxn];
ll f[maxn][maxn][2],D[maxn];
ll m,d,i,j,k,n,ans,A,B,la,lb;
ll get(char *s){
	ll len= strlen(s+1),i,j,re= 0,cnt= 0,x;
	/*for (i= 1;i<len;i++)
	  re= (re+f[i][0][0])%mo;*/
	if (d!=0) re= 1;
	for (i= 1;i<len;i++)
		for (j= 1;j<=9;j++){
			if (j==d) continue;
			ll x= j*D[i-1]%m;
			re= (re+f[i-1][(m-x)%m][1])%mo;
		}
	for (i= 1;i<=len;i++){
		for (j= 0;j<s[i]-'0';j++){
			if (i==1&&j==0) continue;
			if (i&1){
				if (j==d) continue;
				x= (cnt+j*D[len-i])%m;
				re= (re+f[len-i][(m-x)%m][1])%mo;
			}else {
				if (j!=d) continue;
				x= (cnt+j*D[len-i])%m;
				re= (re+f[len-i][(m-x)%m][0])%mo;
			}
		}
		if (i&1){
			if (s[i]-'0'==d) break;
		}else {
			if (s[i]-'0'!=d) break;
		}
		cnt= (cnt+(s[i]-'0')*D[len-i])%m;					
	}
	if (i==len+1&&cnt==0&&!(len==1&&s[1]=='0')) re= (re+1)%mo;
	return re;		
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%lld%lld%s%s",&m, &d, a+1,b+1);
	n= lb= strlen(b+1);
	la= strlen(a+1);
	D[0]= 1;
	for (i= 1;i<=n;i++)
		D[i]= D[i-1]*10%m;
	f[0][0][0]= f[0][0][1]= 1;
	for (i= 1;i<=n;i++)
		for (j= 0;j<=9;j++)
			for (k= 0;k<m;k++){
				if (i&1){
					if (j!=d)
						f[i][(k*10+j)%m][0]= (f[i][(k*10+j)%m][0]+f[i-1][k][0])%mo;
					else f[i][(k*10+j)%m][1]= (f[i][(k*10+j)%m][1]+f[i-1][k][1])%mo;
				}else {
					if (j!=d)
						f[i][(k*10+j)%m][1]= (f[i][(k*10+j)%m][1]+f[i-1][k][1])%mo;
					else f[i][(k*10+j)%m][0]= (f[i][(k*10+j)%m][0]+f[i-1][k][0])%mo;					
				}
		}
	B= get(b);
	if (la==1&&a[1]=='0'){
		A= 0;
	}else {
		a[la]--;
		for (i= la;i>0;i--)
			if (a[i]<'0'){
				a[i]+= 10;
				a[i-1]--;
			}else break;
		if (a[1]=='0'&&la>1){
			for (i= 2;i<=la;i++)
				a[i-1]= a[i];
			a[la]= 0;
			la--;
		}
		A= get(a);
	}
	ans= (B-A+mo)%mo;
	printf("%lld",ans);
	return 0;
}
