#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 300001;
int use[maxn],f[maxn],mex[maxn*10];
int T,F,n,i,j,time,Max,ans,x;
int get(int x,int y){
	if (x&1) return y;
	else return 0;
}
void SG(int n){
	if (n<F) return;
	int i,j;time++;
	for (i= 2;i<=n;i= n/(n/i)+1)
		for (j= i;j<=i+1&&j<=n;j++)
			mex[get(n%j,f[n/j+1])^get(j-n%j,f[n/j])]= time;
	for (f[n]= 0;mex[f[n]]==time;f[n]++);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&T, &F);
	F= max(F,2);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d",&n);
		ans= 0;
		for (i= 1;i<=n;i++){
			scanf("%d",&x);
			if (x>Max){
				for (j= Max+1;j<=x;j++)
					SG(j);
				Max= x;
			}
			ans^= f[x];
		}
		printf("%d%c",ans? 1:0,a1!=T? ' ':'\n');
	}return 0;
}