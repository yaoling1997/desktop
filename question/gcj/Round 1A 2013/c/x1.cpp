#include<cstdio>
#include<cstdlib>
#include<algorithm>
//#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e4;
map<ll,ll> X[maxn];
ld ans[maxn];
ll a[maxn][20],b[maxn][20],C[13];
ll d[20],e[20],P[maxn];
ll p,O;
int T;
int R,n,M,K,tot,i,j,k;
void get(ll o,ll r){
	ll i,j,x;
	if (!r){
		tot++;
		P[tot]= C[n];
		x= 0;
		for (i= 2;i<=M;i++){
			b[tot][i]= d[i];
			P[tot]/= C[d[i]];
		}
		for (i= 2;i<=M;i++)
			for (j= 1;j<=d[i];j++)
				a[tot][++x]= i;
		sort(a[tot]+1,a[tot]+n+1);
		return;
	}
	if (o>M) return;
	for (i= r;i>=0;i--){
		d[o]= i;
		get(o+1,r-i);
	}
}
void deal(ll o,ll s,ll x){
	if (s>12){
		X[o][x]++;
		return;
	}
	d[s]= 1;
	deal(o,s+1,x*a[o][s]);
	d[s]= 0;
	deal(o,s+1,x);
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	int beginT= clock();
	scanf("%d",&T);	
	C[0]= 1;
	for (i= 1;i<=12;i++)
		C[i]= C[i-1]*i;
	for (int t= 1;t<=T;t++){
		printf("Case #%d:\n",t);
		scanf("%d%d%d%d",&R, &n, &M, &K);
		get(2,n);
		for (i= 1;i<=tot;i++)
			deal(i,1,1);
		for (int r= 1;r<=R;r++){
			for (i= 1;i<=tot;i++)
				ans[i]= P[i];
				//ans[i]= 0;
			for (k= 1;k<=K;k++){
				//cin>>p;
				scanf("%I64d",&p);
				for (i= 1;i<=tot;i++)
					ans[i]= ans[i]*X[i][p];
					//ans[i]+= log(P[i])+log(X[i][p]);
			}
			j= 1;
			for (i= 2;i<=tot;i++)
				if (ans[i]>ans[j])
					j= i;
			for (i= 1;i<=n;i++){
				//cout<<a[j][i];
				printf("%I64d",a[j][i]);
			}
			printf("\n");
		}
	}
	int endT= clock();
	//printf("%.2lf\n",(endT-beginT)/1000.0);
	return 0;
}
