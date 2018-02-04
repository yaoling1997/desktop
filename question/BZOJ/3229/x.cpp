#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int oo= 1e8;
const int maxn= 60000;
struct node *null;
struct node{
	node *ch[2];
	int v;
	node(int x):v(x){ch[0]= ch[1]= null;}
};
node *head,*p,*q,*g;
int n,i,j,k,x,ans;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node(0);
	while (scanf("%d",&n)!=EOF&&n!=0){
		head= q= p= new node(oo);ans= 0;
		for (i= 1;i<=n;i++){
			scanf("%d",&x);
			p= new node(x);
			q->ch[1]= p;p->ch[0]= q;
			q= p;
		}
		q->ch[1]= new node(oo);
		q->ch[1]->ch[0]= q;
		for (int a1= 1;a1<n;a1++){
			p= head;q= head->ch[1];g= q->ch[1];
			while (true){
				if (p->v<=g->v) break;
				p= p->ch[1],q= q->ch[1],g= g->ch[1];
			}
			ans+= x= p->v+q->v;
			p= p->ch[0];
			p->ch[1]= g;
			g->ch[0]= p;
			g= g->ch[0];
			while (g->v<=x)
				g= g->ch[0];			
			p= new node(x);
			p->ch[1]= g->ch[1];
			g->ch[1]->ch[0]= p;
			g->ch[1]= p;
			p->ch[0]= g;			
		}
		printf("%d\n",ans);
	}
	return 0;
}
