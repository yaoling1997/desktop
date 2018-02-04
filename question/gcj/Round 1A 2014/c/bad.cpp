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
int a[maxn],p[maxn];
int i,n,x;
int random(int o){
	return 1.0*rand()/RAND_MAX*o;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n= 1000;
	for (int T= 1;T<=1e4;T++){		
		for (i= 0;i<1000;i++)
			p[i]= i;
		for (i= 0;i<1000;i++){
			x= random(1000);
			swap(p[i],p[x]);
		}
		x= 0;
		for (i= 0;i<1000;i++)
			if (p[i]<=i) x++;
		a[x]++;
	}
	for (i= 0;i<=1000;i++)
		printf("%d\n",a[i]);
	return 0;
}
