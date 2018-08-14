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
int p,y,ans;
int solve(int o){
	for (int i=2;i<=p&&i*i<=o;i++)
		if (o%i==0)
			return false;
	return true;		
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&p,&y);
	ans=-1;
	for (int i=y;i>p;i--)
		if (solve(i)){
			ans=i;
			break;
		}
	printf("%d",ans);
	return 0;
}
