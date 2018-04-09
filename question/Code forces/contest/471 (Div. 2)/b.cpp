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
int a[100],b[100];
char s[maxn];
int n,lb,ans;
int cti(char c){
	return c-'a';
}
int check(){
	if (n<4)
		return 0;
	if (lb>4)
		return 0;
	else if (lb==4)
		return 1;
	else if (lb==3){
		return 1;
	}else if (lb==2){
		if (b[1]==1)
			return 0;
		return 1;
	}else {
		return 0;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		a[cti(s[i])]++;
	for (int i=cti('a');i<=cti('z');i++)
		if (a[i])
			b[++lb]=a[i];
	sort(b+1,b+lb+1);
	ans= check();
	printf("%s",ans?"Yes":"No");
	return 0;
}
