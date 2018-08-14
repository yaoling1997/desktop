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
const int maxn= 1e6+10;
int s[maxn][20];
int f(int o){
	int re=1;
	while (o){
		int x=o%10;
		o/=10;
		if (x)
			re*=x;
	}
	return re;
}
int g(int o){
	if (o<10)
		return o;
	return g(f(o));
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	for (int i=1;i<=1e6;i++){
		for (int j=1;j<=9;j++)
			s[i][j]=s[i-1][j];
		s[i][g(i)]++;
	}
	int q;
	scanf("%d",&q);
	for (int tt=1;tt<=q;tt++){
		int l,r,k;
		scanf("%d%d%d",&l, &r, &k);
		printf("%d\n",s[r][k]-s[l-1][k]);
	}
	return 0;
}
