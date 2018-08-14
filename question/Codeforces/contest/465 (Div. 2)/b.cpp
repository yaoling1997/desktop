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
int n;
int u,r,st,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d\n%s",&n,s);
	for (int i=0;i<n;i++){
		if (s[i]=='U'){
			u++;
		}else r++;
		if (u!=r){
			if (u>r){
				if (st!=0&&st!=1)
					ans++;
				st=1;
			}else {
				if (st!=0&&st!=-1)
					ans++;
				st=-1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
