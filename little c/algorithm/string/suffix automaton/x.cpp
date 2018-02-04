#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 3001,sig= 30;
struct node{
	node *par,*ch[sig];
	int v;
	node(int x):
		par(0),v(x){memset(ch,0,sizeof(ch));}
};
node *root,*last;
char s[maxn];
int len;
void extend(int x){
	node *p= last,*np= new node(p->v+1);
	while (p && !p->ch[x]){
		p->ch[x]= np;p= p->par;
	}
	if (!p)
		np->par= root;
	else {
		node *q= p->ch[x];
		if (q->v==p->v+1)
			np->par= q;
		else {
			node *nq= new node(p->v+1);
			memcpy(nq->ch,q->ch,sizeof(q->ch));
			nq->par= q->par;
			q->par= nq;
			np->par= nq;
			while (p && p->ch[x]==q){
				p->ch[x]= nq;p= p->par;
			}
		}
	}
	last= np;
}
int idx(char c){return c-'a';}
void build(char *s){
	root= last= new node(0);
	for (int i= 1;i<=len;i++)
		extend(idx(s[i]));
}
int main()
{
	scanf("%s",s+1);
	len= strlen(s+1);
	build(s);
	return 0;
}
