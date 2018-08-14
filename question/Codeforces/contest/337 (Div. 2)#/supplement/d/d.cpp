#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 4e5;
struct point{
	int x,y;
};
struct node{
	int o,x,y;
}N[maxn];
struct line{
	point a,b;
}X[maxn],Y[maxn],nx[maxn],ny[maxn];
map<int,int> M;
int c[maxn],v[maxn];
point a,b;
ll ans;
int n,x,y,x0,y0,i,j,I,J,k,K,lx,ly,nlx,nly,top,lv,Max;
bool cmpx(line a,line b){
	return a.a.x<b.a.x||(a.a.x==b.a.x&&a.a.y<b.a.y)||(a.a.x==b.a.x&&a.a.y==b.a.y&&a.b.y<b.b.y);
}
bool cmpy(line a,line b){
	return a.a.y<b.a.y||(a.a.y==b.a.y&&a.a.x<b.a.x)||(a.a.y==b.a.y&&a.a.x==b.a.x&&a.b.x<b.b.x);
}
bool cmpn(node a,node b){
	return a.x<b.x;
}
int lowbit(int o){
	return o&-o;
}
void change(int o,int x){
	while (o<=Max){
		c[o]+= x;
		o+= lowbit(o);
	}
}
int find(int o){
	int re= 0;
	while (o){
		re+= c[o];
		o-= lowbit(o);
	}
	return re;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d%d%d%d",&x, &y, &x0, &y0);
		if (!M.count(y)){
			M[y]= 0;
			v[++lv]= y;
		}
		if (!M.count(y0)){
			M[y0]= 0;
			v[++lv]= y0;
		}
		a= (point){x,y};
		b= (point){x0,y0};
		if (x==x0){
			lx++;
			if (a.y>b.y) swap(a,b);
			X[lx]= (line){a,b};
		}else {
			ly++;
			if (a.x>b.x) swap(a,b);
			Y[ly]= (line){a,b};
		}
	}
	sort(X+1,X+lx+1,cmpx);
	sort(Y+1,Y+ly+1,cmpy);
	for (i= 1;i<=lx;i= j){
		j= i;
		while (j<=lx&&X[i].a.x==X[j].a.x) j++;
		ans+= X[i].b.y-X[i].a.y+1;
		int p= i;
		a= X[p].a;
		b= X[p].b;		
		for (k= i+1;k<j;k++)
			if (X[k].a.y<=b.y){
				ans+= max(X[k].b.y-b.y,0);
				if (X[k].b.y>b.y) b= X[k].b;
			}else {
				ans+= X[k].b.y-X[k].a.y+1;				
				nx[++nlx]= (line){a,b};
				p= k;
				a= X[p].a;
				b= X[p].b;				
			}
		nx[++nlx]= (line){a,b};
	}
	for (i= 1;i<=ly;i= j){
		j= i;
		while (j<=ly&&Y[i].a.y==Y[j].a.y) j++;
		ans+= Y[i].b.x-Y[i].a.x+1;
		int p= i;
		a= Y[p].a;
		b= Y[p].b;		
		for (k= i+1;k<j;k++)
			if (Y[k].a.x<=b.x){
				ans+= max(Y[k].b.x-b.x,0);
				if (Y[k].b.x>b.x) b= Y[k].b;
			}else {
				ans+= Y[k].b.x-Y[k].a.x+1;				
				ny[++nly]= (line){a,b};
				p= k;
				a= Y[p].a;
				b= Y[p].b;						
			}
		ny[++nly]= (line){a,b};
	}
	for (i= 1;i<=nly;i++){
		N[++top]= (node){1,ny[i].a.x,ny[i].a.y};
		N[++top]= (node){-1,ny[i].b.x,ny[i].b.y};		
	}
	sort(N+1,N+top+1,cmpn);
	sort(v+1,v+lv+1);
	for (i= 1;i<=lv;i++)
		M[v[i]]= i;
	for (i= 1;i<=top;i++)
		N[i].y= M[N[i].y];
	for (i= 1;i<=nlx;i++){
		nx[i].a.y= M[nx[i].a.y];
		nx[i].b.y= M[nx[i].b.y];		
	}
	Max= lv;
	j= 0;
	for (i= 1;i<=nlx;i= I){
		I= i;
		while (I<=nlx&&nx[I].a.x==nx[i].a.x) I++;
		while (j+1<=top&&N[j+1].x<nx[i].a.x){
			j++;
			change(N[j].y,N[j].o);
		}
		J= j;
		while (J+1<=top&&N[J+1].x<=nx[i].a.x) J++;
		for (k= j+1;k<=J;k++)
			if (N[k].o==1) change(N[k].y,N[k].o);
		for (k= i;k<I;k++)
			ans-= find(nx[k].b.y)-find(nx[k].a.y-1);
		for (k= j+1;k<=J;k++)
			if (N[k].o==-1) change(N[k].y,N[k].o);
		j= J;
	}
	printf("%I64d\n",ans);
	return 0;
}
