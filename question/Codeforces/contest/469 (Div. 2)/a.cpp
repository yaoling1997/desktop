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
int l,r,a;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&l, &r, &a);
	if (l>r)
		swap(l,r);
	if (l+a<=r){
		l+= a;
		a=0;
	}else {
		a-=r-l;
		l=r;
	}
	if (l==r){
		l+=a/2;
		r+=a/2;
	}
	printf("%d",l*2);
}
