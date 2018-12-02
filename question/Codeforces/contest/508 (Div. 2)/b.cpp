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
int a[2][maxn];
int la[2],n;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	if (n<=2)
		printf("No");
	else {
		printf("Yes\n");
		int p=0;
		for (int i=1;i<=(n+1)/2;i++){
			a[p][++la[p]]=i;
			int j=n-i+1;
			if (i!=j)
				a[p][++la[p]]=j;
			p^=1;
		}
		for (int i=0;i<2;i++){
			printf("%d ",la[i]);
			for (int j=1;j<=la[i];j++)
				printf("%d%c",a[i][j],j<la[i]?' ':'\n');
		}
	}
}
