#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
map<int,int> M;
int a[maxn];
char s[maxn];
int n,i,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%s",&n,s+1);
	M[0]=0;
	for (i= 1;i<=n;i++){
		if (s[i]=='0'){
			a[i]= a[i-1]-1;
		}else {
			a[i]= a[i-1]+1;
		}
		if (M.count(a[i]))
			ans= max(ans,i-M[a[i]]);
		else
			M[a[i]]= i;
	}
	printf("%d",ans);
	return 0;
}
