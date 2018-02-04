#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 300;
struct node{
	int o,x,y;
}a[maxn];
char s[10][maxn];
int f[10][maxn];
int i,j,k,o,x,y,z,K,cnt,t,n;
void init(){
	cnt= 0;
	memset(f,0,sizeof(f));
}
void update(int &res,int x,int y,int xx,int yy){
	int bl= 1,k;	
	for (k= 1;k<=K;k++)
		if (xx==a[k].o&&a[k].x+2<=yy&&yy<=a[k].y+2){
			bl= 0;
			break;
		}
	if (bl)
		res|= f[x][y];	
}
int main()
{
	scanf("%d",&t);
	for (int T= 1;T<=t;T++){
		scanf("%d%d",&n, &K);
		init();
		for (i= 1;i<=3;i++){
			scanf("%s",s[i]+1);
			for (j= 1;j<=n;j++)
				if ('A'<=s[i][j]&&s[i][j]<='Z'){
					for (k= j+1;k<=n;k++)
						if (s[i][j]!=s[i][k]) break;
					a[++cnt]= (node){i,j,k-1};
					j= k-1;
				}
		}
		for (i= 1;i<=3;i++)
			f[i][1]= s[i][1]=='s';
		for (i= 2;i<=n;i++){
			for (j= 1;j<=K;j++)
				a[j].x-= 2,a[j].y-= 2;
			for (j= 1;j<=3;j++){
				f[j][i]= f[j][i-1];
				update(f[j][i],j-1,i-1,j-1,i);
				update(f[j][i],j+1,i-1,j+1,i);
				for (k= 1;k<=K;k++)
					if (j==a[k].o&&a[k].x<=i&&i<=a[k].y+2){
						f[j][i]= 0;
						break;
					}
			}
		}
		if (f[1][n]|f[2][n]|f[3][n])
			printf("YES\n");
		else printf("NO\n");
	}return 0;
}
