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
const int maxn= 5e5,oo= 1e9;
char s[maxn];
int n,a[maxn],i,sta[maxn],la,Min,Max;
void update(int x){
	Min= min(Min,x);
	Max= max(Max,x);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i= 1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%s",s+1);
	Min=oo,Max=-oo;
	for (int i=1;i<=n;i++){
		if (s[i]=='0'){
			update(a[i]);
			sta[++la]=Min;
			sta[++la]=Max;
			Min=oo;
			Max=-oo;
		}else {
			update(a[i]);
		}
		if (i==n){
			sta[++la]=Min;
			sta[++la]=Max;
		}
	}
	bool bl=true;
	for (i=1;i<la;i++)
		if (sta[i]>sta[i+1]){
			bl=false;
			break;
		}
	printf("%s",bl?"YES":"NO");
	return 0;
}