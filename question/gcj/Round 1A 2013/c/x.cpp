#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e3;
int a[20],b[20],sta[20];
int R,n,M,K,i,j,la,now,T,x;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d:\n",t);
		scanf("%d%d%d%d",&R, &n, &M, &K);
		for (int r= 1;r<=R;r++){
			memset(b,0,sizeof(b));
			la= 0;			
			for (i= 1;i<=K;i++){
				scanf("%d",&a[i]);
				for (j= 2;j<=M;j++){
					x= a[i];
					now= 0;
					while (x%j==0){
						x/= j;
						now++;
					}
					b[j]= max(b[j],now);
				}
			}
			for (i= M;i>2;i--)
				while (b[i]){
					sta[++la]= i;
					b[i]--;
				}
			while (la<n)
				sta[++la]= 2;
			for (i= 1;i<=n;i++)
				printf("%d",sta[i]);
			printf("\n");
		}
	}return 0;
}
