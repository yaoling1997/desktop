#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const ll maxn= 1e4;
struct node *null;
struct node{
	node *l,*r;
	char c;
	ll v;
	node():c(0),v(0){
		l= r= null;
	}
};
char s[maxn];
node *root,*now,*p;
ll n,cnt,i,j,len,ans;
void init(){
	cnt++;
	ans= 0;
	root= new node();
}
void dfs(node *o){
	ll sum= 0,re= 0;
	for (node *p= o->l;p!=null;p= p->r){
		sum+= p->v;
		dfs(p);
	}
	for (node *p= o->l;p!=null;p= p->r){
		re+= (sum-p->v)*p->v;
	}
	ans+= re/2;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	null= new node();
	while (scanf("%lld",&n)>0){
		if (!n) break;
		init();
		for (i= 1;i<=n;i++){
			scanf("%s",s+1);
			len= strlen(s+1);
			s[++len]= '#';
			now= root;
			for (j= 1;j<=len;j++){
				for (p= now->l;p!=null;p= p->r)
					if (p->c==s[j]) break;
				if (p!=null){
					ans+= p->v*2;
					p->v++;
				}else {
					p= new node();
					p->c= s[j];
					p->v= 1;
					p->r= now->l;
					now->l= p;
				}
				now= p;
			}
		}
		dfs(root);
		printf("Case %lld: %lld\n",cnt, ans);
	}return 0;
}
