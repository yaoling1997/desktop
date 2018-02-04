#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int i;
int getint(){
	char c= getchar();int re= 0;
	while (c<'0'||c>'9') c= getchar();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= getchar();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	//ios::sync_with_stdio(false);
	int x;
	for (i= 1;i<=100000000;i++)
		//x= getint();
		scanf("%d",&x);
		//cin>>x;
	return 0;
}
