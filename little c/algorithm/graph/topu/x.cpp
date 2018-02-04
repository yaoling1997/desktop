#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3000;
int des[maxn],l[maxn],head[maxn],next[maxn],d[maxn];
int i,n,m,x,y,top,f,r;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d %d",&x, &y);
		top++;
		d[y]++;
		next[top]= head[x];
		head[x]= top;
		des[top]= y;
	}
	for (i= 1;i<=n;i++)
		if (!d[i]) l[++r]= i;
	while (f<r){
		f++;printf("%d ",l[f]);
		int p= head[l[f]];
		while (p!=0){
			d[des[p]]--;
			if (d[des[p]]==0) l[++r]= des[p];
			p= next[p];
		}
	}
	return 0;
}
