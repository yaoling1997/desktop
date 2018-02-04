#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001,L= -1000,R= 1001;
int a[maxn],left[maxn],right[maxn],size[maxn];
int n,m,i,x,y,z,tot,ans;
int change(int o,int l,int r,int v,int w){
	int u= ++tot;
	size[u]= size[o]+w;
	if (l+1==r){
		left[u]= right[u]= 0;
		return u;
	}
	int mid= (l+r)>>1;
	if (v<mid){
		right[u]= right[o];
		left[u]= change(left[o],l,mid,v,w);
	}else {
		left[u]= left[o];
		right[u]= change(right[o],mid,r,v,w);
	}return u;
}
int ask(int x,int y,int k){
	if (y-x+1<k) return 0;
	int l= L,r= R;
	x= a[x-1];y= a[y];
	while (l+1<r){
		int mid= (l+r)>>1;
		if (size[left[y]]-size[left[x]]>=k){
			x= left[x];
			y= left[y];
			r= mid;
		}else {
			k-= size[left[y]]-size[left[x]];
			x= right[x];
			y= right[y];
			l= mid;
		}
	}return l;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);
		a[i]= change(a[i-1],L,R,x,1);
	}
	for (i= 1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &z);
		ans= ask(x,y,z);
		printf("%d\n",ans);
	}return 0;
}
