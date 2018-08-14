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
int c[maxn];
int n,a,b,cnt,la,ans;
int solve(int x,int y){
	if (x==a&&y==b)
		ans=cnt;
	if (x==b&&y==a)
		ans=cnt;
	if (x==a||x==b)
		return x;
	else return y;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &a, &b);	
	for (int i=1;i<=n;i++)
		c[i]=i;
	while (n>1){
		cnt++;
		for (int i=1;i<=n;i+=2){
			c[++la]=solve(c[i],c[i+1]);
		}
		n=la;
		la=0;
	}
	if (ans==cnt)
		printf("Final!");
	else printf("%d",ans);
}
