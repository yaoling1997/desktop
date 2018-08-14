#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
int n,ans,i,j,Max,Min;
int count(int n){
	int x= n/7,r= n%7,y= 0;
	if (r==6) y= 1;
	return x*2+y;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	if (n==1){
		Min= 0;
		Max= 1;
	}else if (n==2){
		Min= 0;
		Max= 2;
	}else {
		Max+= 2;
		Max+= count(n-2);
		Min= count(n);
	}
	printf("%d %d",Min, Max);
	return 0;
}