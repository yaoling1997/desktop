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
int a[maxn],b[maxn];
int n,ans=0;
bool check(int o){
	int sum=0;
	for (int i=1;i<=n;i++){
		b[i]=a[i]*o;
		if (b[i]>0)
			sum+=1;
	}
	int cp=n/2+n%2;
	return sum>=cp;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	if (check(1))
		ans=1;
	else if (check(-1))
		ans=-1;
	printf("%d",ans);
	return 0;
}
