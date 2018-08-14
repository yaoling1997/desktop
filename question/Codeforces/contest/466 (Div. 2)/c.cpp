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
bool vis[1000];
char s[maxn],t[maxn];
char sta[maxn];
int n,k,la;
void solve(char *t,int k){
	for (int i=k;i>0;i--)
		if (s[i]!=sta[la]){
			for (int j=la;j>1;j--)
				if (sta[j-1]==s[i]){
					t[i]=sta[j];
					break;
				}
			for(int j=i-1;j>0;j--)
				t[j]=s[j];
			break;
		}else
			t[i]=sta[1];
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		if (!vis[s[i]]){
			vis[s[i]]=1;
			sta[++la]=s[i];
		}
	sort(sta+1,sta+la+1);
	if (k<=n){
		solve(t,k);
	}else {
		for (int i=1;i<=n;i++)
			t[i]=s[i];
		for (int i=n+1;i<=k;i++)
			t[i]=sta[1];
	}
	printf("%s",t+1);
	return 0;
}
