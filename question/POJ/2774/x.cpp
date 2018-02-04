#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e5;
char s[maxn],t[maxn];
int X[maxn],Y[maxn],sa[maxn],rank[maxn],height[maxn],c[maxn];
int ls,lt,i,j,m,ans;
void build(int m){
	int i;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=ls;i++) c[X[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= ls;i>0;i--) sa[c[X[i]]--]= i;
	for (int k= 1;k<=ls;k<<= 1){
		int p= 0;
		for (i= ls-k+1;i<=ls;i++)
			Y[++p]= i;
		for (i= 1;i<=ls;i++)
			if (sa[i]>k) Y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;
		for (i= 1;i<=ls;i++) c[X[i]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= ls;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
		for (i= 1;i<=ls;i++) swap(X[i],Y[i]);
		X[sa[1]]= 1;
		p= 1;
		for (i= 2;i<=ls;i++)
			if (Y[sa[i]]==Y[sa[i-1]]&&Y[sa[i]+k]==Y[sa[i-1]+k])
				X[sa[i]]= p;
			else X[sa[i]]= ++p;
		if (p==ls) return;
		m= p;
	}
}
void getHeight(){
	int i,k= 0;
	for (i= 1;i<=ls;i++){
		if (k) k--;
		int j= sa[rank[i]-1];
		while (s[i+k]==s[j+k]) k++;
		height[rank[i]]= k;
	}
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s%s",s+1, t+1);
	ls= strlen(s+1);
	lt= strlen(t+1);
	s[++ls]= '#';
	m= ls;
	for (i= 1;i<=lt;i++)
		s[++ls]= t[i];
	for (i= 1;i<=ls;i++)
		X[i]= s[i];
	build(300);
	for (i= 1;i<=ls;i++)
		rank[i]= X[i];
	getHeight();
	for (i= 2;i<=ls;i++)
		if ((sa[i-1]<m&&sa[i]>m)||(sa[i-1]>m&&sa[i]<m))
			ans= max(ans,height[i]);
	printf("%d\n",ans);
	return 0;
}
