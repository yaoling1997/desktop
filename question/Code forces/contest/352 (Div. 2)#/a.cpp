#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e5;
int a[maxn],sta[maxn];
int n,i,x,y,la,m;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (i= 1;i<=1000;i++){
		x= i;
		la= 0;
		while (x){
			sta[++la]= x%10;
			x/= 10;
		}
		while (la) a[++m]= sta[la--];
	}
	printf("%d",a[n]);
	return 0;
}
