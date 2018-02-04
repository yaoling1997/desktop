#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e5;
int a,b,c,i;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d%d",&a, &b, &c);
	if (c==0){
		if (a==b) printf("YES");
		else printf("NO");
	}else {
		if ((b-a)%c==0){
			i= (b-a)/c+1;
			if (i>=1) printf("YES");
			else printf("NO");
		}else printf("NO");
	}return 0;
}