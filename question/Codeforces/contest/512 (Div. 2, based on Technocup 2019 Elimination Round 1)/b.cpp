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
const int maxn= 5e5;
struct node{
	int x,y,c;
}a[4];
int n,d,m;
int check(int x,int y){
	for (int i=0;i<4;i++){
		int c=abs(x-a[i].x)+abs(y-a[i].y);
		if (c<a[i].c)
			return 0;
	}
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &d);
	scanf("%d",&m);
	a[0]=(node){0,0,d};
	a[1]=(node){0,n,n-d};
	a[2]=(node){n,0,n-d};
	a[3]=(node){n,n,d};
	for (int tt=1;tt<=m;tt++){
		int x,y;
		scanf("%d%d",&x, &y);
		int ans=check(x,y);
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}
