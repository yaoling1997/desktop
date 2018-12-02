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
char s[maxn];
int a[maxn],f[maxn],last[maxn];
int n,i,cnt;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='G'){
			if (s[i-1]!='G'){
				cnt++;
				f[i]=i;
				a[i]++;
				last[i]=i;
			}else{
				f[i]=f[i-1];
				a[f[i]]++;
				last[f[i]]=i;
			}
		}
	if (cnt==0){
	}else if (cnt==1){
		for (int i=1;i<=n;i++)
			if (s[i]=='G')
				ans++;
	}else if (cnt==2){
		for (int i=1;i<=n;i++)
			if (s[i]=='G'&&s[i-1]!='G'){
				ans=max(ans,a[i]+1);
				if (s[last[i]+2]=='G')
					ans=max(ans,a[i]+a[last[i]+2]);
			}
	}else {//cnt>=3
		for (int i=1;i<=n;i++)
			if (s[i]=='G'&&s[i-1]!='G'){
				ans= max(ans,a[i]+1);
				if (s[last[i]+2]=='G')
					ans=max(ans,a[i]+1+a[last[i]+2]);
			}
	}
	printf("%d",ans);
	return 0;
}
