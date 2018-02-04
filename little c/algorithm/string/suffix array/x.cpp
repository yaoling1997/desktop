#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 3001;
char s[maxn],st[maxn];
int c[maxn],X[maxn],sa[maxn],Y[maxn];
int n,m,len,i;
void build(int m){
	int i;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=len;i++) c[X[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= len;i>0;i--) sa[c[X[i]]--]= i;
	for (int k= 1;k<=len;k<<= 1){
		int p= 0;
		for (i= len-k+1;i<=len;i++) Y[++p]= i;
		for (i= 1;i<=len;i++)
			if (sa[i]>k)
				Y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;		
		for (i= 1;i<=len;i++) c[X[i]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= len;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
		swap(X,Y);
		p= 1;X[sa[1]]= 1;
		for (i= 2;i<=len;i++)
			if (Y[sa[i-1]]==Y[sa[i]] && Y[sa[i-1]+k]==Y[sa[i]+k])
				X[sa[i]]= p;
			else X[sa[i]]= ++p;
		if (p==len) break;
		m= p;
	}
}
int com(char *p,int mid){
	return strncmp(p+1,st+sa[mid],strlen(p+1));
}
int find(char* s){
	if (com(s,1)<0) return 0;
	if (com(s,len)>0) return 0;
	int l= 1,r= len;
	while (l<=r){
		int mid= (l+r)>>1;
		int rt= com(s,mid);
		if (!rt) return 1;
		if (rt<0) r= mid-1;
		if (rt>0) l= mid+1;
	}
	return 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",st+1);
	len= strlen(st+1);
	for (i= 1;i<=len;i++)
		X[i]= st[i]-'a'+1;
	build(28);
	scanf("%d",&m);
	for (i= 1;i<=m;i++){
		scanf("%s",s+1);
		int ans= find(s);
		if (ans==1) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
