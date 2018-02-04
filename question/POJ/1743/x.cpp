#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 4e4+2;
int a[maxn],X[maxn],Y[maxn],sa[maxn],d[maxn];
int height[maxn],rank[maxn],c[maxn];
int i,n;
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
		while (d[i+k]==d[j+k]) k++;
		height[rank[i]]= k;
	}
}
bool ok(int m){
	int i,Min,Max;
	Min= Max= sa[1];
	for (i= 2;i<=n;i++)
		if (height[i]>=m){
			Min= min(Min,sa[i]);
			Max= max(Max,sa[i]);
			if (Max-Min>=m) return 1;
		}else {
			Min= sa[i];
			Max= sa[i];
		}
	return 0;
}
void init(){
	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%d",&a[i]);
			d[i]= a[i]-a[i-1];
			X[i]= d[i]+100;
		}d[1]= 200;
		build(200);
		for (i= 1;i<=n;i++)
			rank[i]= X[i];
		getHeight();
		int l= 3,r= n;
		while (l+1<r){
			int m= (l+r)>>1;
			if (ok(m)) l= m;
			else r= m;
		}
		if (l<4) printf("0\n");
		else printf("%d\n",l+1);
	}return 0;	
}
