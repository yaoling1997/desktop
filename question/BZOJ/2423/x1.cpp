#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn= 3001;
char a[maxn],b[maxn],c[maxn],d[maxn];
int top,tot,ans,sum,i,j,lena,lenb;
void go(){
	if (top!=tot) return;
	for (i= 1;i<=top;i++)
		if (c[i]!=d[i]) return;
	if (ans<top){
		ans= top;
		sum= 1;
	}else if (ans==top)
		sum++;	
}
void dfs1(int o){
	if (o>lenb){
		go();
		return;
	}
	d[++tot]= b[o];
	dfs1(o+1);
	tot--;
	dfs1(o+1);
}
void dfs(int o){
	if (o>lena){
		dfs1(1);
		return;
	}
	c[++top]= a[o];
	dfs(o+1);
	top--;
	dfs(o+1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%s",a+1);
	scanf("%s",b+1);
	lena= strlen(a+1);
	lenb= strlen(b+1);
	a[lena--]= '\0';
	b[lenb--]= '\0';
	dfs(1);
	printf("%d\n%d\n",ans,sum);
	return 0;
}
