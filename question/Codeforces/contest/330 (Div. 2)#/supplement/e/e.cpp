#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll M= 2e18;
const int maxn= 2e5;
struct point{
	int x,y,h;
}P[maxn],Q[maxn];
int b[maxn];
ll ans,X,Y;
int n,K,x,y,xx,yy,i,j,p,q,cnt;
bool cmp(point a,point b){
	return a.x<b.x;
}
bool cmp1(point a,point b){
	return a.y<b.y;
}
int main()
{
	scanf("%d%d",&n, &K);
	ans= M;
	for (i= 1;i<=n;i++){
		scanf("%d%d%d%d",&x, &y, &xx, &yy);
		P[i]= (point){x+xx,y+yy,i};
		Q[i]= P[i];
	}
	sort(P+1,P+n+1,cmp);
	sort(Q+1,Q+n+1,cmp1);
	for (i= 1;i<=K+1;i++){
		p= i-1;
		if (p)
			b[P[p].h]= 1;
		for (j= n;n-j+p<=K;j--){
			q= n-j;
			if (j<n)
				b[P[j+1].h]= 1;
			X= P[j].x-P[i].x;
			if (X&1) X++;
			if (!X) X= 2;
			x= 1;y= n;
			while (b[Q[x].h]) x++;
			cnt= 0;
			while (b[Q[y].h] || p+q+cnt<K){
				if (!b[Q[y].h]) cnt++;
				y--;				
			}
			while (y<=n){
				Y= Q[y].y-Q[x].y;
				if (Y&1) Y++;
				if (!Y) Y= 2;
				if (ans>X*Y/4)
					ans= X*Y/4;
				x++;
				while (b[Q[x].h]) x++;
				y++;
				while (b[Q[y].h]) y++;
			}
		}
		for (j= n;n-j+p<=K;j--)
			b[P[j+1].h]= 0;
	}
	printf("%lld",ans);
	return 0;
}
