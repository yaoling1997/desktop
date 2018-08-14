#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
char s[maxn],t[maxn];
int ls,lt,i,j,bl;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s%s",s+1,t+1);
	ls= strlen(s+1);
	lt= strlen(t+1);
	bl= 1;
	if (ls!=lt) bl= 0;
	else for (i= 1;i<=ls;i++)
			 if (s[i]!=t[i]){
				 bl= 0;
				 break;
			 }
	if (bl) printf("%s",s+1);
	else printf("1");
	return 0;
}