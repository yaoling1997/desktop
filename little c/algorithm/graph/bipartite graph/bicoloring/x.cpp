#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3001;
int d[maxn],head[maxn],des[maxn],next[maxn];
int x,y,top,i,n,m;
bool bl;
void dfs(int o,int g){
	d[o]= g;
	int p= head[o];
	while (p){
		if (d[des[p]]!=-1){
			if (d[des[p]]!=(g^1)) bl= 0;
		}else dfs(des[p],g^1);
		if (!bl) return;
		p= next[p];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	bl= 1;
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		top++;
		next[top]= head[x];
		head[x]= top;
		des[top]= y;
		top++;
		next[top]= head[y];
		head[y]= top;
		des[top]= x;
	}
	for (i= 1;i<=n;i++) d[i]= -1;
	dfs(1,1);
	if (bl)	printf("yes");
	else printf("no");
	return 0;
}
