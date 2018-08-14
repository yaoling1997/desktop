#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e5;
map<int,int> M;
int a[maxn],b[maxn],c[maxn];
int n,i,j,x,y,ans,m;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		M[x]++;
	}
	scanf("%d",&m);
	ans= 1;
	for (i= 1;i<=m;i++)
		scanf("%d",&b[i]);
	for (i= 1;i<=m;i++)
		scanf("%d",&c[i]);	
	for (i= 1;i<=m;i++){
		x= b[i];
		y= c[i];
		if (M[x]>M[b[ans]])
			ans= i;
		else if (M[x]==M[b[ans]]){
			if (M[y]>M[c[ans]])
				ans= i;
		}
	}printf("%d",ans);
	return 0;
}