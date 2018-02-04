#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 4e5,maxm= 7e6;
struct node{
	int o,l,r;
};
node sta[10];
char s[maxn];
int c[maxn],f[maxn];
int left[maxm],right[maxm],S[maxm],Z[maxm],Min[maxm];
int n,m,i,x,y,z,tot,root,L,R,now,la;
//S[]当前子树是否有-1,Z[]区间标记,Min[]区间最小值
void init(){
	memset(s,0,sizeof(s));          
	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	memset(S,0,sizeof(S));
	memset(Z,0,sizeof(Z));
	memset(Min,0,sizeof(Min));
	L= 1;R= n+1;tot= root= 0;
}
void pushdown(int o){
	Z[left[o]]+= Z[o];
	Z[right[o]]+= Z[o];
	Z[o]= 0;
}
void update(int o){
	int l= left[o],r= right[o];
	S[o]= S[l]||S[r];
	Min[o]= min(Min[l]+Z[l],Min[r]+Z[r]);
}
void build(int &o,int l,int r){
	if (!o) o= ++tot;
	if (l+1==r){
		S[o]= c[l]==-1?1:0;
		Min[o]= f[l];
		return;
	}
	int mid= (l+r)>>1;
	build(left[o],l,mid);
	build(right[o],mid,r);	
	update(o);
}
void find(int o,int l,int r,int L,int R){
	if (l==r) return;
	if (l>=R) return;
	if (l+1==r){
		now= l;
		return;
	}
	pushdown(o);
	int mid= (l+r)>>1;
	if (S[left[o]]) find(left[o],l,mid,L,R);
	else find(right[o],mid,r,L,R);
	update(o);
}
void change(int o,int l,int r,int v,int x){
	if (l==r) return;
	if (l+1==r){
		S[o]= c[l]==-1?1:0;
		return;
	}
	pushdown(o);
	int mid= (l+r)>>1;
	if (v<mid) change(left[o],l,mid,v,x);
	else change(right[o],mid,r,v,x);
	update(o);
}
void modify(int o,int l,int r,int L,int R,int x){
	if (l==r) return;	
	if (L<=l&&r<=R){
		Z[o]+= x;
		return;
	}
	pushdown(o);
	int mid= (l+r)>>1;
	if (L<mid) modify(left[o],l,mid,L,R,x);
	if (mid<R) modify(right[o],mid,r,L,R,x);
	update(o);
}
void ask(int o,int l,int r,int L,int R){
	if (l==r) return;	
	if (L<=l&&r<=R){
		sta[++la]= (node){o,l,r};
		return;
	}
	pushdown(o);
	int mid= (l+r)>>1;
	if (L<mid) ask(left[o],l,mid,L,R);
	if (mid<R) ask(right[o],mid,r,L,R);
	update(o);
}
void go(int o,int l,int r){
	if (l==r) return;	
	if (l+1==r){
		if (Min[o]+Z[o]>=2)
			now= l;
		return;
	}
	pushdown(o);
	int mid= (l+r)>>1;
	if (Min[right[o]]+Z[right[o]]>=2){
		now= mid;
		go(left[o],l,mid);
	}else {
		go(right[o],mid,r);
	}update(o);
}
void Ask(int x){	
	la= 0;now= x;
	ask(root,L,R,1,x);
	while (la){
		int o= sta[la].o;
		if (Min[o]+Z[o]>=2){
			now= sta[la].l;
			la--;
		}else break;
	}
	go(sta[la].o,sta[la].l,sta[la].r);
}
int main()
{
	while (scanf("%d%d",&n, &m)>0){
		init();
		scanf("%s",s+1);
		for (i= 1;i<=n;i++){
			c[i]= s[i]=='(' ? 1:-1;
			f[i]= f[i-1]+c[i];
		}
		build(root,L,R);
		for (int MM= 1;MM<=m;MM++){
			scanf("%d",&x);
			now= x;
			if (c[x]==1){
				c[x]= -1;
				find(root,L,R,1,x);
				c[now]= 1;
				change(root,L,R,x,-1);
				change(root,L,R,now,1);
				modify(root,L,R,now,x,2);
			}else {
				c[x]= 1;
				Ask(x);
				c[now]= -1;
				change(root,L,R,x,1);
				change(root,L,R,now,-1);
				modify(root,L,R,now,x,-2);
			}
			printf("%d\n",now);
		}
	}return 0;
}

