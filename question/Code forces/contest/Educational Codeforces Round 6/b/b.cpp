#include<bits/stdc++.h>
using namespace std;
int a[20];
int x,y,i,ans;
int count(int x){
	int re= 0;
	while (x){
		re+= a[x%10];
		x/= 10;
	}return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	a[0]= 6;
	a[1]= 2;
	a[2]= 5;
	a[3]= 5;
	a[4]= 4;
	a[5]= 5;
	a[6]= 6;
	a[7]= 3;
	a[8]= 7;
	a[9]= 6;
	scanf("%d%d",&x, &y);
	for (i= x;i<=y;i++)
		ans+= count(i);
	printf("%d",ans);
	return 0;
}
