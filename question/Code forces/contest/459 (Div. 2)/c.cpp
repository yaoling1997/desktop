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
int n,ans;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	n= strlen(s+1);
	for (int i=1;i<=n;i++){
		int Min=0,Max=0;
		for (int j=i;j<=n;j++){
			if (s[j]=='(')
				Min++,Max++;
			else if (s[j]==')'){
				Min--;
				Max--;
				if (Min<0)
					Min+=2;
				if (Max<0)
					break;
			}else {
				Min--;
				Max++;
				if (Min<0)
					Min+= 2;
			}			
			if (Min==0)
				ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
