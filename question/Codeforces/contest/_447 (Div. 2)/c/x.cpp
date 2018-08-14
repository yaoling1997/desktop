#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
int a[maxn],m;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		scanf("%d",&a[2*i]);
		if (a[2*i]%a[0]!=0){
			printf("-1");
			return 0;
		}
		a[2*i+1]=a[0];
	}
	printf("%d\n",2*m);
	for (int i=0;i<2*m;i++)
		printf("%d%c",a[i],i<2*m-1?' ':'\n');
	return 0;
}
