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
int hh,mm;
int H,D,C,N;
double ans,ans8;
void getAns8(){
	int add=0;
	if (hh<20){
		add=(20-hh-1)*60+60-mm;
		H+=add*D;
	}
	//printf("%d\n",H);
	ans8=(H/N+(H%N!=0))*C*4./5;
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&hh, &mm);
	scanf("%d%d%d%d",&H, &D, &C, &N);
	ans= (H/N+(H%N!=0))*C;
	getAns8();
	ans=min(ans,ans8);
	printf("%.6f",ans);
	return 0;
}
