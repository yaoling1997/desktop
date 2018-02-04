#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 6001,oo= 1e8;
struct node{
	int x,y,z;
};
vector<int> g[maxn];
node a[maxn];
int b[maxn],d[maxn],vis[maxn];
int x,T,i,j,k,A,B,C,tot,ans,time;
void init(){
	memset(b,0,sizeof(b));
	tot= 0;
	ans= oo;
}
void getgraph(){
	int i;
	for (i= 1;i<=B;i++) g[i].clear();
	for (i= 1;i<=C;i++) d[i]= 0;
	for (i= 1;i<=tot;i++)
		if (!b[a[i].x])
			g[a[i].y].push_back(a[i].z);			
}
int find(int o){
	int len= g[o].size(),i;
	for (i= 0;i<len;i++){
		int v= g[o][i];
		if (vis[v]!=time){
			vis[v]= time;
			if (!d[v]||find(d[v])){
				d[v]= o;
				return 1;
			}
		}
	}return 0;
}
void go(int o,int s){
	if (s>ans) return;
	if (o>A){
		getgraph();
		int cnt= 0,i;
		for (i= 1;i<=B;i++)
			time++,cnt+= find(i);		
		ans= min(ans,cnt+s);
	}else {
		b[o]= 0;
		go(o+1,s);
		b[o]= 1;
		go(o+1,s+1);
	}			
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d %d %d",&A, &B, &C);
		init();
		for (i= 1;i<=A;i++)
			for (j= 1;j<=B;j++)
				for (k= 1;k<=C;k++){
					scanf("%d",&x);
					if (x) a[++tot]= (node){i,j,k};
				}
		if (B<A&&B<C){
			for (i= 1;i<=tot;i++)
				swap(a[i].y,a[i].x);
			swap(A,B);
		}
		else if (C<A&&C<B){
			for (i= 1;i<=tot;i++)
				swap(a[i].z,a[i].x);
			swap(A,C);
		}
		go(1,0);
		printf("%d\n",ans);
	}return 0;
}
