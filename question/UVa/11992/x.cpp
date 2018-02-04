#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 1e7,oo= 1e9;
int left[maxn],right[maxn],sum[maxn],Min[maxn],Max[maxn],I[maxn],S[maxn];
int root[30];
int opt,x1,y1,x2,y2,v,r,c,m,i,j,tot,Q= -1,L,R,_sum,_min,_max;
void init(){
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	memset(sum,0,sizeof(sum));
	memset(Min,0,sizeof(Min));
	memset(Max,0,sizeof(Max));
	memset(I,0,sizeof(I));
	memset(root,0,sizeof(root));
	tot= 0;L= 1;R= c+1;
}
void build(int &o,int l,int r){
	if (!o) o= ++tot;
	S[o]= Q;
	if (l+1==r){
		return;
	}
	int mid= (l+r)>>1;
	build(left[o],l,mid);
	build(right[o],mid,r);
}
void pushdown(int o){
	int l= left[o],r= right[o];
	if (S[o]!=Q){
		I[l]= I[r]= 0;
		S[l]= S[r]= S[o];
	}
	if (I[o]){
		I[l]+= I[o];
		I[r]+= I[o];
	}
	S[o]= Q;
	I[o]= 0;
}
int min(int a,int b,int c){
	return min(min(a,b),c);
}
int max(int a,int b,int c){
	return max(max(a,b),c);
}
void update(int o,int l,int r){
	int ch[2]= {left[o],right[o]},i,mid= (l+r)>>1,LL[2]= {mid-l,r-mid};
	sum[o]= 0;Min[o]= oo;Max[o]= -oo;
	for (i= 0;i<2;i++){
		int j= ch[i],L= LL[i];
		if (S[j]!=Q){
			sum[o]+= L*(S[j]+I[j]);
			Min[o]= min(Min[o],S[j]+I[j]);
			Max[o]= max(Max[o],S[j]+I[j]);
		}else if (S[j]==Q){
			sum[o]+= sum[j]+L*I[j];
			Min[o]= min(Min[o],Min[j]+I[j]);
			Max[o]= max(Max[o],Max[j]+I[j]);
		}
	}
}
void add(int o,int l,int r,int L,int R,int v){
	if (L<=l && r<=R){
		I[o]+= v;
		return;
	}
	pushdown(o);
	int mid= (l+r)>>1;
	if (L<mid) add(left[o],l,mid,L,R,v);
	if (mid<R) add(right[o],mid,r,L,R,v);
	update(o,l,r);
}
void change(int o,int l,int r,int L,int R,int v){
	if (L<=l && r<=R){
		I[o]= 0;
		S[o]= v;
		return;
	}
	pushdown(o);
	int mid= (l+r)>>1;
	if (L<mid) change(left[o],l,mid,L,R,v);
	if (mid<R) change(right[o],mid,r,L,R,v);
	update(o,l,r);
}
void query(int o,int l,int r,int L,int R){
	if (L<=l && r<=R){
		int L= r-l;
		if (S[o]!=Q){
			_sum+= L*(S[o]+I[o]);
			_min= min(_min,S[o]+I[o]);
			_max= max(_max,S[o]+I[o]);			
		}else {
			_sum+= sum[o]+L*I[o];
			_min= min(_min,Min[o]+I[o]);
			_max= max(_max,Max[o]+I[o]);
		}return;
	}
	pushdown(o);
	int mid= (l+r)>>1;
	if (L<mid) query(left[o],l,mid,L,R);
	if (mid<R) query(right[o],mid,r,L,R);
	update(o,l,r);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d%d%d",&r, &c, &m)>0){
		init();
		for (i= 1;i<=r;i++)
			build(root[i],L,R);
		for (int mm= 1;mm<=m;mm++){
			scanf("%d",&opt);
			if (opt==1){
				scanf("%d%d%d%d%d",&x1, &y1, &x2, &y2, &v);
				for (i= x1;i<=x2;i++)
					add(root[i],L,R,y1,y2+1,v);
			}else if (opt==2){
				scanf("%d%d%d%d%d",&x1, &y1, &x2, &y2, &v);
				for (i= x1;i<=x2;i++)
					change(root[i],L,R,y1,y2+1,v);				
			}else {
				scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
				_sum= 0;_min= oo;_max= -oo;
				for (i= x1;i<=x2;i++)
					query(root[i],L,R,y1,y2+1);
				printf("%d %d %d\n",_sum, _min, _max);
			}
		}
	}return 0;
}	
