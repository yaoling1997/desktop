#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 3e5;
char s[maxn];
char a[100];
char x[5],y[5];
int n,m,i,j,p,q;
int idx(char c){
	return c-'a';
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	scanf("%s",s+1);
	for (i= 0;i<=25;i++)
		a[i]= 'a'+i;
	for (i= 1;i<=m;i++){
		scanf("%s%s",x+1, y+1);
		for (j= 0;j<=25;j++){
			if (a[j]==x[1]) p= j;
			if (a[j]==y[1]) q= j;
		}
		swap(a[p],a[q]);
	}
	for (i= 1;i<=n;i++)
		printf("%c",a[idx(s[i])]);
	return 0;
}
