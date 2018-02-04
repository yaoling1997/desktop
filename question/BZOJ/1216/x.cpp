#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 33001;
int b[6];
int a1,a2,a3,a4,top,m;
struct node{
	int a1,a2,a3,a4;
};
node a[maxn];
bool operator <(node a,node b){return a.a4<b.a4 || (a.a4==b.a4 && a.a2>b.a2);}
void up(int o){
	while (o/2){
		int u= o/2;
		if (a[u].a4<a[o].a4){
			swap(a[u],a[o]);
		}else break;
		o/= 2;
	}
}
void down(int o){
	int t= o;
	if (2*o<=top && a[t]<a[2*o]) t= 2*o;
	if (2*o+1<=top && a[t]<a[2*o+1]) t= 2*o+1;
	if (t!=o){
		swap(a[t],a[o]);
		down(t);
	}
}
void add(){
	a[++top]= (node){a1,a2,a3,a4};
	up(top);
}
void pop(){
	m+= a[1].a3;
	printf("%d %d\n",a[1].a1,m);
	a[1]= a[top--];
	down(1);
	if (top && a[1].a2>m) m= a[1].a2;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while(scanf("%d %d %d %d",&a1, &a2, &a3, &a4)!=-1){
		b[1]= a1;b[2]= a2;b[3]= a3;b[4]= a4;
		while (top && (m+a[1].a3<=a2))
			pop();
		if (top==0){
			m= a2;
			add();
			continue;
		}
		if (a[1].a4>=a4)
			add();
		else {
			a[1].a3-= a2-m;m= a2;
			add();
		}
	}
	while (top)
		pop();
	return 0;
}
