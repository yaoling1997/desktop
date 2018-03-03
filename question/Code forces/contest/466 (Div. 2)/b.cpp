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
ll n,k,A,B,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%I64d%I64d%I64d%I64d",&n, &k, &A, &B);
	if (k==1){
		printf("%I64d",(n-1)*A);
		return 0;
	}
	while (n!=1){
		if (n%k==0){
			ans+=min(B,(n-n/k)*A);
			n/=k;
		}else if (n>k){
			ans+=n%k*A;
			n-=n%k;
		}else {
			ans+=(n-1)*A;
			n=1;
		}
	}
	printf("%I64d",ans);
	return 0;
}
