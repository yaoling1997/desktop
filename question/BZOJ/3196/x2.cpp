#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 20000001,maxm= 1e8+10;
int c[maxn],l1[maxn],l2[maxn],r1[maxn],r2[maxn],size[maxn];
int a[maxn],stack[maxn];
int x,y,top,tot,root,n,m,i,ans,k,la,orz,gg;
void insert(int &o,int l,int r){
	if (!o) o= ++top;
	size[o]++;
	if (l+1==r) return;
	int mid= (l+r)>>1;
	if (x<mid) insert(l2[o],l,mid);
	else insert(r2[o],mid,r);
}
int remove(int &o,int l,int r){
	if (!o) return 0;
	int mid= (l+r)>>1,y= size[o];
	if (l+1==r){
		if (!size[o]) return 0;
		return size[o]--;
	}else {
		if (x<mid){
			if (remove(l2[o],l,mid)) size[o]--;
		}
		else if (remove(r2[o],mid,r)) size[o]--;
	}return (size[o]!=y);
}
void insert2(int &o,int l,int r){
	if (!o) o= ++tot;
	insert(a[o],0,maxm);
	if (l+1==r) return;
	int mid= (l+r)>>1;
	if (i<mid) insert2(l1[o],l,mid);
	else insert2(r1[o],mid,r);
}
int cmp(int o,int k){
	return k>size[l2[o]];
}
int find0(int o,int l,int r,int k){
	if (!o) return 0;
	int mid= (l+r)>>1,g;
	if (k<mid) g= find0(l2[o],l,mid,k);
	else g= find0(r2[o],mid,r,k)+size[l2[o]];
	return g;
}
int find(int o,int l,int r,int k){
	if (l+1==r) return l;
	int d= cmp(o,k),mid= (l+r)>>1;
	if (!d){k-= size[l2[o]];return find(r2[o],mid,r,k);}
	return find(l2[o],l,mid,k);
}
void find1(int o,int l,int r){
	if (x<=l && r<=y) {ans+= find0(a[o],0,maxm,k);return;}
	int mid= (l+r)>>1;
	if (x<mid) find1(l1[o],l,mid);
	if (y>mid) find1(r1[o],mid,r);
}
void push(int o,int l,int r){
	if (x<=l && r<=y){
		stack[++la]= a[o];
		return;
	}
	int mid= (l+r)>>1;
	if (x<mid) push(l1[o],l,mid);
	if (mid<y) push(r1[o],mid,r);
}
void find2(int k){
	push(root,1,n+1);
	int l= 0,r= maxm;
	while (l+1!=r){
		int mid= (l+r)>>1,sum= 0;
		for (i= 1;i<=la;i++)
			sum+= size[l2[stack[i]]];
		if (sum<k){
			k-= sum;
			for (i= 1;i<=la;i++)
				stack[i]= r2[stack[i]];
			l= mid;
		}else {
			for (int i= 1;i<=la;i++) stack[i]= l2[stack[i]];
			r= mid;
		}
	}ans= l;
}
void change(int o,int l,int r,int y){
	if (l+1==r){
		remove(a[o],0,maxm);swap(orz,x);
		insert(a[o],0,maxm);swap(orz,x);
	}else {
		int mid= (l+r)>>1;
		if (y<mid) change(l1[o],l,mid,y);
		else change(r1[o],mid,r,y);
		remove(a[o],0,maxm);swap(orz,x);
		insert(a[o],0,maxm);swap(orz,x);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++){
		scanf("%d",&x);c[i]= x;
		insert2(root,1,n+1);
	}
	for (gg= 1;gg<=m;gg++){
		scanf("%d",&x);ans= la= 0;
		if (x==1){
			scanf("%d %d %d",&x, &y, &k);y++;
			find1(root,1,n+1);
			printf("%d\n",ans+1);
		}else if (x==2){
			scanf("%d %d %d",&x, &y, &k);y++;
			find2(k);
			printf("%d\n",ans);
		}else if (x==3){
			scanf("%d %d",&y, &x);orz= x;x= c[y];c[y]= orz;
			change(root,1,n+1,y);
		}else if (x==4){
			scanf("%d %d %d",&x, &y, &k);y++;
			find1(root,1,n+1);
			find2(ans);
			if (ans<10000000) printf("%d\n",ans);
		}else {
			scanf("%d %d %d",&x, &y, &k);k++;y++;
			find1(root,1,n+1);
			find2(ans+1);
			if (ans<10000000) printf("%d\n",ans);
		}
	}
	return 0;
}
