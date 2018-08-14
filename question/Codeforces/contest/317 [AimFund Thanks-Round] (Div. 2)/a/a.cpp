#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int a[maxn],b[maxn];
int na,nb,i,j,k,m;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&na, &nb);
	scanf("%d%d",&k, &m);
	for (i= 1;i<=na;i++)
		scanf("%d",a+i);
	for (i= 1;i<=nb;i++)
		scanf("%d",b+i);
	if (a[k]<b[nb-m+1]) printf("YES");
	else printf("NO");
}
