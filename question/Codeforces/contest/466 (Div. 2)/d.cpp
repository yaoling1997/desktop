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
int a[maxn],b[maxn];
int n,l,r;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("\n%s",s+1);
	for (int i=1;i<=n;i++)
		b[i]=s[i]-'0';
	l=-1e9;
	r=1e9;
	for (int i=5;i<=n;i++)
		if (b[i]==0){
			if (b[i-1]==1&&b[i-2]==1&&b[i-3]==1&&b[i-4]==1){
				r=min(r,a[i]-1);
				r=min(r,a[i-1]-1);
				r=min(r,a[i-2]-1);
				r=min(r,a[i-3]-1);
				r=min(r,a[i-4]-1);
			}
		}else {//1
			if (b[i-1]==0&&b[i-2]==0&&b[i-3]==0&&b[i-4]==0){
				l=max(l,a[i]+1);
				l=max(l,a[i-1]+1);
				l=max(l,a[i-2]+1);
				l=max(l,a[i-3]+1);
				l=max(l,a[i-4]+1);
			}			
		}
	printf("%d %d\n",l,r);
}
