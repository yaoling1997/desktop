#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 300001,oo= 1e9;
int a[maxn],c[maxn];
int x,y,z,n,m,i,j,t,ans;
char ch;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d %d",&n, &m);
	c[0]= oo;
	for (i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	for (t= 1;t<=m;t++){
		scanf("%c",&ch);ans= 0;
		while (ch==' '||ch=='\n') scanf("%c",&ch);
		if(ch=='Q'){
			scanf("%d %d %d",&x, &y, &z);
			int g= y-x+1;
			for (i= x;i<=y;i++)
				c[i-x+1]= a[i];
			sort(c+1,c+g+1);
			printf("%d\n",c[z]);
		}else {
			scanf("%d %d",&x, &y);
			a[x]= y;
		}
	}
	return 0;
}
