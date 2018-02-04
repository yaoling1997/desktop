#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 5e4;
int a[maxn],X[maxn],Y[maxn],sa[maxn],c[maxn];
int height[maxn],rank[maxn];
int n,K,i,j,M;
void build(int m){
	int i;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=n;i++) c[X[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= n;i>0;i--) sa[c[X[i]]--]= i;
	for (int k= 1;k<=n;k<<= 1){
		int p= 0;
		for (i= n-k+1;i<=n;i++)
			Y[++p]= i;
		for (i= 1;i<=n;i++)
			if (sa[i]>k) Y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;
		for (i= 1;i<=n;i++) c[X[i]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= n;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
		swap(X,Y);
		p= 1;
		X[sa[1]]= 1;
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
		while (a[i+k]==a[j+k]) k++;
		height[rank[i]]= k;
	}
}
bool ok(int m){
	int i,now= 1;
	for (i= 2;i<=n;i++)
		if (height[i]>=m){
			now++;
			if (now>=K) return 1;
		}else now= 1;
	return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &K);
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		X[i]= a[i]+1;
		M= max(M,X[i]);
	}
	build(M);
	for (i= 1;i<=n;i++)
		rank[i]= X[i];
	getHeight();
	int l= 1,r= n;
	while (l+1<r){
		int m= (l+r)>>1;
		if (ok(m)) l= m;
		else r= m;
	}
	printf("%d\n",l);
	return 0;
}
