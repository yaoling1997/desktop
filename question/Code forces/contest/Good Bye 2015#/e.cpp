#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#define ll long long
using namespace std;
const int maxn= 3e5,oo= 1e9;
//multiset<int> S;
struct node *null;
struct node{
	node *ch[2];
	int v,r,s;
	int cmp(int x){
		if (x==v) return -1;
		return x>v;
	}
	void clear(){r=rand();v= s= 0,ch[0]=ch[1]=null;}
	void mt(){s= ch[0]->s+ch[1]->s+1;}
	node (int x):v(x),r(rand()),s(0){ch[0]= ch[1]= null;}
};
node *S;
int t[maxn],A[10],b[maxn];
int ans,i,j,k,x,y,z,p,q,n,len,Max;
bool cmp(int a,int b){
	return a>b;
}
void rotate(node *&o,int d){
	node *k= o->ch[d^1];o->ch[d^1]= k->ch[d];k->ch[d]= o;
	o->mt();k->mt();o= k;
}
void insert(node *&o,int x){
	if (o==null) o= new node(x);
	else {
		int d= o->cmp(x);
		if (d==-1) d= 1;
		insert(o->ch[d],x);
		if (o->ch[d]->r > o->r) rotate(o,d^1);
	}
	o->mt();
}
void remove(node *&o,int x){
	if (o==null) return;
	int d= o->cmp(x);
	if (d==-1){
		if (o->ch[0]==null) o= o->ch[1];
		else if (o->ch[1]==null) o= o->ch[0];
		else {
			int d2= o->ch[0]->r > o->ch[1]->r;
			rotate(o,d2);remove(o->ch[d2],x);
		}
	}else remove(o->ch[d],x);
	if (o!=null) o->mt();
}
bool ok(node *o,int x,int &re){
	int bl= 0;
	re= -oo;
	while (o!=null){
		int d= o->cmp(x);
		if (d==-1||d==1){
			d= 1;
			re= max(o->v,re);
			bl= 1;
		}
		o= o->ch[d];
	}
	return bl;
}
int find(node *o,int x){
	while (o!=null){
		int d= o->cmp(x);
		if (d==-1) return 1;
		o= o->ch[d];
	}
	return 0;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	S= null= new node(0);
	for (i= 1;i<=3;i++)
		scanf("%d",&A[i]);
	for (i= 1;i<=n;i++){
		scanf("%d",&t[i]);
		insert(S,t[i]);
	}
	sort(A+1,A+3+1,cmp);
	sort(t+1,t+n+1,cmp);
	if (A[1]+A[2]+A[3]<t[1]){
		printf("-1");
		return 0;
	}
	p= 1;q= n;
	Max= max(A[1],A[2]+A[3]);
	while (p<=q){
		ans++;
		if (Max== A[2]+A[3]&&Max!=A[1]){
			if (t[p]>A[1]+A[2]){
				remove(S,t[p]);
				p++;
			}else if (t[p]>A[1]+A[3]){
				remove(S,t[p]);
				if (S!=null&&ok(S,A[3],x)){
					remove(S,x);
				}
			}else if (t[p]>A[2]+A[3]){
				remove(S,t[p]);
				if (S!=null&&ok(S,A[2],x))
					remove(S,x);
			}else if (t[p]>A[1]){
				remove(S,t[p]);			
				if (S!=null&&ok(S,A[1],x))
					remove(S,x);
			}else {
				if (S!=null&&ok(S,A[1],x))
					remove(S,x);
				int cnt= 0;
				if (S!=null&&ok(S,A[2],x)){
					cnt++;
				}
				if (S!=null&&ok(S,A[3],y)){
					cnt++;
				}
				if (cnt==2){
					remove(S,x);
					if (S!=null&&ok(S,A[3],x))
						remove(S,x);
				}else if (S!=null&&ok(S,A[2]+A[3],x))
						remove(S,x);
			}
			while (p<=q&&find(S,t[p])==0) p++;
			while (p<=q&&find(S,t[q])==0) q--;
		}else {
			if (t[p]>A[1]+A[2]){
				remove(S,t[p]);
				p++;
			}else if (t[p]>A[1]+A[3]){
				remove(S,t[p]);
				if (S!=null&&ok(S,A[3],x)){
					remove(S,x);
				}
			}else if (t[p]>A[1]){
				remove(S,t[p]);			
				if (S!=null&&ok(S,A[2],x))
					remove(S,x);
			}else if (t[p]>A[2]+A[3]){
				remove(S,t[p]);
				if (S!=null&&ok(S,A[2],x)&&ok(S,A[3],y)){
					remove(S,x);
					if (S!=null&&ok(S,A[3],y))					
						remove(S,y);
				}else if (S!=null&&ok(S,A[2]+A[3],x))
					remove(S,x);
			}else {
				if (S!=null&&ok(S,A[1],x))
					remove(S,x);
				int cnt= 0;
				if (S!=null&&ok(S,A[2],x)){
					cnt++;
				}
				if (S!=null&&ok(S,A[3],y)){
					cnt++;
				}
				if (cnt==2){
					remove(S,x);
					if (S!=null&&ok(S,A[3],x))
						remove(S,x);
				}else if (S!=null&&ok(S,A[2]+A[3],x))
						remove(S,x);
			}
			while (p<=q&&find(S,t[p])==0) p++;
			while (p<=q&&find(S,t[q])==0) q--;			
		}
	}
	printf("%d\n",ans);
	return 0;
}
