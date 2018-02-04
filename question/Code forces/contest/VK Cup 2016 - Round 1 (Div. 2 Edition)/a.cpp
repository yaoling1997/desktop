#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int p[maxn],t[maxn];
int n,c,i,j,a,b,ta,tb;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &c);
	for (i= 1;i<=n;i++)
		scanf("%d",&p[i]);
	for (i= 1;i<=n;i++)
		scanf("%d",&t[i]);
	for (i= 1;i<=n;i++){
		ta+= t[i];
		tb+= t[n-i+1];
		a+= max(p[i]-ta*c,0);
		b+= max(p[n-i+1]-tb*c,0);
	}
	if (a==b) printf("Tie");
	else if (a>b) printf("Limak");
	else printf("Radewoosh");
	return 0;
}