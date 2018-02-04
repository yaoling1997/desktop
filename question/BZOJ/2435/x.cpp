#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
#define gc getchar
using namespace std;
const int maxn= 2e6,maxm= 2e6;
struct node{
	int o,fa,i;
};
struct node1{
	int o,fa,s,i;
};
node a[maxn];
node1 A[maxn];
int size[maxn],head[maxm],next[maxm],des[maxm],w[maxm],vis[maxn];
ll ans,top,tot;
int x,y,z,i,n;
void dfs(){
	top= 1;
	a[1]= (node){1,0,head[1]};
	size[1]= 1;
	while (top){
	pn:
		int o= a[top].o,fa= a[top].fa,&i= a[top].i;
		if (size[des[i]]){
			if (des[i]!=fa) size[o]+= size[des[i]];
			i= next[i];
		}
		for (;i;i= next[i]){
			int v= des[i];
			if (v!=fa){
				a[++top]= (node){v,o,head[v]};
				size[v]= 1;				
				goto pn;
			}
		}top--;
	}
}
void DFS(){
	top= 1;
	A[1]= (node1){1,0,0,head[1]};
	while (top){
	pn1:
		int o= A[top].o,fa= A[top].fa,s= A[top].s,&i= A[top].i;
		if (vis[des[i]]) i= next[i];
		for (;i;i= next[i]){
			int v= des[i];
			if (v!=fa){
				ans+= (ll)abs(s+size[o]-2*size[v])*w[i];
				A[++top]= (node1){v,o,s+size[o]-size[v],head[v]};
				vis[v]= 1;
				goto pn1;
			}
		}top--;
	}
}
int gi(){
	char c= gc();int re= 0;
	while (c<'0'||c>'9') c= gc();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= gc();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n= gi();
	for (i= 1;i<n;i++){
		//scanf("%d %d %d",&x, &y, &z);
		x= gi();y= gi();z= gi();
		next[++tot]= head[x];
		des[tot]= y;
		w[tot]= z;
		head[x]= tot;
		next[++tot]= head[y];
		des[tot]= x;
		w[tot]= z;
		head[y]= tot;
	}
	dfs();
	DFS();
	printf("%lld",ans);
	return 0;
}
