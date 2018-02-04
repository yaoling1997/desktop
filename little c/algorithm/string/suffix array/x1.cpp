#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn= 700000,sig= 30;
char s[maxn];
int f[maxn][21];
int c[maxn],x[maxn],y[maxn],sa[maxn],h[maxn],rank[maxn],height[maxn];
int i,len,m;
void build(int m){
	int i;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=len;i++) c[x[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= len;i>0;i--) sa[c[x[i]]--]= i;
	for (int k= 1;k<=len;k<<= 1){
		int p= 0;
		for (i= len-k+1;i<=len;i++) y[++p]= i;
		for (i= 1;i<=len;i++) if (sa[i]>k) y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;
		for (i= 1;i<=len;i++) c[x[y[i]]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= len;i>0;i--) sa[c[x[y[i]]]--]= y[i];
		swap(x,y);
		p= x[sa[1]]= 1;
		for (i= 2;i<=len;i++)
			if (y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])
				x[sa[i]]= p;
			else x[sa[i]]= ++p;
		if (p==len) break;
		m= p;
	}
}
void geth(){//height[i]表示sa[i]和sa[i+1]的LCP
	int i,j,k= 0;
	for (i= 1;i<=len;i++) rank[sa[i]]= i;
	for (i= 1;i<=len;i++){
		if (k) k--;
		j= sa[rank[i]+1];
		while (s[i+k]==s[j+k]) k++;
		if (rank[i]!=len)
			height[rank[i]]= k;
	}
}
void getf(){
	int i,j,k;
	for (i= 1;i<=len;i++)
		f[i][0]= len-sa[i]+1;
	for (i= 1;i<=len;i++)
		f[i][1]= height[i];
	k= 2;
	for (i= 2;i<=18;i++){
		for (j= 1;j<=len;j++){
			f[j][i]= min(f[j][i-1],f[j+k][i-1]);
			f[j][i]= min(f[j][i],f[j+k/2][i-1]);
		}	
		k*= 2;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%s",s+1);
	len= strlen(s+1);
	for (i= 1;i<=len;i++)
		x[i]= s[i]-'a'+1;
	build(sig);
	memcpy(rank,x,len);
	geth();
	getf();
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x, &y);
		x= rank[x];y= rank[y];
		if (y<x) swap(x,y);
		int k= (int)(log(y-x+1)/log(2)+0.0000001);
		int z= min(f[x][k],f[y-(1<<k)+1][k]);
		printf("%d\n",z);
	}
	return 0;
}
