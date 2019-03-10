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
int w,h,u1,d1,u2,d2;
void hit(int u,int d){
	w=w+(h+d)*(h-d+1)/2;
	h=d-1;
	w=max(0,w-u);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&w,&h);
	scanf("%d%d",&u1,&d1);
	scanf("%d%d",&u2,&d2);
	if (d1<d2){
		swap(d1,d2);
		swap(u1,u2);
	}
	hit(u1,d1);
	hit(u2,d2);
	hit(0,0);
	printf("%d",w);
}
