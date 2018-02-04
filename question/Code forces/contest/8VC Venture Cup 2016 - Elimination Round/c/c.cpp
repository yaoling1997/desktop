#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 1e7,oo= 1e9;
int b[maxn];
int sta[maxn];
int n,m,i,j,la,ans,x,y;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	while (n){
		n--;
		x+= 2;
		b[x]= 1;
		if (x%3==0) sta[++la]= x;
	}
	while (m){
		y+= 3;
		if (!b[y]) m--;
	}
	if (x>=y) printf("%d",x);
	else {
		ans= y;
		while (x<y&&la){
			b[sta[la--]]= 0;
			do y-= 3;
			while (b[y]);
			do x+= 2;
			while (x<=y&&x%3==0);
			b[x]= 1;
			ans= min(ans,max(x,y));
		}
		printf("%d",ans);
	}
}
