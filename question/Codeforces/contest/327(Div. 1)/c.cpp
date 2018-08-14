#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn= 1100,oo= 1e7;
struct Move{
	int x,y;
};
struct node{
	int x,y,s;
};
queue<node> Q;
Move M[5];
char s[maxn][maxn];
int f[5]= {0},F[4][maxn][maxn],b[5];
int opt,n,m,i,j,k,x,y,ans;
int find(int o){
	if (f[o]==o) return o;
	return f[o]= find(f[o]);
}
bool isdig(char x){
	return '1'<=x && x<='3';
}
void deal(char x1,char x2){
	int a= x1-'0',b= x2-'0';
	find(a),find(b);
	if (f[a]==f[b]) return;
	f[f[a]]= f[b];
}
int judge(){
	int i,j,k;
	for (i= 1;i<=3;i++)
		f[i]= i;
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++){
			if (!isdig(s[i][j])) continue;
			for (k= 1;k<=4;k++)
				if (isdig(s[i+M[k].x][j+M[k].y]))
					deal(s[i+M[k].x][j+M[k].y],s[i][j]);				
		}
	find(1);
	find(2);
	find(3);
	if (f[1]==f[2]&&f[2]==f[3]) return 1;
	if (f[1]!=f[2]&&f[2]!=f[3]&&f[3]!=f[1]) return 3;
	return 2;
}
void bfs(int o){
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		int i,xx,yy;
		for (i= 1;i<=4;i++){
			xx= u.x+M[i].x;
			yy= u.y+M[i].y;
			if (s[xx][yy]=='.'&&F[o][xx][yy]==oo){
				F[o][xx][yy]= u.s+1;
				Q.push((node){xx,yy,u.s+1});
			}
		}
	}
}
void init(){
	int i,j,k;
	M[1].x= 1;
	M[2].x= -1;
	M[3].y= 1;
	M[4].y= -1;
	for (i= 1;i<=3;i++)
		for (j= 1;j<=n;j++)
			for (k= 1;k<=m;k++)
				F[i][j][k]= oo;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	init();
	for (i= 1;i<=n;i++){
		scanf("%s",s[i]+1);
		s[i][0]= s[i][m+1]= '#';
	}
	for (i= 0;i<=m+1;i++)
		s[0][i]= s[n+1][i]= '#';
	opt= judge();
	ans= oo;
	if (opt==1){
		printf("0\n");
	}else if (opt==2){
		for (i= 1;i<=3;i++){
			if (b[f[i]]) continue;
			b[f[i]]= 1;
			for (j= 1;j<=n;j++)
				for (k= 1;k<=m;k++)
					if (f[s[j][k]-'0']==f[i])
						Q.push((node){j,k,0});
			bfs(f[i]);
		}
		x= f[1];
		y= f[2];
		if (x==y) y= f[3];
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++)
				ans= min(ans,F[x][i][j]+F[y][i][j]);
		if (ans>oo/10) printf("-1\n");
		else printf("%d\n",ans-1);		
	}else {
		for (i= 1;i<=3;i++){
			for (j= 1;j<=n;j++)
				for (k= 1;k<=m;k++)
					if (s[j][k]==i+'0')
						Q.push((node){j,k,0});
			bfs(i);
		}
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++)
				if (s[i][j]=='.')
					ans= min(ans,F[1][i][j]+F[2][i][j]+F[3][i][j]);
		ans-= 2;
		int p[4]= {0,1,2,3},z,xx,yy;
		for (i= 1;i<=3;i++){
			x= oo;y= oo;
			for (j= 1;j<=n;j++)
				for (k= 1;k<=m;k++)
					if (s[j][k]==p[1]+'0')
						for (z= 1;z<=4;z++){
							xx= j+M[z].x;yy= k+M[z].y;
							if (s[xx][yy]!='.') continue;
							x= min(x,F[p[2]][xx][yy]);
							y= min(y,F[p[3]][xx][yy]);
						}
			ans= min(ans,x+y);
			if (i==1) swap(p[1],p[2]);
			else swap(p[1],p[3]);
		}
		if (ans>oo/10) printf("-1\n");
		else printf("%d\n",ans);
	}return 0;
}
