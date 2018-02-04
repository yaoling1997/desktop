#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 600000;
vector<int> b[maxn];
int a[maxn];
int i,j,n,m,u,k,p,v,x,top,size,l,r;
int lowbound(int o,int x){
	int l= 0,r= b[o].size();
	while (l<r){
		int mid= (l+r)>>1;
		if (b[o][mid]<x) l= mid+1;
		else r= mid;
	}
	return l;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d",&n, &m, &u);
	size= sqrt(n)+1;top= 1;
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		b[top].push_back(a[i]);
		if (b[top].size()==size) {
			sort(b[top].begin(),b[top].end());
			top++;
		}
	}
	if (!b[top].size()) top--;
	sort(b[top].begin(),b[top].end());
	for (i= 1;i<=m;i++){
		scanf("%d %d %d %d",&l, &r, &v, &p);
		int b1= (l-1)/size+1,b2= (r-1)/size+1;k= 0;
		if (b1==b2){
			for (j= l;j<=r;j++)
				if (a[j]<v) k++;
		}else {
			for (j= l;j<=b1*size;j++)
				if (a[j]<v) k++;
			for (j= (b2-1)*size+1;j<=r;j++)
				if (a[j]<v) k++;
			for (j= b1+1;j<b2;j++)
				k+= lowbound(j,v);
		}
		int x= (long long) u*k/(r-l+1),pos= 0;
		b1= (p-1)/size+1;
		while (b[b1][pos]!=a[p]) pos++;
		b[b1][pos]= x;
		while (pos && b[b1][pos]<b[b1][pos-1]){
			swap(b[b1][pos],b[b1][pos-1]);
			pos--;
		}
		while (pos<size-1 && b[b1][pos]>b[b1][pos+1]){
			swap(b[b1][pos],b[b1][pos+1]);
			pos++;
		}
		a[p]= x;
	}
	for (i= 1;i<=n;i++)
		printf("%d\n",a[i]);
	return 0;
}
