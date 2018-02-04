#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 5000,oo= 1e9;
int Max[maxn][maxn],Min[maxn][maxn],c[maxn][maxn];
int xo,xleaf,n,m,i,j,x1,x2,y1,y2,vmax,vmin,v,q;
void build1(int o,int l,int r){
	if (l+1==r){
		if (xleaf){Max[xo][o]= Min[xo][o]= c[xleaf][l];return;}
		Max[xo][o]= max(Max[2*xo][o],Max[2*xo+1][o]);
		Min[xo][o]= min(Min[2*xo][o],Min[2*xo+1][o]);
	}else {
		int mid= (l+r)>>1;
		build1(2*o,l,mid);
		build1(2*o+1,mid,r);
		Max[xo][o]= max(Max[xo][2*o],Max[xo][2*o+1]);
		Min[xo][o]= min(Min[xo][2*o],Min[xo][2*o+1]);
	}
}
void build2(int o,int l,int r){
	if (l+1==r){xo= o;xleaf= l;build1(1,1,m+1);}
	else {
		int mid= (l+r)>>1;
		build2(2*o,l,mid);
		build2(2*o+1,mid,r);
		xo= o;xleaf= 0;build1(1,1,m+1);
	}
}
void ask1(int o,int l,int r){
	if (y1<=l && r<=y2){
		vmax= max(vmax,Max[xo][o]);
		vmin= min(vmin,Min[xo][o]);
	}else {
		int mid= (l+r)>>1;
		if (y1<mid) ask1(2*o,l,mid);
		if (y2>mid) ask1(2*o+1,mid,r);
	}
}
void ask2(int o,int l,int r){
	if (x1<=l && x2>=r){xo= o;ask1(1,1,m+1);}
	else {
		int mid= (l+r)>>1;
		if (x1<mid) ask2(2*o,l,mid);
		if (x2>mid) ask2(2*o+1,mid,r);
	}
}
void change1(int o,int l,int r){
	if (l+1==r){
		if (xleaf){Max[xo][o]= Min[xo][o]= v;return;}
		Max[xo][o]= max(Max[2*xo][o],Max[2*xo+1][o]);
		Min[xo][o]= min(Min[2*xo][o],Min[2*xo+1][o]);
	}else {
		int mid= (l+r)>>1;
		if (y1<mid) change1(2*o,l,mid);
		if (mid<y2) change1(2*o+1,mid,r);
		Max[xo][o]= max(Max[xo][2*o],Max[xo][2*o+1]);
		Min[xo][o]= min(Min[xo][2*o],Min[xo][2*o+1]);
	}
}
void change2(int o,int l,int r){
	if (l+1==r){xo= o;xleaf= 1;change1(1,1,m+1);}
	else {
		int mid= (l+r)>>1;
		if (x1<mid) change2(2*o,l,mid);
		if (mid<x2) change2(2*o+1,mid,r);
		xo= o;xleaf= 0;change1(1,1,m+1);
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		for (j= 1;j<=m;j++)
			scanf("%d",&c[i][j]);
	build2(1,1,n+1);
	scanf("%d\n",&q);
	for (i= 1;i<=q;i++){
		char ch;
		scanf("%c",&ch);
		if (ch=='q'){
			vmin= oo;vmax= -oo;
			scanf("%d %d %d %d\n",&x1, &y1, &x2, &y2);
			x2++;y2++;
			ask2(1,1,n+1);
			printf("%d %d\n",vmax, vmin);
		}else {
			scanf("%d %d %d\n",&x1,&y1,&v);
			x2= x1+1;y2= y1+1;
			change2(1,1,n+1);
		}
	}
	return 0;
}
