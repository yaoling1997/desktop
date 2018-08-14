#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define rep(i,a,n) for (int i= a;i<=n;i++)
#define ll long long
using namespace std;
const int maxn= 1e3;
char a[maxn][maxn],b[maxn][maxn];
int d[maxn];
int k,m;
char inv(char c){
	if (c=='+') return '*';
	else return '+';
}
void get(int o){
	if (o==0){
		a[1][1]= '+';
		return;
	}
	get(o-1);
	int i,j,m;
	m= d[o-1];
	for (i= 1;i<=m;i++){
		for (j= 1;j<=m;j++)
			b[i][j]= b[i+m][j]= a[i][j];
		for (j= m+1;j<=2*m;j++){
			b[i][j]= a[i][j-m];
			b[i+m][j]= inv(a[i][j-m]);
		}
	}
	m*= 2;
	for (i= 1;i<=m;i++)
		for (j= 1;j<=m;j++)
			a[i][j]= b[i][j];
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&k);
	d[0]= 1;
	rep(i,1,10)
		d[i]= d[i-1]*2;
	if (k==0){
		printf("+");
	}else {
		get(k);
		m= d[k];
		rep(i,1,m)
			printf("%s\n",a[i]+1);
	}
	return 0;
}
