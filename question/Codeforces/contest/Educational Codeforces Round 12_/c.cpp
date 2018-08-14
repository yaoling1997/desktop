#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e5;
char s[maxn];
int len,i,j;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	len= strlen(s+1);
	s[len+1]= '*';
	for (i= 2;i<=len;i++)
		if (s[i]==s[i-1])
			for (j= 'a';j<='z';j++)
				if (j!=s[i-1]&&j!=s[i+1]){
					s[i]= j;
					break;
				}
	for (i= 1;i<=len;i++)
		printf("%c",s[i]);
	return 0;
}