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
int n,bl;
char s[maxn];
bool isColor(char c){
	return c=='C'||c=='Y'||c=='M';
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	bl=1;
	for (int i=2;i<=n;i++){
		if (isColor(s[i])&&isColor(s[i-1])&&s[i-1]==s[i]){
			bl=0;
			break;
		}
		if (isColor(s[i-1])&&!isColor(s[i])&&isColor(s[i+1])&&s[i-1]!=s[i+1])
			s[i]='.';
	}
	if (!bl){
		printf("No");
		return 0;
	}
	bl=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='?'){
			bl=1;
			break;
		}
	printf("%s",bl?"Yes":"No");
	return 0;
}
