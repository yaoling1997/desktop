#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int maxn= 6e5,maxm= 6e6,oo= 1e9;
struct node{
	int v,l,r,m,p;
	bool operator <(const node &a)const{
		return v<a.v;
	}
};
priority_queue<node> Q;
int a[maxm],b[maxm];
int A[maxn];
ll ans;
int n,K,L,R,i,x,y,m,p,now,nowp;
void build(int o,int l,int r){
	if (l+1<r){
		int mid= (l+r)>>1;
		build(2*o,l,mid);
		build(2*o+1,mid,r);
		if (a[2*o]<a[2*o+1]){
			a[o]= a[2*o];
			b[o]= b[2*o];
		}else {
			a[o]= a[2*o+1];
			b[o]= b[2*o+1];
		}
	}else a[o]= A[l],b[o]= l;
}
void find(int o,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		if (now>a[o]) now= a[o],nowp= b[o];
		return;
	}
	int mid= (l+r)>>1;
	if (x<mid) find(2*o,l,mid,x,y);
	if (mid<y) find(2*o+1,mid,r,x,y);
}
void Find(int x,int y){
	now= oo;
	find(1,0,n+1,x,y+1);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d %d %d",&n, &K, &L, &R);
	for (i= 1;i<=n;i++){
		scanf("%d",&A[i]);
		A[i]+= A[i-1];
	}
	build(1,0,n+1);
	for (i= L;i<=n;i++){
		x= max(0,i-R);y= max(0,i-L);
		Find(x,y);
		Q.push((node){A[i]-now,x,y,nowp,i});
	}
	for (i= 1;i<=K;i++){
		node u= Q.top();Q.pop();
		ans+= u.v;
		x= u.l,y= u.r,m= u.m,p= u.p;
		if (x<=m-1){
			Find(x,m-1);
			Q.push((node){A[p]-now,x,m-1,nowp,p});
		}if (m+1<=y){
			Find(m+1,y);
			Q.push((node){A[p]-now,m+1,y,nowp,p});
		}
	}printf("%lld",ans);
	return 0;
}
