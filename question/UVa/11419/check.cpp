#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 300;
int a[maxn][maxn];
char s[20];
int R,C,n,i,j,x,y,ans,len;
int main()
{
	freopen("1.in","r",stdin);
	scanf("%d%d%d",&R, &C, &n);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		a[x][y]= 1;
	}
	fclose(stdin);
	freopen("1.out","r",stdin);
	freopen("check.out","w",stdout);
	scanf("%d",&ans);
	for (i= 1;i<=ans;i++){
		scanf("%s",s+1);
		len= strlen(s+1);
		x= 0;
		for (j= 2;j<=len;j++)
			x= x*10+s[j]-'0';
		if (s[1]=='r'){
			for (j= 1;j<=C;j++)
				a[x][j]= 0;
		}else {
			for (j= 1;j<=R;j++)
				a[j][x]= 0;			
		}
	}
	for (i= 1;i<=R;i++)
		for (j= 1;j<=C;j++)
			if (a[i][j]){
				printf("shit!");
				return 0;
			}
	printf("ok");
	return 0;
}
