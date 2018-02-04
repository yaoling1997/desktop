#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 15,maxm= 1001;
ll f[maxn][maxn*maxn][maxm];
int st[maxm],a[maxn],b[maxn],gg[maxm];
ll ans;
int n,K,i,j,k,z,x,num,top,bl;
void prepare(int o,int s,int k){
	if (o<n){
		prepare(o+1,s,k);
		if (s & 1<<(o-1));
		else prepare(o+1,s^(1<<o),k+1);
	}else st[++top]= s,gg[top]= k;
}
int main()
{
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &K);
	if (n==1){
		if (K==1) printf("1");
		else printf("0");
	}
	prepare(1,0,0);
	prepare(1,1,1);
	f[0][0][1]= 1;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=top;j++){
			for (k= 1;k<=n;k++)
				a[k]= st[j]&(1<<(k-1))? 1:0;
			for (x= 0;x<=K;x++){
				for (k= 1;k<=top;k++){
					for (z= 1;z<=n;z++)
						b[z]= st[k]&(1<<(z-1))? 1:0;
					bl= 1;
					for (z= 1;z<=n;z++)
						if (a[z])
							if (b[z-1]==1||b[z]==1||b[z+1]==1){
								bl= 0;
								break;
							}
					if (bl&&x-gg[j]>=0) f[i][x][j]+= f[i-1][x-gg[j]][k];
				}
			}
		}
	for (i= 1;i<=top;i++)
		ans+= f[n][K][i];
	printf("%lld",ans);
	return 0;
}
