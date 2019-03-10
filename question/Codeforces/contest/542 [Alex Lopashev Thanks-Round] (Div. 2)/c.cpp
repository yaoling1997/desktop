#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 60;
typedef pair<int,int> PA;
PA Move[4];
PA bp,ep;
char s[maxn][maxn];
bool visb[maxn][maxn];
bool vise[maxn][maxn];
int n,ans;
void prepare(PA b,bool vis[maxn][maxn]){
	memset(vis,0,sizeof(visb));
	queue<PA> q;
	vis[b.first][b.second]=1;
	q.push(b);
	while (!q.empty()){
		PA u=q.front();
		q.pop();
		for (int i=0;i<4;i++){
			PA v=mp(u.first+Move[i].first,u.second+Move[i].second);
			if (vis[v.first][v.second]||s[v.first][v.second]!='0')
				continue;
			vis[v.first][v.second]=1;
			q.push(v);
		}
	}
}
bool check(PA a,PA b){
	return (visb[a.first][a.second]&&vise[b.first][b.second])||(vise[a.first][a.second]&&visb[b.first][b.second]);
}
int sqr(int x){
	return x*x;
}
int getAns(){
	prepare(bp,visb);
	prepare(ep,vise);
	if (check(mp(0,0),mp(0,0))){
		return 0;
	}
	int re=1e8;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				for (int l=1;l<=n;l++)
					if (s[i][j]=='0'&&s[k][l]=='0'){
						if (check(mp(i,j),mp(k,l))){
							re=min(re,sqr(k-i)+sqr(l-j));
						}
					}
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	Move[0]=mp(-1,0);
	Move[1]=mp(1,0);
	Move[2]=mp(0,-1);
	Move[3]=mp(0,1);
	scanf("%d",&n);
	int x,y;
	scanf("%d%d",&x, &y);
	bp=mp(x,y);
	scanf("%d%d",&x, &y);
	ep=mp(x,y);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);	
	ans=getAns();
	printf("%d",ans);
	return 0;
}
