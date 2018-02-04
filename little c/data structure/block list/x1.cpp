#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn= 10000,size= 20;
struct node *null;
struct node{
	vector<int> g;
	int flip;
	node *ch[1];
};
int c[maxn];
node *head,*left,*right;
int n,m,i,x,y,z;
void location(node *o,int k,node *&p,int &x){
	p= o;
	while (p!=null && p->g.size()<k)
		k-= p->g.size(),p= p->ch[1];
	x= k-1;
}
void split(node *o,int x,node *&right){
	right= new node();
	for (int i= x+1;i<o->g.size();i++)
		right->g.push_back(o->g[i]);
	while (o->g.size()>x+1) o->g.pop_back();
	right->ch[1]= o->ch[1];o->ch[1]->ch[0]= right;
	right->ch[0]= o->ch[1]= null;
}
node *merge(node *left,node *right){
	node *p= left;int i;
	while (p->ch[1]!=null) p= p->ch[1];
	if (p->g.size()+right->g.size()<=2*size){
		for (i= 0;i<right->g.size();i++)
			p->g.push_back(right->g[i]);
		right= right->ch[1];
	}
	p->ch[1]= right;right->ch[0]= p;
	return left;
}
node *build(int n){
	node *o= new node(),*p= o;
	for (int i= 1;i<=n;i++){
		if (p->g.size()>=size){
			p->ch[1]= new node();
			p->ch[1]->ch[0]= p;
			p= p->ch[1];
		}p->g.push_back(c[i]);
	}p->ch[1]= null;
	return o;
}
void reverse(node *o){
	int len= o->g.size();if (!len) return;
	for (int i= 0;i<=(len-1)/2;i++)
		swap(o->g[i],o->g[len-i-1]);
}
void reverse(node *o,int x,int y){
	node *p1,*p2,*mid,*right;
	x--;y= y-x;
	location(o,x,p1,x);
	if (p1->flip)
		reverse(p1),p1->flip= 0;
	split(p1,x,mid);
	location(mid,y,p2,y);
	if (p2->flip)
		reverse(p2),p2->flip= 0;
	split(p2,y,right);
	p1->ch[1]= p2;right->ch[0]= mid;
	mid->ch[0]= right;p2->ch[1]= p1;
	while (mid!=p1){
		mid->flip^= 1;
		swap(mid->ch[0],mid->ch[1]);
		mid= mid->ch[0];
	}
}
void print(node *o){
	while (o!=null){
		if (o->flip){
			reverse(o);
			o->flip= 0;
		}
		for (int i= 0;i<o->g.size();i++)
			printf("%d ",o->g[i]);
		o= o->ch[1];
	}	
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node();
	scanf("%d %d",&n, &m);
	for (i= 1;i<=n;i++)
		scanf("%d",&c[i]);
	head= build(n);
	while (m--){
		scanf("%d %d",&x, &y);
		reverse(head,x,y);
	}
	print(head);
	return 0;
}
