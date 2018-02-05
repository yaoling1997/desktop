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
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s);
	int len= strlen(s);
	int x= 0,y= 0;
	for (int i= 0;i<len;i++){
		if (y>0)
			x+= s[i]=='0';
		y+= s[i]=='1';
	}
	
	if (y >0&&x>=6)
		printf("yes");
	else printf("no");
	return 0;
}
