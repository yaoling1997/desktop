#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 3e5;
char s[maxn];
char t[20000],st[20000];
int X[maxn],Y[maxn],c[maxn],sa[maxn],rank[maxn];
int height[maxn],vis[20],Max[20],Min[20],h[maxn];
int n,T,i,j,len,start,tim;
void init(){
	memset(X,0,sizeof(X));
	memset(Y,0,sizeof(Y));
	memset(s,0,sizeof(s));
	memset(h,0,sizeof(h));
	len= 0;
	start= 0;
}
void deal(char *t){
	int lt= strlen(t+1),i,x= 0;
	for (i= 1;i<=lt;i++){
		if (t[i]==' ') continue;
		st[++x]= t[i];
	}
	for (i= 1;i<=x;i++) t[i]= st[i];
	t[x+1]= 0;
}
void build(int m){
	int i;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=len;i++) c[X[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= len;i>0;i--) sa[c[X[i]]--]= i;
	for (int k= 1;k<=len;k++){
		int p= 0;
		for (i= len-k+1;i<=len;i++) Y[++p]= i;
		for (i= 1;i<=len;i++)
			if (sa[i]>k) Y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;
		for (i= 1;i<=len;i++) c[X[i]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= len;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
		for (i= 1;i<=len;i++) swap(X[i],Y[i]);
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
		while (s[i+k]==s[j+k]) k++;
		height[rank[i]]= k;
	}		
}
bool ok(int m){
	int i,j,k,cnt= 0;
	for (i= 1;i<=len;i= j){
		j= i+1;
		while (j<=len&&height[j]>=m) j++;
		tim++;
		cnt= 0;
		for (k= i;k<j;k++){
			if (!h[sa[k]]) continue;
			if (vis[h[sa[k]]]!=tim){
				vis[h[sa[k]]]= tim;
				Max[h[sa[k]]]= Min[h[sa[k]]]= sa[k];
				cnt++;
			}else {
				Max[h[sa[k]]]= max(Max[h[sa[k]]],sa[k]);
				Min[h[sa[k]]]= min(Min[h[sa[k]]],sa[k]);
			}
		}
		if (cnt<n) continue;
		int bl= 1;
		for (k= 1;k<=n;k++)
			if (Max[k]-Min[k]<m){
				bl= 0;
				break;
			}
		if (bl) return 1;
	}return 0;
}
int main()
{
	//freopen("2.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int tt= 1;tt<=T;tt++){
		scanf("%d\n",&n);
		init();
		for (i= 1;i<=n;i++){
			gets(t+1);
			deal(t);
			int lt= strlen(t+1);
			for (j= 1;j<=lt;j++){
				s[++len]= t[j];
				h[len]= i;
			}
			s[++len]= start+'A';
			start++;
		}
		for (i= 1;i<=len;i++)
			X[i]= s[i];
		build(300);
		for (i= 1;i<=len;i++)
			rank[i]= X[i];
		getHeight();
		int l= 0,r= 10010;
		while (l+1<r){
			int m= (l+r)>>1;
			if (ok(m)) l= m;
			else r= m;
		}
		printf("%d\n",l);
	}return 0;
}
