#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 60000;
vector<int> b[maxn];
int a[maxn];
int size,n,m,i,top,x,y,l,r,k,ans,opt;
int low1(int o,int v){
	int l= 0,r= b[o].size();
	while (l<r){
		int mid= (l+r)>>1;
		if (b[o][mid]<v) l= mid+1;
		else r= mid;
	}return l;
}
int rank(int l,int r,int v){
	int i,k= 0;
	int b1= (l-1)/size+1,b2= (r-1)/size+1;
	if (b1==b2){
		for (i= l;i<=r;i++)
			if (a[i]<v) k++;
	}else {
		for (i= l;i<=b1*size;i++)
			if (a[i]<v) k++;
		for (i= (b2-1)*size+1;i<=r;i++)
			if (a[i]<v) k++;
		for (i= b1+1;i<b2;i++)
			k+= low1(i,v);
	}return k+1;
}
int low3(int ll,int rr,int k){
	int l= -1e9;r= 1e9;
	while (l+1<r){
		int mid= (l+r)>>1;
		if (rank(ll,rr,mid)>k) r= mid;
		else l= mid;
	}return l;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	size= sqrt(n);top= 1;
	for (i= 1;i<=n;i++){
		scanf("%d",&a[i]);
		b[top].push_back(a[i]);
		if (b[top].size()==size){
			sort(b[top].begin(),b[top].end());
			top++;
		}
	}
	if (!b[top].size()) sort(b[top].begin(),b[top].end());
	else top--;
	for (i= 1;i<=m;i++){
		char opt;
		do	scanf("%c",&opt);
		while (opt==' ' || opt=='\n');
		if (opt=='Q'){
			scanf("%d %d %d",&l, &r, &k);
			ans= low3(l,r,k);
		}else {
			scanf("%d %d ",&x, &y);
			int b1= (x-1)/size+1,pos= 0;
			while (a[x]!=b[b1][pos]) pos++;
			b[b1][pos]= y;
			while (pos && b[b1][pos]<b[b1][pos-1]){
				swap(b[b1][pos-1],b[b1][pos]);pos--;
			}
			while (pos<b[b1].size()-1 && b[b1][pos]>b[b1][pos+1]){
				swap(b[b1][pos],b[b1][pos+1]);pos++;
			}
			a[x]= y;
		}
		if (opt=='Q')
			printf("%d\n",ans);
	}
	return 0;
}
