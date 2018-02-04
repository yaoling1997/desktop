#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn= 3001,sig= 30;
char s[maxn],st[maxn];
int len;
struct node{
	node *par,*ch[sig+1];
	int val,z;
	node(int x):
		par(0),val(x),z(sig){
		memset(ch,0,sizeof(ch));
	}
};
node *root,*last;
void extend(int x){
	node *p= last;
	node *np= new node (p->val+1);
	while (p && !p->ch[x]){
		p->ch[x]= np;
		if (x < p->z) p->z= x;
		p= p->par;
	}
	if (!p)	np->par= root;
	else {
		node *q= p->ch[x];
		if (q->val==p->val+1)
			np->par= q;
		else {
			node *nq= new node(p->val+1);
			memcpy(nq->ch,q->ch,sizeof(q->ch));
			nq->z= q->z;
			nq->par= q->par;
			q->par= nq;
			np->par= nq;
			while (p && p->ch[x]==q){
				p->ch[x]= nq;
				if (x < p->z) p->z= x;
				p= p->par;
			}
		}
	}
	last= np;
}
int idx(char c){return c-'a';}
int udx(int c){return c+'a';}
void build(char *s){
	root= last= new node(0);
	for (int i= 1;i<=len;i++)
		extend(idx(s[i]));
}
void find(node *h){
	int s= 0;
	while (s!=len/2){
		s++;
		int z= h->z;
		printf("%c",udx(z));
		h= h->ch[z];
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	len= strlen(s+1);
	for (int i= 1;i<=2*len;i++)
		st[i]= s[(i-1)%len+1];
	len+= len;
	build(st);
	find(root);
	return 0;
}
