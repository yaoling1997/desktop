#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e5,maxl= 2e2;
char p[maxn];
int s[maxn],height[maxn],rank[maxn],sta[maxn];
int X[maxn],Y[maxn],sa[maxn],c[maxn],b[maxl],Z[maxn];
int len,lp,i,j,n,tot,beg,la,T;
void init(){
	len= 0;
	tot= 300;
	memset(s,0,sizeof(s));
}
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
		p= 1;
		X[sa[1]]= 1;
		for (i= 2;i<=len;i++)
			if (Y[sa[i]]==Y[sa[i-1]]&&Y[sa[i]+k]==Y[sa[i-1]+k])
				X[sa[i]]= p;
			else X[sa[i]]= ++p;
		if (p==len) break;
		m= p;
	}
}
void getHeight(){
	int i,k= 0;
	for (i= 1;i<=len;i++){
		if (k) k--;
		int j= sa[rank[i]-1];
		while (s[j+k]==s[i+k]) k++;
		height[rank[i]]= k;
	}		
}
bool ok(int m){
	memset(b,0,sizeof(b));
	la= 0;
	int i,now,tim= 1;
	now= 1;
	beg= sa[1];
	b[Z[sa[1]]]= 1;
	for (i= 2;i<=len;i++)
		if (height[i]>=m){
			if (b[Z[sa[i]]]==tim) continue;
			b[Z[sa[i]]]= tim;
			now++;
		}else {
			if (now>n/2)
				sta[++la]= beg;			
			now= 1;
			beg= sa[i];
			b[Z[sa[i]]]= ++tim;
		}
	if (now>n/2)
		sta[++la]= beg;				
	return la;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&n)>0){
		if (!n) break;
		T++;
		if (T>1) printf("\n");
		init();
		for (i= 1;i<=n;i++){
			scanf("%s",p+1);
			lp= strlen(p+1);
			for (j= 1;j<=lp;j++){
				s[++len]= p[j];
				Z[len]= i;
			}
			s[++len]= ++tot;
		}
		if (n==1){
			printf("%s\n", p+1);
			continue;
		}		
		for (i= 1;i<=len;i++)
			X[i]= s[i]-'a'+1;
		build(tot);
		for (i= 1;i<=len;i++)
			rank[i]= X[i];
		getHeight();
		int l= 0,r= len;
		while (l+1<r){
			int m= (l+r)>>1;
			if (ok(m)) l= m;
			else r= m;
		}
		if (l){
			ok(l);
			for (i= 1;i<=la;i++){
				for (j= 1;j<=l;j++)
					printf("%c",(char)s[sta[i]+j-1]);
				printf("\n");
			}
		}else printf("?\n");
	}return 0;
}
