#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int a[20];
ll f[20][10][5];
int T;
ll solve(ll x){
	if (x==0)
		return 1;
	ll re=0;
	int L=0,nc=0;
	while (x){
		a[++L]=x%10;
		x/=10;
	}
	if (!L)
		a[++L]=0;
	re=1;
	for (int i=1;i<L;i++)
		for (int j=1;j<=9;j++)
			for (int k=1;k<=3;k++)
				re+=f[i][j][k];
	int i=L;
	while (nc<=3&&i){
		for (int j=0;j<a[i];j++){
			if (j==0&&i==L)
				continue;
			for (int k=0;k<=3-nc;k++)
				re+=f[i][j][k];
		}
		if (a[i])
			nc++;
		i--;
	}
	if (nc<=3)
		re++;
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	f[1][0][0]=1;
	for (int i=1;i<=9;i++)
		f[1][i][1]=1;
	for (int i=2;i<=19;i++)
		for (int j=0;j<=9;j++)
			for (int k=0;k<=3;k++){
				if (j==0){
					for (int z=0;z<=9;z++)
						f[i][j][k]+=f[i-1][z][k];
				}else if (k){
					for (int z=0;z<=9;z++)
						f[i][j][k]+=f[i-1][z][k-1];
				}
			}
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		ll x,y,ans;
		scanf("%I64d%I64d",&x, &y);
		ans=solve(y)-solve(x-1);
		printf("%I64d\n",ans);
	}
	return 0;
}
