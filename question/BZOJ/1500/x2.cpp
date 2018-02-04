#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn= 400000,size= 820,oo= 1e8;
struct node *null;
struct node{
	vector<int> g;
	int flip,z,sum,m,l,r;
	node *ch[2];
	void clear(){
		g.clear();
		flip= sum= m= l= r= 0;z= -oo;ch[0]= ch[1]= null;
	}
	void reverse(){
		int len= g.size(),i;
		for (i= 0;i<(len+1)/2;i++)
			swap(g[i],g[len-i-1]);
		swap(l,r);
	}
	void mt(){
		int len= g.size(),i,ml= 0,mm= -oo;
		sum= 0;m= l= r= -oo;
		for (i= 0;i<len;i++){
			sum+= g[i];
			ml+= g[i];mm= max(mm+g[i],g[i]);
			l= max(l,ml);m= max(m,mm);			
		}ml= 0;
		for (i= len-1;i>=0;i--){
			ml+= g[i];r= max(r,ml);
		}
	}
	void change(){
		int len= g.size(),i;
		for (i= 0;i<len;i++)
			g[i]= z;
		z= -oo;mt();
	}
	void pushdown(){
		if (flip) reverse();
		flip= 0;
		if (z!=-oo) change();
	}
	node():flip(0),z(-oo),sum(0){ch[0]= ch[1]= null;}
};
node *stack[maxn];
int c[maxn],b[maxn];
char ch;
node *head,*right;
int n,m,i,x,y,z,top,ans,tot;
node *create(){
	if (top) return stack[top--];
	else return new node();
}
void location(node *o,int k,node *&p,int &x){
	p= o;
	while (p!=null && p->g.size()<k)
		k-= p->g.size(),p= p->ch[1];
	p->pushdown();
	x= k-1;
}
void split(node *o,int x,node *&right){
	//right= new node();
	right= create();
	for (int i= x+1;i<o->g.size();i++)
		right->g.push_back(o->g[i]);
	while (o->g.size()>x+1) o->g.pop_back();
	right->ch[1]= o->ch[1];o->ch[1]->ch[0]= right;
	right->ch[0]= o->ch[1]= null;
	o->mt();right->mt();
}
node *merge(node *left,node *right){
	node *p= left;int i;
	while (p->ch[1]!=null) p= p->ch[1];
	if (p->g.size()+right->g.size()<2*size){
		p->pushdown();right->pushdown();
		for (i= 0;i<right->g.size();i++)
			p->g.push_back(right->g[i]);
		//stack[++top]= right;
		node *q= right;
		right= right->ch[1];
		q->clear();
		stack[++top]= q;
		//stack[++top]->clear();
		p->mt();
	}
	p->ch[1]= right;right->ch[0]= p;
	return left;
}
node *build(int n){
	node *o= create(),*p= o;
	for (int i= 1;i<=n;i++){
		if (p->g.size()>=size){
			p->mt();
			p->ch[1]= create();
			p->ch[1]->ch[0]= p;
			p= p->ch[1];
		}p->g.push_back(c[i]);
	}p->ch[1]= null;
	p->mt();
	return o;
}
void reverse(int x,int y){
	node *p1,*p2,*mid,*right;
	x--;
	location(head,x,p1,x);
	split(p1,x,mid);
	location(mid,y,p2,y);
	split(p2,y,right);
	while (mid!=null){
		mid->flip^= 1;
		swap(mid->ch[1],mid->ch[0]);
		mid= mid->ch[0];
	}
	head= merge(merge(head,p2),right);
}
void insert(int x,int y){
	node *mid,*right,*p;
	mid= build(y);
	location(head,x,p,x);
	split(p,x,right);
	head= merge(merge(head,mid),right);
}
void del(int x,int y){
	node *p,*mid,*right;
	x--;
	location(head,x,p,x);
	split(p,x,mid);
	location(mid,y,p,y);
	split(p,y,right);
	while (mid!=null){
		node *q= stack[++top]= mid;
		mid =mid->ch[1];
		q->clear();
	}
	merge(head,right);
}
void same(int x,int y,int z){
	node *p,*mid,*right;
	x--;
	location(head,x,p,x);
	split(p,x,mid);
	location(mid,y,p,y);
	split(p,y,right);
	p= mid;
	while (p!=null){
		p->z= z;
		p= p->ch[1];
	}
	head= merge(merge(head,mid),right);
}
int sum(int x,int y){
	node *p,*mid,*right;
	int ans= 0;
	x--;
	location(head,x,p,x);
	split(p,x,mid);
	location(mid,y,p,y);
	split(p,y,right);
	p= mid;
	while (p!=null){
		if (p->z==-oo) ans+= p->sum;
		else ans+= p->z*p->g.size();
		p= p->ch[1];
	}
	head= merge(merge(head,mid),right);
	return ans;
}
int get(){
	node *p= head;int ans= -oo,sum= -oo,l,r;
	while (p!=null){
		if (!p->g.size()){p= p->ch[1];continue;}
		l= p->l;r= p->r;
		if (p->flip) swap(l,r);
		if (p->z==-oo){
			ans= max(ans,p->m);
			ans= max(ans,sum+l);
			sum= max(sum+p->sum,r);
			ans= max(ans,sum);
		}else {
			int len= p->g.size();
			if (p->z<0) ans= max(ans,p->z);
			else ans= max(ans,p->z*len);
			sum= max(sum+p->z*len,p->z*len);
			sum= max(sum,p->z);
		}p= p->ch[1];
	}
	return ans;
}
int gi(){
	char c= getchar();int re= 0,p= 1;
	while ((c<'0'||c>'9')&&c!='-') c= getchar();
	if (c=='-') p= -1,c= getchar();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= getchar();
	return re*p;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node();
	n= gi();m= gi();
	for (i= 1;i<=n;i++)
		c[i]= gi();
	head= build(n);
	for (int a1= 1;a1<=m;a1++){
		for (i= 1;i<=3;i++) ch= getchar();
		if (ch=='S'){
			while (ch!=' ')ch= getchar();
			x= gi();y= gi();if (!y) continue;
			for (i= 1;i<=y;i++)
				c[i]= gi();
			insert(x,y);
		}else if (ch=='L'){
			while (ch!=' ')ch= getchar();			
			x= gi();y= gi();if (!y) continue;
			del(x,y);
		}else if (ch=='K'){
			while (ch!=' ')ch= getchar();			
			x= gi();y= gi();z= gi();if (!y) continue;
			same(x,y,z);
		}else if (ch=='V'){
			while (ch!=' ')ch= getchar();			
			x= gi();y= gi();if (!y) continue;
			reverse(x,y);
		}else if (ch=='T'){
			while (ch!=' ')ch= getchar();			
			x= gi();y= gi();
			if (y){
				ans= sum(x,y);
				printf("%d\n",ans);	
			}else printf("0\n");
		}else {
			ans= get();
			printf("%d\n",ans);
			for (i= 1;i<=5;i++) ch= getchar();
		}
	}
	return 0;
}
