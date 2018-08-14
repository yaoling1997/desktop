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
int x,y;
bool solve(int x,int y){
	int a,b;
	if (y==0)
		return false;
	a= y-1;
	if (x<a)
		return false;
	b= x-a;
	if (b&1)
		return false;
	b/=2;
	if (a==0&&b)
		return false;
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&x, &y);
	if (solve(x,y))
		printf("Yes");
	else printf("No");
}
