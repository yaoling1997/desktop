#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 2e5;
struct edge{
	int v,h,x,y;
};
edge ans[maxn],In[maxn],out[maxn];
int i,j,k,la,top,tot,cnt,bl,n,m,x,y;
bool cmp(edge a,edge b){
	return a.v<b.v;
}
bool cmp1(edge a,edge b){
	return a.h<b.h;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=m;i++){
		scanf("%d%d",&x, &y);
		if (y){
			In[++top]= (edge){x,i,0,0};
		}else out[++tot]= (edge){x,i,0,0};
	}
	sort(In+1,In+top+1,cmp);
	sort(out+1,out+tot+1,cmp);
	for (i= 1;i<n;i++)
		In[i].x= i,In[i].y= i+1;
	j= 1;
	bl= 1;
	for (i= 3;i<=n;i++){
		if (j>tot) break;		
		for (k= 1;k+1<i;k++){
			if (out[j].v>=In[i-1].v){
				out[j].x= k;
				out[j].y= i;
				j++;
				if (j>tot) break;
			}else {
				bl= 0;
				break;
			}
		}
		if (!bl) break;
	}
	if (!bl){
		printf("-1");
		return 0;
	}
	for (i= 1;i<=top;i++){
		ans[In[i].h].x= In[i].x;
		ans[In[i].h].y= In[i].y;
	}
	for (i= 1;i<=tot;i++){
		ans[out[i].h].x= out[i].x;
		ans[out[i].h].y= out[i].y;
	}
	for (i= 1;i<=m;i++)
		printf("%d %d\n",ans[i].x, ans[i].y);
	return 0;
}
