#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn= 20001;
int f[maxn];
char c;
int x,y,m,n,i;
int findRoot(int o){
	while (o!=f[o]) o= f[o];
	return o;
}
void makeRoot(int u){
	int v= f[u],t;f[u]= u;
	while (u!=v){
		t= f[v];f[v]= u;
		u= v;v= t;
	}
}
void connect(int x,int y){
	makeRoot(x);
	makeRoot(y);
	f[x]= y;
}
void destroy(int x,int y){
	makeRoot(x);
	f[y]= y;
}
void query(int x,int y){
	if (findRoot(x)==findRoot(y))
		printf("Yes\n");
	else printf("No\n");
}
void init(int n){
	for (int i= 1;i<=n;i++)
		f[i]= i;
}
int getint(){
	char c= getchar();int re= 0;
	while (c<'0'||c>'9') c= getchar();
	while (c>='0'&&c<='9') re= re*10+c-'0',c= getchar();
	return re;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n= getint();m= getint();
	init(n);
	for (int a1= 1;a1<=m;a1++){
		scanf("%c",&c);
		if (c=='C'){
			for (i= 1;i<=6;i++) scanf("%c",&c);
			x= getint();y= getint();
			connect(x,y);
		}
		else if (c=='D'){
			for (i= 1;i<=6;i++) scanf("%c",&c);
			x= getint();y= getint();
			destroy(x,y);
		}
		else {
			for (i= 1;i<=4;i++) scanf("%c",&c);
			x= getint();y= getint();			
			query(x,y);
		}
	}
	return 0;
}
