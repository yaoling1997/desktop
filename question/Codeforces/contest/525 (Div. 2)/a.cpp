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
int a,b,x;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&x);
	for (int i=1;i<=x;i++)
		for (int j=1;j<=x;j++)
			if (i%j==0&&i*j>x&&(double)i/j<x){
				a=i;
				b=j;
			}
	if (a==0)
		printf("-1");
	else
		printf("%d %d",a,b);
	return 0;
}
