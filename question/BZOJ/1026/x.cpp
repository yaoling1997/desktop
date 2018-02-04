#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxm= 30,mlen= 10;
int f[maxm][maxm],b[maxm];
int ansb,ansa,len1,len2,l,r,i,j,k;
int pp(int o){
	int l= 0;
	while (o)
		b[++l]= o%10,o/= 10;
	return l;
}
int pre(int x, int len){
	int i,j,re= 0;
	if (len==1) return x-1;
	for (i= 1;i<len;i++)
		for (j= 1;j<=9;j++)
			re+= f[i][j];
	for (j= 1;j<b[len];j++)
		re+= f[len][j];
	for (i= len-1;i;i--){
		for (j= 0;j<b[i];j++)
			if (abs(b[i+1]-j)>1) re+= f[i][j];
		if (abs(b[i]-b[i+1])<2) break;
	}return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	for (i= 0;i<=9;i++) f[1][i]= 1;
	for (i=2;i<=mlen;i++)
		for (j= 0;j<=9;j++)
			for (k= 0;k<=9;k++)
				if (abs(j-k)>1)
					f[i][j]+= f[i-1][k];
	while (scanf("%d %d",&l, &r)!=EOF){
		r++;
		len1= pp(l);ansa= pre(l,len1);
		len2= pp(r);ansb= pre(r,len2);
		printf("%d\n",ansb-ansa);
	}
	return 0;
}
