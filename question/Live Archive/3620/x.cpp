#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int oo= 1e9;
int n,m,i,j,ans;
struct state{
	int up[10];
	int left;
	int encode(){
		int key= left,i;
		for (i= 1;i<=m;i++)
			key= key*3+up[i];
		return key;
	}
	bool next(int x,int y,int U,int R,int D,int L,state &T){
		if (y==m&&R!=0) return 0;
		if (x==n&&D!=0) return 0;
		int must_left= (y>1&&left!=0);
		int must_up= (x>1&&up[y]!=0);
		if ((must_left&&L!=left)||(!must_left&&L!=0)) return 0;
		if ((must_up&&U!=up[y])||(!must_up&&U!=0)) return 0;
		if (must_up&&must_left&&up[y]!=left) return 0;
		int i;
		//T= init;
		for (i= 1;i<=m;i++)
			T.up[i]= up[i];
		T.left= R;
		T.up[y]= D;
		return 1;
	}
};
state init;
int f[10][10][60000],g[20][20];
int dfs(int x,int y,state S){
	if (y>m){x++;y= 1;}
	if (x>n) return 0;
	int key= S.encode(),&res= f[x][y][key],i;
	if (res!=-1) return res;
	res= oo;
	state T;
	if (g[x][y]<=1){
		if (S.next(x,y,0,0,0,0,T))
			res= min(res,dfs(x,y+1,T));
		if (g[x][y]==0){
			for (i= 1;i<=2;i++){
				if (S.next(x,y,i,i,0,0,T))
					res= min(res,dfs(x,y+1,T)+2);
				if (S.next(x,y,i,0,i,0,T))
					res= min(res,dfs(x,y+1,T)+2);
				if (S.next(x,y,i,0,0,i,T))
					res= min(res,dfs(x,y+1,T)+2);
				if (S.next(x,y,0,i,i,0,T))
					res= min(res,dfs(x,y+1,T)+2);
				if (S.next(x,y,0,i,0,i,T))
					res= min(res,dfs(x,y+1,T)+2);
				if (S.next(x,y,0,0,i,i,T))
					res= min(res,dfs(x,y+1,T)+2);
			}
		}
	}else {
		i= g[x][y]-1;
		if (S.next(x,y,i,0,0,0,T))
			res= min(res,dfs(x,y+1,T)+1);
		if (S.next(x,y,0,i,0,0,T))
			res= min(res,dfs(x,y+1,T)+1);
		if (S.next(x,y,0,0,i,0,T))
			res= min(res,dfs(x,y+1,T)+1);
		if (S.next(x,y,0,0,0,i,T))
			res= min(res,dfs(x,y+1,T)+1);
	}return res;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	while (scanf("%d %d",&n, &m)!=EOF&&n&&m){
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++)
				scanf("%d",&g[i][j]);
		memset(f,-1,sizeof(f));
		ans= dfs(1,1,init);
		if (ans!=oo) printf("%d\n",ans/2);
		else printf("%d\n",0);
	}return 0;
}
