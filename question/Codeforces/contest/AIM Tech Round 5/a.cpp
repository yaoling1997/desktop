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
const int maxn= 1000;
char s[maxn];
int n,m,first,x,y,xx,yy;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			if(s[j]=='B'){
				xx=i;
				yy=j;
				if (!first){
					first=1;
					x=i;
					y=j;
				}
			}
	}
	printf("%d %d",(x+xx)/2,(y+yy)/2);
}
