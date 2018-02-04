#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 30001,oo= 1e8;
struct node{
	int pos,stu,b;
};
node a[maxn],b[maxn];
char c;
int n,T,i,l,t,p;
bool cmp(node a,node b){return a.pos<b.pos;}
bool cmp1(node a,node b){return a.b<b.b;}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int a1= 1;a1<=T;a1++){
		scanf("%d %d %d",&l, &t, &n);
		for (i= 1;i<=n;i++){
			scanf("%d %c",&a[i].pos, &c);
			if (c=='R') a[i].stu= 1;
			else a[i].stu= 0;
			a[i].b= i;
		}
		for (i= 1;i<=n;i++){
			if (a[i].stu) p= 1;
			else p= -1;
			b[i].pos= a[i].pos+p*t;
			b[i].stu= a[i].stu;
		}
		sort(b+1,b+n+1,cmp);
		sort(a+1,a+n+1,cmp);
		b[n+1].pos= oo;
		for (i= 1;i<=n;i++){
			if (b[i].pos==b[i+1].pos)
				b[i].stu= b[i+1].stu= -1;
			a[i].pos= b[i].pos;
			a[i].stu= b[i].stu;
		}
		sort(a+1,a+n+1,cmp1);
		printf("Case #%d:\n",a1);
		for (i= 1;i<=n;i++){
			if (a[i].pos<0 || a[i].pos>l){
				printf("Fell off\n");
				continue;
			}
			printf("%d ",a[i].pos);
			if (a[i].stu==-1) printf("Turning\n");
			else if (a[i].stu==0) printf("L\n");
			else printf("R\n");
		}
		printf("\n");
	}
	return 0;
}
