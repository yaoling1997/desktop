#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5,oo= 1e9;
double P[maxn],S[maxn];
double ans,x;
int i,T,A,B;
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		scanf("%d%d",&A, &B);
		S[0]= 1;
		for (i= 1;i<=A;i++){
			scanf("%lf",&P[i]);
			S[i]= S[i-1]*P[i];
		}
		ans= 1+B+1;
		for (i= A;i>=0;i--){
			x= S[i]*(B+1-A+2*(A-i));
			x+= (1-S[i])*(B+1-A+2*(A-i)+B+1);
			ans= min(ans,x);
		}
		printf("Case #%d: %.6lf\n",t, ans);
	}
	return 0;
}
