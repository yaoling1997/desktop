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
int n,h,a,b,k;
int count(int x,int y,int xx,int yy){
	if (x==xx)
		return abs(y-yy);
	int re=0;
	if (y<a||y>b){
		re+=min(abs(y-a),abs(y-b));
		if (y<a)
			y=a;
		else
			y=b;
	}		
	if (yy<a||yy>b){
		re+=min(abs(yy-a),abs(yy-b));
		if (yy<a)
			yy=a;
		else
			yy=b;
	}
	re+=abs(x-xx)+abs(y-yy);
	return re;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d%d%d",&n, &h, &a, &b, &k);
	for (int kk=1;kk<=k;kk++){
		int x,y,xx,yy,ans;
		scanf("%d%d%d%d",&x, &y, &xx, &yy);
		ans=count(x,y,xx,yy);
		printf("%d\n",ans);
	}
	return 0;
}
