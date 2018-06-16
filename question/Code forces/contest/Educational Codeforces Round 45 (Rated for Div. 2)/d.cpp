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
const int maxn= 2000;
int m[maxn][maxn];
int n,a,b,bl;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&n, &a, &b);
	if (a<b){
		swap(a,b);
		bl=1;
	}
	if (b!=1||(a==1&&(n==2||n==3))){
		printf("NO");
	}else {
		printf("YES\n");
		if (a==1){
			for (int i=1;i<n;i++)
				m[i][i+1]=m[i+1][i]=1;
		}else {
			for (int i=2;i<=2+n-a-1;i++)
				m[1][i]=m[i][1]=1;
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				int x=i==j?0:bl;
				printf("%d",m[i][j]^x);
			}
			printf("\n");
		}				
	}
	return 0;
}
