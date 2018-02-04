#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn= 3001;
int f[maxn];
int n,a,b,c,x,i,l;
int ans(int o){
	if (f[o]!=-1) return f[o];
	f[o]= 0;
	if (o-a>=0) f[o]= 1-ans(o-a);
	if (o-b>=0) f[o]= max(f[o],1-ans(o-b));
	if (o-c>=0) f[o]= max(f[o],1-ans(o-c));
	return f[o];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	memset(f,-1,sizeof(f));
	int x= min(a,b);
	x= min(x,c);
	for (i= 0;i<x;i++)
		f[i]= 0;
	scanf("%d %d %d %d",&l, &a, &b, &c);
	printf("%d",ans(l));
	return 0;
}
