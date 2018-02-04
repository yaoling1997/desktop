#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxl= 30001,maxn= 10000000,L= -1e9-1,R= 1e9+1;
int c[maxl],a[maxl],left[maxn],right[maxn],size[maxn],sta[maxl],stb[maxl];
int n,q,i,l,r,k,x,y,tot,ans;
char ch;
int lowbit(int o){return o&(-o);}
void insert(int &o,int l,int r,int v){
	if (!o)	o= ++tot;
	size[o]++;
	if (l+1==r) return;
	int mid= l+((r-l)>>1);
	if (v<mid) insert(left[o],l,mid,v);
	else insert(right[o],mid,r,v);
}
int remove(int o,int l,int r,int v){
	if (!o) return 0;
	if (l+1==r){
		if (!size[o]) return 0;
		return size[o]--;
	}
	int mid= l+((r-l)>>1),y= size[o];
	if (v<mid){
		if (remove(left[o],l,mid,v)) size[o]--;
	}else if (remove(right[o],mid,r,v)) size[o]--;
	return size[o]!=y;
}
void add(int o,int x){
	while (o<=n){
		insert(a[o],L,R,x);
		o+= lowbit(o);
	}
}
void change(int o,int k){
	int x= c[o];
	while (o<=n){
		remove(a[o],L,R,x);
		insert(a[o],L,R,k);
		o+= lowbit(o);
	}
}
int ask(int x,int y,int k){
	int l= L,r= R,la= 0,lb= 0;
	int o= x-1;
	while (o>0){
		sta[++la]= a[o];
		o-= lowbit(o);
	}
	o= y;
	while (o>0){
		stb[++lb]= a[o];
		o-= lowbit(o);
	}
	while (l+1<r){
		int i,mid= l+((r-l)>>1);
		int suma= 0,sumb= 0;
		for (i= 1;i<=la;i++)
			suma+= size[left[sta[i]]];
		for (i= 1;i<=lb;i++)
			sumb+= size[left[stb[i]]];
		if (sumb-suma>=k){
			for (i= 1;i<=la;i++)
				sta[i]= left[sta[i]];
			for (i= 1;i<=lb;i++)
				stb[i]= left[stb[i]];
			r= mid;
		}else {
			k-= sumb-suma;
			for (i= 1;i<=la;i++)
				sta[i]= right[sta[i]];
			for (i= 1;i<=lb;i++)
				stb[i]= right[stb[i]];
			l= mid;
		}
	}return l;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &q);
	for (i= 1;i<=n;i++){
		scanf("%d",&c[i]);
		add(i,c[i]);
	}
	for (i= 1;i<=q;i++){
		do scanf("%c",&ch);
		while (ch==' ' || ch=='\n');
		if (ch=='Q'){
			scanf("%d %d %d",&l, &r, &k);
			ans= ask(l,r,k);
			printf("%d\n",ans);
		}else {
			scanf("%d %d",&x, &y);
			change(x,y);
			c[x]= y;
		}
	}
	return 0;
}
