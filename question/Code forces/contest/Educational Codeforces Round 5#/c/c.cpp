#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 1e3+10,maxm= 1e6+10;
char s[maxn][maxn];
int B[maxn][maxn],sta[maxn];
int X[5],Y[5];
int f[maxm],sum[maxm],vis[maxm];
int n,m,i,j,k,tot,la,ans,x,y;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%s",s[i]+1);
	X[1]= 1;
	X[2]= -1;
	Y[3]= 1;
	Y[4]= -1;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			B[i][j]= ++tot;
	for (i= 1;i<=tot;i++)
		f[i]= i;
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++)
			if (s[i][j]=='.')
				for (k= 1;k<=4;k++){
					int xx= i+X[k],yy= j+Y[k];
					if (s[xx][yy]=='.'){
						x= B[i][j];
						y= B[xx][yy];
						find(x);
						find(y);
						f[f[x]]= f[y];
					}
				}
	}
	for (i= 1;i<=tot;i++){
		find(i);
		sum[f[i]]++;
	}
	for (i= 1;i<=n;i++){
		for (j= 1;j<=m;j++)
			if (s[i][j]=='.') printf(".");
			else {
				ans= 1;
				for (k= 1;k<=4;k++){
					int xx= i+X[k],yy= j+Y[k];
					if (s[xx][yy]!='.') continue;
					x= f[B[xx][yy]];
					if (vis[x]) continue;
					vis[x]= 1;
					sta[++la]= x;
					ans+= sum[x];
				}
				printf("%d",ans%10);
				while (la)
					vis[sta[la--]]= 0;
			}
		printf("\n");
	}
	return 0;
}
