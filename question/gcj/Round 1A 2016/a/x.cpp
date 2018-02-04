#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e4;
char a[maxn];
char s[maxn];
int l,r,m= 1e4,T,len,i;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%s",s+1);
		len= strlen(s+1);
		l= m;r= m;
		a[l]= s[1];
		for (i= 2;i<=len;i++)
			if (s[i]>=a[l]) a[--l]= s[i];
			else a[++r]= s[i];
		for (i= l;i<=r;i++)
			printf("%c",a[i]);
		printf("\n");
	}return 0;
}
