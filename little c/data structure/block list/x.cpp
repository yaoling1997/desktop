#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
const int maxn= 3001,size= 4;
struct node *null;
struct node{
	vector<int> g;
	node *ch;
	node(){ch= null;}
};
int c[maxn];
node *head,*p,*left,*right,*mid;
int n,m,i,j,x,y,z;
void location(node *o,int k,node *&p,int &x){
	p= o;
	while (p->g.size()<k && p!=null)
		k-= p->g.size(),p= p->ch;
	x= k-1;
}
void split(node *left,int x,node *&right){
	int i;node *p;right= new node();
	location(left,x,p,x);
	for (i= x+1;i<p->g.size();i++)
		right->g.push_back(p->g[i]);
	while (p->g.size()>x+1) p->g.pop_back();
	right->ch= p->ch;p->ch= null;
}
node *merge(node *left, node*right){
	node *p= left;int i;
	while (p->ch!=null) p= p->ch;
	if (p->g.size()+right->g.size()<=2*size){
		for (i= 0;i<right->g.size();i++)
			p->g.push_back(right->g[i]);
		right= right->ch;
	}
	p->ch= right;
	return left;
}
void change(node *o,int x,int y){
	node *p;
	location(o,x,p,x);
	p->g[x]= y;
}
void print(node *o){
	if (o==null) return;
	for (int i= 0;i<o->g.size();i++)
		printf("%d ",o->g[i]);
	print(o->ch);
}
node *build(int n){
	node *o= new node(),*p= o;
	for (int i= 1;i<=n;i++){
		if (p->g.size()>=size){
			p->ch= new node();
			p= p->ch;
		}
		p->g.push_back(c[i]);
	}
	return o;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d %d",&n, &m);
	null= new node();
	for (i= 1;i<=n;i++)
		scanf("%d",&c[i]);
	head= build(n);
	for (i= 1;i<=m;i++){
		scanf("%d",&x);
		if (x==1){
			scanf("%d %d",&x, &y);
			for (j= 1;j<=y;j++)
				scanf("%d",&c[j]);
			mid= build(y);
			split(head,x,right);
			head= merge(merge(head,mid),right);
		}else if (x==2){
			scanf("%d %d",&x, &y);
			split(head,x-1,left);
			split(left,y-x+1,right);
			merge(head,right);
		}else {
			scanf("%d %d",&x, &y);
			change(head,x,y);
		}
	}
	print(head);
	return 0;
}
