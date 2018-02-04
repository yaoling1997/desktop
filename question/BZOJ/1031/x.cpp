#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn= 300001,sig= 256;
char s[maxn],t[maxn];
int sa[maxn],X[maxn],Y[maxn],c[maxn];
int len,i,j,tot;
void build(int m){
	int i,k;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=2*len;i++) c[X[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= 2*len;i>0;i--) sa[c[X[i]]--]= i;
	for (k= 1;k<=2*len;k<<= 1){
		int p= 0;
		for (i= 2*len-k+1;i<=2*len;i++) Y[++p]= i;
		for (i= 1;i<=2*len;i++) if (sa[i]>k) Y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;
		for (i= 1;i<=2*len;i++) c[X[Y[i]]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= 2*len;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
		swap(X,Y);
		X[sa[1]]= p= 1;
		for (i= 2;i<=2*len;i++)
			if (Y[sa[i-1]]==Y[sa[i]]&&Y[sa[i-1]+k]==Y[sa[i]+k])
				X[sa[i]]= p;
			else X[sa[i]]= ++p;
		if (p==2*len) return;
		m= p;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	gets(s+1);
	len= strlen(s+1);
	for (i= len+1;i<=2*len;i++)
		s[i]= s[i-len];
	for (i= 1;i<=2*len;i++) X[i]= s[i];
	build(sig);
	for (i= 1;i<=2*len;i++)
		if (sa[i]<=len)
			t[++tot]= s[sa[i]+len-1];
	printf("%s",t+1);
	return 0;
}
