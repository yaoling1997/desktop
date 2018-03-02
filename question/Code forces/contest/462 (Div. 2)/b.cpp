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
int a[5];
ll ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	a[0]=1;
	a[1]=4;
	a[2]=8;
	int k;
	scanf("%d",&k);
	for (int i=1;i<=18;i++)
		if (k){
			if (k>=2){
				ans=ans*10+a[2];
				k-=2;
			}else {
				ans=ans*10+a[1];
				k--;
			}
		}else{
			break;
		}
	if (k)
		ans=-1;
	printf("%I64d",ans);
	return 0;
}
