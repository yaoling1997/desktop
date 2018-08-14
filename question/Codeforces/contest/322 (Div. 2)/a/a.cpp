#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int a,b;
	scanf("%d%d",&a, &b);
	if (a>b) swap(a,b);
	b-= a;
	printf("%d %d",a,b/2);
	return 0;
}
