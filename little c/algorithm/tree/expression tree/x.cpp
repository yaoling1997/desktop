#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 3001;
char s[maxn],op[maxn];
int L[maxn],R[maxn];
int i,root,tot;
int build(int l,int r){
	int i,u,p= 0,c1,c2;
	c1= c2= -1;
	if (r-l==1){
		u= ++tot;
		L[u]= R[u]= 0;
		op[u]= s[l];
		return u;
	}
	for (i= l;i<r;i++){
		switch (s[i]){
		case '(':p++;break;
		case ')':p--;break;
		case '+':case '-':if (!p) c1= i;break;
		case '*':case '/':if (!p) c2= i;break;
		}
	}
	if (c1<0) c1= c2;
	if (c1<0) return build(l+1,r-1);
	u= ++tot;
	L[u]= build(l,c1-1);
	R[u]= build(c1+1,r);
	op[u]= s[u];
	return u;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	root= build(1,strlen(s+1)+1);
	return 0;
}
