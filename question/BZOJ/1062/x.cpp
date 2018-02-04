#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int maxn= 5510,A= 10,B= 2001,lim= 3010,lim1= 5500,lim2= 4010;
struct node{
	int x,y;
};
map<int,node> X;
int a[3100][4100],b[3100][maxn];
int n,m,r,i,T,C,L,R,D,x,y,z,ans,ooo;
int lowbit(int o){return o & (-o);}
void change(int o,int x,int y,int w){
	int i= x,j= y;
	if (!o)
		while (i<=lim){
			j= y;
			while (j<=lim2){
				a[i][j]+= w;
				j+= lowbit(j);
			}i+= lowbit(i);
		}
	else
		while (i<=lim){
			j= y;
			while (j<=lim1){
				b[i][j]+= w;
				j+= lowbit(j);
			}i+= lowbit(i);
		}
}
int ask(int o,int x,int y){
	if (x<0) return 0;
	int re= 0,i= x,j= y;
	if (!o)
		while (i){
			j= y;
			while (j){
				re+= a[i][j];
				j-= lowbit(j);
			}i-= lowbit(i);
		}
	else
		while (i){
			j= y;
			while (j){
				re+= b[i][j];
				j-= lowbit(j);
			}i-= lowbit(i);
		}		
	return re;
}
void Change(int w){
	change(0,T+A,R+T+A,w);
	if (T>=r) change(1,T+A-r,R+m-T+B,w);
	if (T<=r) change(0,T+m+A,R+T+m+A,w);
	change(1,T+m+A-r,R+m-(T+m)+B,w);	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &r);m= 2*r;
	for (int a1= 1;a1<=n;a1++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d %d %d %d %d",&T, &C, &L, &R, &D);
			R= R-L;
			T= T-L*D;
			T= (T+m)%m;
			Change(1);
			X[C]= (node){T,R};
		}else if (x==2){
			scanf("%d %d %d",&T, &L, &R);
			T%= m;
			x= R;y= L-R;ans= 0;
			x+= T;y+= x;
			if (x>=lim)	ooo++;
			ans+= ask(0,x+A,lim2)-ask(0,x-R-1+A,lim2)-ask(0,x-1+A,y-1+A)+ask(0,x-R-1+A,y-1+A);
			x= m;y= L;
			x+= T;y= y+m-x;
			if (x>=lim1)	ooo++;
			z= R==r;
			ans+= ask(1,x-1+A-r,lim1)-ask(1,x-R-1+z+A-r,lim1)-ask(1,x-1+A-r,y-1+B)+ask(1,x-R-1+z+A-r,y-1+B);				
			printf("%d\n",ans);
		}else {
			scanf("%d %d",&T, &C);
			T= X[C].x;
			R= X[C].y;
			X.erase(C);
			Change(-1);
		}
	}return 0;
}

