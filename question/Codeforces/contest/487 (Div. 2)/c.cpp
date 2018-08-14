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
char s[maxn][maxn];
int a,b,c,d,n,m;
void solve(){
	n=m=50;
	int now=0;
	for (int i='A';i<='C';i++)
		for (int j=1;j<=12;j++){
			now++;
			for (int k=1;k<=m;k++)
				s[now][k]=i;
		}
	for (int i=1;i<=14;i++){
		now++;
		for (int j=1;j<=m;j++)
			s[now][j]='D';
	}
	a--;
	b--;
	c--;
	d--;
	int ch[4]={0};
	ch[0]=a;
	ch[1]=b;
	ch[2]=c;
	ch[3]=d;
	for (int i=0;i<=3;i++){
		int r=i*12+2;
		int p=0;
		int o=(i+1)%4;
		while (ch[o]){
			int c=2+p;
			while (c<m&&ch[o]){
				s[r][c]='A'+o;
				ch[o]--;
				c+=2;
			}
			r+=2;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d%d",&a, &b, &c, &d);
	solve();
	printf("%d %d\n",n, m);
	for (int i=1;i<=n;i++){
		printf("%s",s[i]+1);
		printf("\n");
	}
	return 0;
}
