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
int a,b,ans;
int sum(int x){
	return (1+x)*x/2;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&a, &b);
	a=abs(a-b);
	ans= sum(a/2)+sum(a-a/2);
	printf("%d",ans);
}
