#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 4e5+10,oo= 1e6;
char s[maxn],t[maxn];
int X[maxn],Y[maxn],sa[maxn];
int rank[maxn],height[maxn],c[maxn];
int sta[maxn],stb[maxn];
int A[maxn],B[maxn];
ll ans,ca,cb,na,nb;
int ls,lt,i,la,lb,m,K;
void build(int m){
	int i;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=ls;i++) c[X[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= ls;i>0;i--) sa[c[X[i]]--]= i;
	for (int k= 1;k<=ls;k<<= 1){
		int p= 0;
		for (i= ls-k+1;i<=ls;i++) Y[++p]= i;
		for (i= 1;i<=ls;i++)
			if (sa[i]>k) Y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;
		for (i= 1;i<=ls;i++) c[X[i]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= ls;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
		for (i= 1;i<=ls;i++)
			swap(X[i],Y[i]);
		p= 1;
		X[sa[1]]= 1;
		for (i= 2;i<=ls;i++)
			if (Y[sa[i]]==Y[sa[i-1]]&&Y[sa[i]+k]==Y[sa[i-1]+k])
				X[sa[i]]= p;
			else X[sa[i]]= ++p;
		if (p==ls) return;
		m= p;
	}
}
void getHeight(){
	int i,k= 0;
	for (i= 1;i<=ls;i++){
		if (k) k--;
		int j= sa[rank[i]-1];
		while (s[i+k]==s[j+k]) k++;
		height[rank[i]]= k;
	}
}
void update(int *sta,int *A,int &la,ll &ca,int y){
	int x= 0;
	while (la>0&&y<=sta[la]){
		ca+= ((ll)y-sta[la])*A[la];
		x+= A[la];
		la--;
	}
	if (x){
		la++;
		sta[la]= y;
		A[la]= x;
	}	
}
void add(int *sta,int *A,int &la,ll &ca,ll &na){
	sta[++la]= oo;
	A[la]= 1;
	ca+= oo;
	na++;
}
void getAns(){
	ans= 0;
	la= lb= ca= cb= na= nb= 0;
	for (i= 1;i<=ls;i++){
		if (height[i]<K)
			la= lb= ca= cb= na= nb= 0;
		else {
			update(sta,A,la,ca,height[i]);
			update(stb,B,lb,cb,height[i]);
		}
		if (sa[i]<m){
			ans+= cb-nb*(K-1);
			add(sta,A,la,ca,na);
		}else if (sa[i]>m){
			ans+= ca-na*(K-1);
			add(stb,B,lb,cb,nb);
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while (scanf("%d",&K)>0){
		if (!K) break;
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		memset(X,0,sizeof(X));
		memset(Y,0,sizeof(Y));
		scanf("%s%s",s+1,t+1);
		ls= strlen(s+1);
		lt= strlen(t+1);
		s[++ls]= '#';
		m= ls;
		for (i= 1;i<=lt;i++)
			s[++ls]= t[i];
		for (i= 1;i<=ls;i++)
			X[i]= s[i];
		build(300);
		for (i= 1;i<=ls;i++)
			rank[i]= X[i];
		getHeight();
		getAns();
		printf("%I64d\n",ans);
	}return 0;
}
