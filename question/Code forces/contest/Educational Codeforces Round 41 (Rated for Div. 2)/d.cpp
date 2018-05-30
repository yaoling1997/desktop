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
	int x,y;
}a[maxn],b[maxn],c[maxn];
int n;
int ans,lb;
void getUnique(int p,int q,node *a,node *b,int n,int &lb){
	lb=0;
	for (int i=1;i<=n;i++){
		if (i==p||i==q)
			continue;
		if ((ll)(a[q].y-a[p].y)*(a[i].x-a[p].x)==
				(ll)(a[i].y-a[p].y)*(a[q].x-a[p].x))
			continue;
		b[++lb]=a[i];
	}
}
int check(int p,int q){
	int lb=0,lc=0;
	getUnique(p,q,a,b,n,lb);
	if (lb<=2)
		return 1;
	getUnique(1,2,b,c,lb,lc);
	return lc==0;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x, &a[i].y);
	}
	if (n<=2){
		ans=1;
	}else {
		ans=max(check(1,2),ans);
		ans=max(check(1,3),ans);
		ans=max(check(2,3),ans);
	}
	printf("%s",ans?"YES":"NO");
	return 0;
}
