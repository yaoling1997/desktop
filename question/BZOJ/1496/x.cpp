#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 2000001;
vector<int> st[2];
int l[maxn],a[maxn],f[2][30][2];
int n,i,x,y,ans;
void Min(int &a,int b){
	a= min(a,b);
}
void get(){
	st[0].clear();st[1].clear();
	int o= 0,p= 1,i,j,k,len,len1,res= maxn;
	for (i= 1;i<=1+2;i++)
		for (j= a[i];j<=a[i]+2;j++)
			if (j>=a[1]) st[0].push_back(j);
	len= st[0].size();
	for (i= 0;i<len;i++)
		f[0][i][0]= st[0][i]-a[1],f[0][i][1]= maxn;
	for (i= 2;i<=n;i++){
		o^= 1;p^= 1;st[o].clear();
		for (j= max(1,i-2);j<=i+2&&j<=n;j++)
			for (k= a[j];k<=a[j]+2;k++)
				if (k>=a[i]) st[o].push_back(k);
		len= st[o].size();len1= st[p].size();
		for (j= 0;j<len;j++){
			f[o][j][0]= f[o][j][1]= maxn;
			for (k= 0;k<len1;k++){
				if (st[p][k]>st[o][j]) Min(f[o][j][0],f[p][k][1]);
				else if (st[p][k]<st[o][j]) Min(f[o][j][1],f[p][k][0]);
				else Min(f[o][j][0],f[p][k][0]),Min(f[o][j][1],f[p][k][1]);
			}
			f[o][j][0]+= st[o][j]-a[i];f[o][j][1]+= st[o][j]-a[i];
		}
	}
	len= st[o].size();
	for (i= 0;i<len;i++)
		res= min(res,f[o][i][0]);
	ans+= res;
}
int main()	
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++) scanf("%d %d",&l[i], &a[i]);
	get();
	for (i= 1;i<=n;i++) a[i]= maxn-l[i];
	get();
	printf("%d\n",ans);
	return 0;
}
