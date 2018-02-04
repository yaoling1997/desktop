#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[4][100],k[4];
int na,nb,nc,i,j;
char s[100];
void xx(int o)
{
	k[o]= strlen(s+1);
	for (int i= 1;i<=k[o];i++)
		a[o][k[o]-i+1]=s[i]-48;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	for (i= 1;i<=2;i++){
		memset(s,0,sizeof(s));
		scanf("%s\n",s+1);
		xx(i);
	}
	for (i= 1;i<=k[1];i++)
		for (j= 1;j<=k[2];j++)
			a[3][i+j-1]+=a[1][i]*a[2][j];
    k[3]= k[2]+k[1]-1;
	for (i= 1;i<=k[3];i++){
		a[3][i+1]+=a[3][i]/10;
		a[3][i]%=10;
	}
	while (a[3][k[3]+1]!=0){
		k[3]++;
		a[3][k[3]+1]+=a[3][k[3]]/10;
		a[3][k[3]]%=10;
	}
	for (i= k[3];i>0;i--)
		printf("%d",a[3][i]);
	return 0;	
}
