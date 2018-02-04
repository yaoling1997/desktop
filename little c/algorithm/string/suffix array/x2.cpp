#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int maxn= 300000,sig= 150;
int c[maxn],x[maxn],sa[maxn],y[maxn],height[maxn];
char s[maxn];
int len,i,ans;
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
		p= 1;x[sa[1]]= 1;
		for (i= 2;i<=len;i++)
			if (y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])
				x[sa[i]]= p;
			else x[sa[i]]= ++p;
		if (p==len) break;
		m= p;
	}
}
void geth(){
	int i,j,k= 0;
	for (i= 1;i<=len;i++){
		if (k) k--;
		j= sa[x[i]-1];
		while (s[i+k]==s[j+k]) k++;
		height[x[i]]= k;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	len= strlen(s+1);
	s[++len]= 64;
	scanf("%s",s+len+1);
	len= strlen(s+1);
	for (i= 1;i<=len;i++)
		x[i]= s[i];
	build(sig);
	geth();
	ans= 0;
	for (i= 1;i<=len;i++){
		if (ans<height[i])
			ans= height[i];
	}
	printf("%d",ans);
}
