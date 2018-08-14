#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 100;
vector<int> r[maxn],c[maxn];
vector<int> R,C;
char s[maxn][maxn],a[maxn][maxn];
int vis[maxn];
int b[maxn];
int n,m,ans;
void solveR(int);
void solveC(int o){
	b[o]=1;
	C.pb(o);
	for (int i=0;i<(int)c[o].size();i++){
		int v=c[o][i];
		if (vis[v])
			continue;
		solveR(v);
	}
}
void solveR(int o){
	vis[o]=1;
	R.pb(o);
	for (int i=0;i<(int)r[o].size();i++){
		int v=r[o][i];
		if (b[v])
			continue;
		solveC(v);
	}
}
void solve(int o){
	R.clear();
	C.clear();	
	solveR(o);
	for (int i=0;i<(int)R.size();i++)
		for (int j=0;j<(int)C.size();j++)
			a[R[i]][C[j]]='#';
}
void print(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
}
int check(){
	//	print();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]!=a[i][j])
				return 0;
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++){
			a[i][j]='.';
			if (s[i][j]=='#'){
				r[i].pb(j);
				c[j].pb(i);
			}
		}
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			solve(i);
		}
	ans= check();
	printf("%s",ans?"Yes":"No");
	return 0;
}
