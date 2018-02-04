#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 100;
char d[100];
char a[100][100],b[100][100];
int vis[100],sta[100];
int m,i,j,k,K,C,S,bl,L,T,ooo;
void get(int o){
	if (o>K){
		m++;
		memcpy(a[m],d,sizeof(d));
		memcpy(b[m],d,sizeof(d));
		return;
	}
	d[o]= 'L';
	get(o+1);
	d[o]= 'G';
	get(o+1);
	d[o]= 0;
}
void deal(){
	int i,j,k,len,K= strlen(a[1]+1);
	for (i= 1;i<=m;i++){
		memset(d,0,sizeof(d));
		len= strlen(b[i]+1);
		k= 0;
		for (j= 1;j<=len;j++){
			int x= 0;
			if (b[i][j]=='L'){
				while (x<K){
					x++;
					d[++k]= a[i][x];
				}
			}else {
				while (x<K){
					x++;
					d[++k]= 'G';
				}				
			}
		}
		memcpy(b[i],d,sizeof(d));
	}
}
void check(){
	queue<int> Q[2];
	int i;
	for (i= 1;i<=m;i++)
		Q[0].push(i);
	for (i= 1;i<=S;i++){
		int o= (i-1)%2,n= i%2,x= sta[i];
		while (!Q[o].empty()){
			int u= Q[o].front();
			Q[o].pop();
			if (b[u][x]=='L')
				Q[n].push(u);
		}
	}
	if (Q[S%2].size()==1) bl= 1;
}
void dfs(int o,int r){
	if (r>S){
		ooo++;
		check();
		return;
	}
	if (o>L) return;
	sta[r]= o;
	dfs(o+1,r+1);
	if (bl) return;
	dfs(o+1,r);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		m= 0;
		scanf("%d%d%d",&K, &C, &S);
		get(1);
		for (j= 2;j<=C;j++)
			deal();
		bl= 0;
		L= strlen(b[1]+1);
		dfs(1,1);
		if (bl) printf("YES\n");
		else printf("IMPOSSIBLE\n");
	}return 0;
}
