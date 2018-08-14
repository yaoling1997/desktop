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
const int maxn= 5e5,M= 1050;
int f[1100],g[1100];
int n,k,X,i,j,Max,Min;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &k, &X);
	for (i= 1;i<=n;i++){
		int y;
		scanf("%d",&y);
		f[y]++;
	}
	for (i= 1;i<=k;i++){
		int sum= 0;
		memset(g,0,sizeof(g));
		for (j= 0;j<=M;j++)
			if (f[j]){
				int x= (f[j]+1)/2,y= f[j]-x;
				if (sum%2)
					swap(x,y);
				g[j^X]+= x;
				g[j]+= y;
				sum+= f[j];
			}
		swap(f,g);
	}
	Min= -1;
	for (i= 0;i<=M;i++)
		if (f[i]){
			if (Min==-1)
				Min= i;
			Max= i;
		}
	printf("%d %d",Max, Min);
	return 0;
}