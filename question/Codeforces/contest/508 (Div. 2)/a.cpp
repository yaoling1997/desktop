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
int ch[100];
char s[maxn];
int n,k;
int idx(char c){
	return c-'A';
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%s",&n, &k, s+1);
	for (int i=1;i<=n;i++)
		ch[idx(s[i])]++;
	int Min=1e9;
	for (int i=0;i<k;i++)
		Min=min(Min,ch[i]);
	printf("%d",Min*k);
	return 0;
}
