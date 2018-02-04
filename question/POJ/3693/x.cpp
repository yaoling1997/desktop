#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#define ll long long
#define ld long double
using namespace std;
const double eps= 1e-8;
const int maxn= 3e5,M= 17;
char s[maxn],ans[maxn];
int c[maxn],rank[maxn],sta[maxn],d[20];
int X[maxn],Y[maxn],sa[maxn],height[maxn],f[maxn][20];
int n,i,T,cnt,len,p,la;
void init(){
	cnt= 0;
	memset(X,0,sizeof(X));
	memset(Y,0,sizeof(Y));
	memset(f,0,sizeof(f));
}
void build(int m,int *X,int *Y,int *sa){
	int i;
	for (i= 0;i<=m;i++) c[i]= 0;
	for (i= 1;i<=n;i++) c[X[i]]++;
	for (i= 1;i<=m;i++) c[i]+= c[i-1];
	for (i= n;i>0;i--) sa[c[X[i]]--]= i;
	for (int k= 1;k<=n;k<<= 1){
		int p= 0;
		for (i= n-k+1;i<=n;i++)
			Y[++p]= i;
		for (i= 1;i<=n;i++)
			if (sa[i]>k) Y[++p]= sa[i]-k;
		for (i= 0;i<=m;i++) c[i]= 0;
		for (i= 1;i<=n;i++) c[X[i]]++;
		for (i= 1;i<=m;i++) c[i]+= c[i-1];
		for (i= n;i>0;i--) sa[c[X[Y[i]]]--]= Y[i];
		for (i= 1;i<=n;i++)
			swap(X[i],Y[i]);
		p= 1;
		X[sa[1]]= 1;
		for (i= 2;i<=n;i++)
			if (Y[sa[i]]==Y[sa[i-1]]&&Y[sa[i]+k]==Y[sa[i-1]+k])
				X[sa[i]]= p;
			else X[sa[i]]= ++p;
		if (p==n) break;
		m= p;
	}
}
void getHeight(char *s,int *sa,int *rank,int *height){
	int i,k= 0;
	for (i= 1;i<=n;i++){
		if (k) k--;
		int j= sa[rank[i]-1];
		while (s[i+k]==s[j+k]) k++;
		height[rank[i]]= k;
	}
}
void get(char *s,int *X,int *Y,int *sa,int *height,int *rank,int f[][20]){
	int i,j;
	for (i= 1;i<=n;i++)
		X[i]= s[i];
	build(300,X,Y,sa);
	for (i= 1;i<=n;i++)
		rank[i]= X[i];
	getHeight(s,sa,rank,height);
	for (i= 1;i<=n;i++){
		f[i][0]= n-sa[i]+1;
		f[i][1]= height[i+1];
	}
	for (i= 2;i<=M;i++)
		for (j= 1;j<=n;j++){
			f[j][i]= min(f[j][i-1],f[j+d[i-1]][i-1]);
			f[j][i]= min(f[j][i],height[j+d[i-1]]);
		}
}
int lcp(int x,int y){
	if (x>n||y>n) return 0;
	x= rank[x];
	y= rank[y];
	if (x>y) swap(x,y);
	double L= log(y-x+1)/log(2);
	int i= L+eps;
	return min(f[x][i],f[y-d[i]+1][i]);
}
void getAns(){
	int i,j,k,m= 0,x,y;
	cnt= 1;
	sta[la= 1]= 1;
	for (i= 1;i<=n;i++){
		k= i+1;
		while (k<=n){
			j= k-i;
			if (s[k]==s[j]){
				x= lcp(k,j);
				y= x/i+1;
				x%= i;
				x= i-x;
				if (j-x>0&&lcp(j-x,k-x)>=x) y++;
				if (y==1);
				else {
					if (y>cnt){
						cnt= y;
						sta[la= 1]= i;
					}else if (y==cnt){
						if (sta[la]==i);
						else sta[++la]= i;
					}
				}
			}
			k+= i;
		}
	}
	if (cnt==1){
		ans[1]= s[1];
		for (i= 2;i<=n;i++)
			ans[1]= min(ans[1],s[i]);
		m= 1;
	}else {
		p= 0;
		for (i= 1;i<=n;i++){
			for (j= 1;j<=la;j++){
				k= sta[j];
				if (lcp(sa[i],sa[i]+k)/k+1==cnt)
					goto pn;
			}
		}
	pn:for (p= sa[i];p<=sa[i]+cnt*k-1;p++)
			ans[++m]= s[p];
	}
	ans[m+1]= 0;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	d[0]= 1;
	int beginTime= clock();
	for (i= 1;i<=M;i++)
		d[i]= d[i-1]*2;
	while (scanf("%s",s+1)>0){
		if (s[1]=='#') break;
		init();
		T++;
		n= strlen(s+1);
		get(s,X,Y,sa,height,rank,f);
		getAns();
		printf("Case %d: %s\n",T, ans+1);
	}
	int endTime= clock();
	//printf("%.2lf",(endTime-beginTime)/1000.0);
	return 0;
}
