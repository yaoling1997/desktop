#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int maxn= 2e6,oo= 2e9;
struct line{
	int x,y;
}a[maxn];
struct point{
	int o,x;
}P[maxn];
int n,x,y,i,j,k,K,la,cnt,tot,now,p,q;
bool cmp(point a,point b){
	return a.x<b.x;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &K);
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		P[++la]= (point){1,x};
		P[++la]= (point){-1,y};
	}
	sort(P+1,P+la+1,cmp);
	p= q= -oo;
	for (i= 1;i<=la;i= j){
		j= i;
		while (j<=la&&P[j].x==P[i].x) j++;
		for (k= i;k<j;k++)
			if (P[k].o==1) now++;
		if (now>=K){
			if (p==-oo) p= q= P[i].x;
			else q= P[i].x;
		}
		for (k= i;k<j;k++)
			if (P[k].o==-1) now--;
		if (now<K){
			if (p!=-oo){
				a[++tot]= (line){p,q};
				p= q= -oo;
			}
		}		
	}
	printf("%d\n",tot);
	for (i= 1;i<=tot;i++)
		printf("%d %d\n",a[i].x, a[i].y);
	return 0;
}
