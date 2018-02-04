#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int maxn= 1000000;
int a[maxn][5];
char ch;
int m,d,t,top,i,l,r,x,o;
void build(int l,int r){
	o++;
	int x= o;
	a[x][1]= l;
	a[x][2]= r;
	if (l+1<r){
		int mid= (l+r)>>1;
		a[x][3]= o+1;
		build(l,mid);
		a[x][4]= o+1;
		build(mid,r);
	}
}
int ask(int o){
	if (a[o][1]>=l && a[o][2]<=r)
		return a[o][0];
	int mid= (a[o][1]+a[o][2])>>1,x= 0,y= 0;
	if (l<mid) x= ask(a[o][3]);
	if (r>mid) y= ask(a[o][4]);
	return max(x,y);
}
void change(int o){
	if (a[o][1]+1==a[o][2]){
		a[o][0]= x;
		return;
	}
	int mid= (a[o][1]+a[o][2])>>1;
	if (top<mid) change(a[o][3]);
	if (mid<top+1) change(a[o][4]);
	a[o][0]= max(a[a[o][3]][0],a[a[o][4]][0]);
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d\n",&m, &d);
	build(1,300000);
	for (i= 1;i<=m;i++){
		scanf("%c %d\n",&ch, &x);
		if (ch=='Q'){
			l= top-x+1;
			r= top+1;
			t= ask(1);
			printf("%d\n",t);
		}else{
			top++;
			l= top;r= top+1;
			x= (x+t)% d;
			change(1);
		}
	}
	return 0;
}
