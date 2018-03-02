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
int a[maxn];
ll sum,ans,ansSum;
int n,s,f;
int mo(int x){
	if (x<=0)
		x+=n;
	return x;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[n+i]=a[i];
	}
	scanf("%d%d",&s, &f);
	int L=f-s;
	int j=1;
	for (int i=1;i<=2*n;i++){
		while (j<=2*n&&j-i+1<=L){
			sum+=a[j];
			j++;
		}
		int realI=i>n?i-n:i;
		if (sum>ansSum||(sum==ansSum&&mo(s-realI+1)<mo(s-ans+1))){
			ans=realI;
			ansSum=sum;
		}
		sum-=a[i];
	}
	ans=mo(s-ans+1);
	printf("%I64d",ans);
	return 0;
}
