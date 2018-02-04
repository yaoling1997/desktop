#include<cstdio> 
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 300;
struct edge{
	int x,y,h;
	char c;
};
vector<edge> g[maxn];
vector<edge> G;
int f[maxn],b[maxn],d[maxn],ok[maxn],sta[maxn];
int n,i,j,x,y,z,com,bl,la;
int find(int o){
	if (o==f[o]) return o;
	return f[o]= find(f[o]);
}
void go(int o){
	for (;;){
		int len= g[o].size();
		if (!len) return;
		edge e= g[o][len-1];
		g[o].pop_back();
		if (b[e.h]) continue;
		b[e.h]= 1;
		//printf("%d %c\n",e.h, e.c);
		go(e.y);
		G.push_back(e);		
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=7;i++)
		f[i]= i;	
	for (i= 1;i<=n;i++){
		scanf("%d%d",&x, &y);
		x++;y++;
		ok[x]= ok[y]= 1;
		g[x].push_back((edge){x,y,i,'-'});
		g[y].push_back((edge){y,x,i,'+'});				
		d[x]++;
		d[y]++;
		find(x);
		find(y);
		f[f[x]]= f[y];
	}
	for (i= 1;i<=7;i++)
		if (ok[i]){
			find(i);
			com= f[i];	
		}
	bl= 1;
	for (i= 1;i<=7;i++)
		if (ok[i]){
			if (f[i]!=com){
				bl= 0;	
				break;
			}
			if (d[i]&1)
				sta[++la]= i;
		}		
	if (la>2) bl= 0;
	if (!bl) printf("No solution");
	else {
		if (la) go(sta[1]);
		else for (i= 1;i<=7;i++)
			if (ok[i]){
				go(i);
				break;
			}
		int len= G.size();
		for (i= 0;i<len;i++)
			printf("%d %c\n",G[i].h, G[i].c);				
	}return 0;
}
