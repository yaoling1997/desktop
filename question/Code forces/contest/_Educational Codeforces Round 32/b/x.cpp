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
int L,D,U,R;
int n,i;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%s",&n, s);
	for (i= 0;i<n;i++)
		if (s[i]=='L')
			L++;
		else if (s[i]=='R')
			R++;
		else if (s[i]=='U')
			U++;
		else D++;
	printf("%d",min(L,R)*2+min(U,D)*2);
	return 0;
}
