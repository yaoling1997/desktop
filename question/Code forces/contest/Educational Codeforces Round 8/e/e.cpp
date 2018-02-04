#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 4e3;
struct node{
	int v,h;
	bool operator <(const node &a)const{
		return v>a.v;
	}
};
priority_queue<node> Q;
char s[maxn][maxn];
int c[maxn],left[maxn][maxn],right[maxn][maxn];
ll ans;
int n,m,i,j,x,y,M;
int lowbit(int o){
	return o&-o;
}
void add(int o,int x){
	while (o<=M){
		c[o]+= x;
		o+= lowbit(o);
	}
}
int cal(int o){
	int re= 0;
	while (o>0){
		re+= c[o];
		o-= lowbit(o);
	}return re;
}

void get(int x,int y){
	while (!Q.empty())
		Q.pop();
	memset(c,0,sizeof(c));
	int pos= 0;
	while (x<=n&&y>0){
		pos++;
		if (s[x][y]=='.'){
			while (!Q.empty()){
				add(Q.top().h,-1);
				Q.pop();
			}
		}else {
			Q.push((node){pos+left[x][y],pos});
			add(pos,1);
			while (Q.top().v<=pos){
				add(Q.top().h,-1);
				Q.pop();
			}
			ans+= cal(pos)-cal(max(pos-right[x][y],0));
		}
		x++;y--;
	}
}
int main()
{
	//freopen("2.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	M= max(n,m);
	for (i= 1;i<=n;i++){
		scanf("%s",s[i]+1);
		for (j= 1;j<=m;j++){
			if (s[i][j]=='z')
				left[i][j]= left[i][j-1]+1;
			if (s[i][m-j+1]=='z')
				right[i][m-j+1]= right[i][m-j+2]+1;
		}
	}
	for (i= 1;i<=m;i++)
		get(1,i);
	for (i= 2;i<=n;i++)
		get(i,m);
	printf("%lld",ans);
	return 0;
}
