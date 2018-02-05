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
int a[maxn];
int sta[maxn];
int n,la;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	for (int i= 1;i<=n;i++)
		a[i]= 2;
	for (int i= 2;i<=n;i+= 2){
		a[i]= 0;
		sta[++la]= i;
	}
	for (int i= 1;i<=n;i+= 2){
		a[i]= 0;
		sta[++la]= i;
	}
	for (int i= 2;i<=n;i+= 2){
		a[i]= 0;
		sta[++la]= i;
	}
	printf("%d\n",la);
	for (int i= 1;i<=la;i++)
		printf("%d%c",sta[i],i<la?' ':'\n');
	return 0;
}
