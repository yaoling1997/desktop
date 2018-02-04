#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
const ll oo= 2e9,mo= 1e6;
struct node *null;
struct node{
	node *ch[2];
	ll v,r,s;
	ll cmp(ll x){
		if (x==v) return -1;
		return x>v;
	}
	void mt(){
		s= ch[0]->s+ch[1]->s+1;
	}
	node(ll x):v(x),r(rand()),s(0){ch[0]= ch[1]= null;}
};
node *root;
ll x,y,i,n,bl;
ll ans;
void rotate(node *&o,ll d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,ll x){
	if (o==null) o= new node(x);
	else {
		ll d= o->cmp(x);
		if (d==-1) d= 1;
		insert(o->ch[d],x);
		if (o->ch[d]->r > o->r) rotate(o,d^1);
	}o->mt();
}
void remove(node *&o,ll x){
	if (o==null) return;
	ll d= o->cmp(x);
	if (d==-1){
		if (o->ch[0]==null) o= o->ch[1];
		else if (o->ch[1]==null) o= o->ch[0];
		else {
			ll d2= o->ch[0]->r > o->ch[1]->r;
			rotate(o,d2);
			remove(o->ch[d2],x);
		}
	}else remove(o->ch[d],x);
	if (o!=null) o->mt();
}
ll find(node *o,ll x){
	ll re= -oo;
	while (o!=null){
		ll d= o->cmp(x);
		if (d==-1) return x;
		else if (abs(o->v-x)<abs(re-x)) re= o->v;
		else if (abs(o->v-x)==abs(re-x)&&re>o->v)
			re= o->v;
		o= o->ch[d];
	}return re;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	root= null= new node(0);
	scanf("%lld",&n);   
	bl= -1;
	for (ll a1= 1;a1<=n;a1++){
		scanf("%lld %lld",&x, &y);
		if (x==0){
			if (bl==-1){
				bl= 0;
				insert(root,y);
			}else if (bl==0) insert(root,y);
			else {
				x= find(root,y);
				ans+= abs(x-y);
				remove(root,x);
				if (root==null) bl= -1;
			}
		}else {
			if (bl==-1){
				bl= 1;
				insert(root,y);
			}else if (bl==1) insert(root,y);
			else {
				x= find(root,y);
				ans+= abs(x-y);
				remove(root,x);
				if (root==null) bl= -1;				
			}
		}
	}printf("%lld",ans%mo);
	return 0;
}
