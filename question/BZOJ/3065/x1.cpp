#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 40000;
struct point{
	int x,y,b;
};
struct edge{
	int u,v,d;
	bool operator <(const edge &a)const{
		return d<a.d;
	}
};
point p[maxn];
edge l[maxn];
int f[maxn],use[maxn];
int ans,top,n,i,j;
int find(int o){
	if (o== f[o]) return o;
	return f[o]= find(f[o]);
}
int kruskal(){
	int i,re= 0;
	sort(l+1,l+top+1);
	for (i= 1;i<=n;i++)
		f[i]= i;
	for (i= 1;i<=top;i++){
		int u= l[i].u,v= l[i].v;
		if (find(u)!=find(v)){
			f[f[u]]= f[v];
			use[i]= 1;
			re+= l[i].d;
		}
	}return re;
}
void addedge(point a,point b){
	int d= abs(a.x-b.x)+abs(a.y-b.y);
	int x= min(a.b,b.b),y= max(a.b,b.b);
	l[++top]= (edge){x,y,d};
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		scanf("%d %d",&p[i].x, &p[i].y);
		p[i].b= i;
		for (j= 1;j<i;j++)
			addedge(p[i],p[j]);
	}
	ans= kruskal();
	printf("%d",ans);
	return 0;
}
