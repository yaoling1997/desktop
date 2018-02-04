#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn= 1e4,sig= 26,mo= 10007;
struct node{
	int ch[sig+1];
	int v;
};
node a[maxn];
int last[maxn],F[maxn],f[200][maxn][2];
char s[maxn];
int n,m,i,j,k,z,len,now,tot,x,y,bl,ans,sh,ooo;
int idx(char c){return c-'A';}
void update(int &a,int b){
	a+= b;
	a-= a/mo*mo;
}
void getFail(){
	queue<int> Q;
	int i,j;
	F[0]= 0;
	for (i= 0;i<sig;i++){
		int v= a[0].ch[i];
		if (!v) continue;
		Q.push(v);
	}
	while (!Q.empty()){
		int u= Q.front();
		Q.pop();
		for (i= 0;i<sig;i++){
			int v= a[u].ch[i];
			if (!v) continue;
			Q.push(v);
			j= F[u];
			while (j && !a[j].ch[i]) j= F[j];
			F[v]= a[j].ch[i];
			last[v]= a[F[v]].v? F[v]:last[F[v]];
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%s",s+1);
		len= strlen(s+1);now= 0;
		for (j= 1;j<=len;j++){
			int c= idx(s[j]);
			if (a[now].ch[c]) now= a[now].ch[c];
			else {
				a[now].ch[c]= ++tot;
				now= tot;
			}
		}a[now].v= 1;
	}
	getFail();
	f[0][0][0]= 1;
	for (i= 0;i<m;i++)
		for (j= 0;j<=tot;j++)
			for (k= 0;k<=1;k++)
				if (x= f[i][j][k])
					for (z= 0;z<sig;z++){
						y= j;bl= k;
						while (y && !a[y].ch[z]) y= F[y];
						y= a[y].ch[z];
						if (y==4)
							ooo++;
						if (a[y].v||last[y]) bl= 1;
						update(f[i+1][y][bl],x);
					}
	for (i= 0;i<=tot;i++)
		update(ans,f[m][i][1]);
	printf("%d\n",ans);
	return 0;
}
