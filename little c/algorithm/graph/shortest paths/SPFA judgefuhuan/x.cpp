#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn= 3001,oo= 99999999;
int l[maxn],des[maxn],w[maxn],next[maxn],head[maxn],d[maxn],dg[maxn];
int x,y,z,i,top,f,r,n,m;
bool bl;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d\n",&n, &m);
	bl= 1;
	for (i= 1;i<=m;i++){
		scanf("%d %d %d",&x, &y, &z);
		top++;
		next[top]= head[x];
		head[x]= top;
		des[top]= y;
		w[top]= z;
	}
	for (i= 1;i<=n;i++) d[i]= oo;
	d[1]= 0;
	f= 0;r= 1;dg[1]= y;
	l[1]= 1;
	while (f<r){
		f++;
		int u= l[f],p= head[u];
		while (p!=0){
			if (d[des[p]]>d[u]+w[p]){
				l[++r]= des[p];
				d[des[p]]= d[u]+w[p];
				dg[des[p]]++;
				if (dg[des[p]]>n) {
					bl= 0;
					goto pop;
				}
			}
			p= next[p];
		}
	}
 pop:
	if (!bl) printf("yes");
	else printf("no");
	return 0;
}
