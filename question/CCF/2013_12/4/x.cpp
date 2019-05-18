#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
const int mo= 1e9+7;
int f[2000][20];
int n,ans;
void update(int &x,int y){
	x+= y;
	if (x>=mo)
		x-= mo;
}
int prepare(int n){
	int d[10]= {0};
	d[0]= 1;
	d[1]= 2;
	d[2]= 4;
	d[3]= 8;
	f[0][1]= f[0][2]= f[0][4]= f[0][8]= 1;
	int i,j,k,re;
	for (i= 1;i<=n;i++)
		for (j= 0;j<4;j++)
			for (k= 0;k<16;k++){
				if (j==1&&(k&d[0]))
					continue;
				if (j==3&&(k&d[2]))
					continue;
				update(f[i][k|d[j]],f[i-1][k]);
			}
				
	re= (f[n-1][11]+f[n-1][15])%mo;
	return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	ans= prepare(n-1);
	printf("%d",ans);
	return 0;
}
