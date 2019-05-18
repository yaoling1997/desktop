#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int maxn= 300;
int a[maxn][maxn];
int n,i,ans;
void deal(int x1,int y1,int x2,int y2){
	int i,j;
	for (i= x1;i<x2;i++)
		for (j= y1;j<y2;j++)
			a[i][j]= 1;
}
int getAns(){
	int i,j,re= 0; 
	for (i= 0;i<=200;i++)
		for (j= 0;j<=200;j++)
			re+= a[i][j];
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
		deal(x1,y1,x2,y2);
	}
	ans= getAns();
	printf("%d",ans);
	return 0;
}

