#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxl= 300,oo= 1e8;
struct node{
	int x,d;
	bool operator <(const node &a)const{return d<a.d;}
	bool operator >(const node &a)const{return d>a.d;}	
};
struct que{
	node a[maxl];
	int f,r;
	void clear(){f= r= 0;}
	void push(node u){
		while (f<r){
			if (a[r].d>u.d) break;
			r--;
		}a[++r]= u;
	}
	void pop(){f++;}
	node top(){return a[f+1];}
};
que Q;
int f[2][maxl][maxl],l[maxl][2];
char s[maxl][maxl];
node u;
int n,m,K,i,j,k,ans,x,y,z,o,p,to,to1;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d %d %d",&n, &m, &x, &y, &K);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			f[0][i][j]= -oo;
	f[0][x][y]= 0;
	for (i= 1;i<=n;i++)	scanf("%s",s[i]+1);
	for (i= 1;i<=K;i++){
		scanf("%d %d %d",&x, &y, &z);
		l[i][0]= y-x+1;l[i][1]= z;
	}o= 0;p= 1;
	for (k= 1;k<=K;k++){
		o^= 1;p^= 1;x= l[k][0],y= l[k][1];
		for (i= 1;i<=n;i++)
			for (j= 1;j<=m;j++) f[o][i][j]= -oo;
		if (y==1){
			for (j= 1;j<=m;j++){
				for (i= n;i>0;i--)
					if (s[i][j]=='.'){
						Q.push((node){i,f[p][i][j]+i});
						for (;;){
							u= Q.top();
							if (u.x-i>x) Q.pop();
							else break;
						}						
						f[o][i][j]= f[p][u.x][j]+u.x-i;
					}else Q.clear();
				}
		}else if (y==2){
			for (j= 1;j<=m;j++){
				Q.clear();
				for (i= 1;i<=n;i++)
					if (s[i][j]=='.'){
						Q.push((node){i,f[p][i][j]-i});
						for (;;){
							u= Q.top();
							if (i-u.x>x) Q.pop();
							else break;
						}
						
						f[o][i][j]= f[p][u.x][j]+i-u.x;
					}else Q.clear();
			}			
		}else if (y==3){
			for (i= 1;i<=n;i++){
				Q.clear();
				for (j= m;j>0;j--)
					if (s[i][j]=='.'){
						Q.push((node){j,f[p][i][j]+j});
						for (;;){
							u= Q.top();
							if (u.x-j>x) Q.pop();
							else break;
						}
						f[o][i][j]= f[p][i][u.x]+u.x-j;
					}else Q.clear();
			}			
		}else {
			for (i= 1;i<=n;i++){
				Q.clear();
				for (j= 1;j<=m;j++)
					if (s[i][j]=='.'){
						Q.push((node){j,f[p][i][j]-j});
						for (;;){
							u= Q.top();
							if (j-u.x>x) Q.pop();
							else break;
						}
						f[o][i][j]= f[p][i][u.x]+j-u.x;
					}else Q.clear();
			}						
		}
	}
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			ans= max(ans,f[o][i][j]);
	printf("%d",ans);
	return 0;
}
