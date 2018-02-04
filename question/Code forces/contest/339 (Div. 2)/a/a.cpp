#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ld nex;
ll l,r,k,x,bl;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d%I64d%I64d",&l, &r, &k);
	x= nex= 1;
	while (nex<=r){
		x= nex;
		if (x>=l){
			if (bl) printf(" ");
			bl= 1;
			printf("%I64d",x);
		}
		nex*= k;
	}
	if (!bl) printf("-1");
	return 0;
}
