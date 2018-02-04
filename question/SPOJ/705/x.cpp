#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
char s[maxn];
int X[maxn],Y[maxn],sa[maxn],rank[maxn],height[maxn],c[maxn];
ll ans;
int T,n,i;
void build(int m){
	int i;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=n;i++) c[X[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= n;i>0;i--) sa[c[X[i]]--]= i;
	for (int k= 1;k<=n;k<<= 1){
		int p= 0;
		for (i= n-k+1;i<=n;i++) Y[++p]= i;
		for (i= 1;i<=n;i++)
			if (sa[i]>k)
				Y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;
		for (i= 1;i<=n;i++) c[X[i]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= n;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
		swap(X,Y);
		p= 1;
		X[sa[1]]= p;
		for (i= 2;i<=n;i++)
			if (Y[sa[i]]==Y[sa[i-1]]&&Y[sa[i]+k]==Y[sa[i-1]+k])
				X[sa[i]]= p;
			else X[sa[i]]= ++p;
		if (p==n) break;
		m= p;
	}
}
void getHeight(){
	int i,k= 0;
	for (i= 1;i<=n;i++){
		if (k) k--;
		int j= sa[rank[i]-1];
		while (s[i+k]==s[j+k]) k++;
		height[rank[i]]= k;
	}
}
void getAns(){
	int i;
	ans= n-sa[1]+1;
	for (i= 2;i<=n;i++)
		ans+= n-sa[i]+1-height[i];
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		n= strlen(s+1);
		for (i= 1;i<=n;i++)
			X[i]= s[i];
		build(300);
		for (i= 1;i<=n;i++)
			rank[i]= X[i];
		getHeight();
		getAns();
		cout<<ans<<endl;
	}return 0;
}
