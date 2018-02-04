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
char s[maxn];
int b[maxn];
int N,J,T,i,j,n;
bool ok(){
	int i,j;
	ll x;
	for (i= 2;i<=10;i++){
		if (b[i]==0||b[i]==x||b[i]==1) return 0;		
		x= 0;
		for (j= 1;j<=N;j++){
			x= x*i+s[j]-'0';
			x%= b[i];
		}
		if (x) return 0;
	}return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	scanf("%d",&T);
	scanf("%d%d",&N, &J);
	fclose(stdin);
	freopen("1.out","r",stdin);
	freopen("check.out","w",stdout);
	scanf("%s%s",s+1,s+1);
	for (i= 1;i<=J;i++){
		scanf("%s",s+1);
		n= strlen(s+1);
		for (j= 2;j<=10;j++)
			scanf("%d",&b[j]);
		if (!ok()){
			printf("shit!\n");
			return 0;
		}
	}
	printf("ok");
	return 0;
}
