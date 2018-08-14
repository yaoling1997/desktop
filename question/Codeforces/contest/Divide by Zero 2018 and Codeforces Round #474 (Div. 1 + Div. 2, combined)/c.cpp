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
ll sta[maxn];
ll now=1;
int X,d,la;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&X, &d);
	int i=0;
	while (X){
		if (X&1){
			for (int j=1;j<=i;j++)
				sta[++la]=now;
			now+=d;
			sta[++la]=now;
			now+=d;
		}
		X>>=1;
		i++;
	}
	printf("%d\n",la);
	for (int i=1;i<=la;i++)
		printf("%I64d%c",sta[i],i<la?' ':'\n');
	return 0;
}
