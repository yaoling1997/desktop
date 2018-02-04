#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 3e3;
struct node *null;
struct node{
	node *h,*n;
	int v,c;
	node(int x= 0):v(0),c(x){
		h= n= null;
	}
};
node *r1,*r2,*now,*p,*n1,*n2;
char s[maxn],t[maxn];
int X[maxn],Y[maxn];
int ls,lt,ans,i,j,x,y,z,M;
node *get(node *o,int c){
	for (node *p= o->h;p!=null;p= p->n){
		if (p->c==c) return p;
	}return null;
}
int idx(char c){
	return c-'a';
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	null= new node();
	r1= new node();
	r2= new node();	
	scanf("%s%s",s+1, t+1);
	ls= strlen(s+1);
	lt= strlen(t+1);
	for (i= 1;i<=ls;i++){
		now= r1;
		for (j= i;j<=ls;j++){
			int c= idx(s[j]);
			p= get(now,c);
			if (p==null){
				p= new node(c);
				p->n= now->h;
				now->h= p;
				now= p;
				now->v= i;				
			}else now= p;
		}
	}
	for (i= ls;i>0;i--){
		now= r2;
		for (j= i;j>0;j--){
			int c= idx(s[j]);
			p= get(now,c);
			if (p==null){
				p= new node(c);
				p->n= now->h;
				now->h= p;
				now= p;				
				now->v= i;						
			}else now= p;
		}
	}
	for (i= 1;i<=lt;i+=M){
		M= 0;
		n1= r1;
		n2= r2;
		int b1= 1,b2= 1,p1= 0,p2= 0;
		for (j= i;j<=lt;j++){
			int c= idx(t[j]);			
			if (n1!=null) n1= get(n1,c);
			if (n2!=null) n2= get(n2,c);
			if (n1==null&&n2==null) break;
			if (n1==null) b1= 0;
			if (n2==null) b2= 0;
			p1= n1->v;
			p2= n2->v;
			M++;
		}
		if (M==0){
			printf("-1");
			return 0;
		}
		ans++;
		if (b1&&p1) X[ans]= p1,Y[ans]= p1+M-1;
		else X[ans]= p2,Y[ans]= p2-M+1;
	}
	printf("%d\n",ans);
	for (i= 1;i<=ans;i++)
		printf("%d %d\n",X[i], Y[i]);
	return 0;
}
