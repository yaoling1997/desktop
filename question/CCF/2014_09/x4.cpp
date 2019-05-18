#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 1e6+10;
struct node{
	int x,y,s;
};
struct move{
	int x,y;
}M[4];
queue<node> Q;
int dx[maxn],dy[maxn];
int a[1005][1005],vis[1005][1005];
ll ans;
int n,m,k,d,i;
bool ok(int x,int y){
	if (x<1||x>n||y<1||y>n||a[x][y]<0)
		return 0;
	return 1;
}
ll solve(){
	int i;
	for (i= 1;i<=m;i++){
		Q.push((node){dx[i],dy[i],0});
		a[dx[i]][dy[i]]= 0;
		vis[dx[i]][dy[i]]= 1;
	}
	ll re= 0;
	while (!Q.empty()){
		node u= Q.front();
		Q.pop();
		for (i= 0;i<4;i++){
			int xx= u.x+M[i].x;
			int yy= u.y+M[i].y;
			if (!ok(xx,yy))
				continue;
			if (vis[xx][yy])
				continue;
			vis[xx][yy]= 1;
			if (a[xx][yy]){
				re+= (u.s+1)*a[xx][yy];
				a[xx][yy]= 0;
			}
			Q.push((node){xx,yy,u.s+1});
		}
	}
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	M[0]= (move){-1,0};
	M[1]= (move){0,1};
	M[2]= (move){1,0};
	M[3]= (move){0,-1};	
	scanf("%d%d%d%d",&n, &m, &k, &d);
	for (i= 1;i<=m;i++)
		scanf("%d%d",&dx[i], &dy[i]);
	for (i= 1;i<=k;i++){
		int x,y,z;
		scanf("%d%d%d",&x, &y, &z);
		a[x][y]+= z;
	}
	for (i= 1;i<=d;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		a[x][y]= -1;
	}
	ans= solve();
	cout<<ans;
	return 0;
}

