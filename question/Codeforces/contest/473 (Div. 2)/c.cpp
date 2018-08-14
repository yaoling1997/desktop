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
int n;
void printFalse(){
	if (n<6){
		printf("-1\n");
		return;
	}
	for (int i=2;i<=4;i++)
		printf("%d %d\n",1,i);
	for (int i=5;i<=n;i++)
		printf("%d %d\n",i,2);
}
void printTrue(){
	for (int i=2;i<=n;i++)
		printf("%d %d\n",i-1,i);
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	printFalse();
	printTrue();
	return 0;
}
