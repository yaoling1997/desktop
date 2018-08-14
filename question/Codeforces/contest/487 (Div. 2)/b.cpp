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
int n,p,bl;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &p);
	scanf("%s",s+1);
	for (int i=1;i<=n-p;i++)
		if (s[i]=='.'){
			if (s[i+p]=='.'){
				s[i]='0';
				s[i+p]='1';
				bl=1;
				break;
			}else {
				s[i]='1'-s[i+p]+'0';
				bl=1;
				break;
			}
		}else {
			if (s[i+p]=='.'){
				s[i+p]='1'-s[i]+'0';
				bl=1;
				break;
			}else if (s[i]!=s[i+p]){
				bl=1;
				break;
			}
		}	
	for (int i=1;i<=n;i++)
		if (s[i]=='.')
			s[i]='0';
	if (bl)
		printf("%s",s+1);
	else
		printf("%s","No");
	return 0;
}
