#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
using namespace std;
const int maxn= 3e4;
string t;
char S[maxn][110],s[maxn][110],T[110];
int L[maxn],l[maxn],per[maxn];
int n,i,j,k,M,p;
char change(char c){
	if ('A'<=c&&c<='Z') c+= 32;
	return c;
}
bool is_bm(char *s){
	int i,j,len= strlen(s+1);
	for (i= 1;i<=len;i++)
		if (s[i]=='@') break;
	if (len-i!=M) return 0;
	for (j= i+1;j<=len;j++)
		if (s[j]!=T[j-i]) return 0;
	return 1;
}
bool cmp(int a,int b){
	int i,L= max(l[a],l[b]);
	for (i= 1;i<=L;i++){
		if (s[a][i]<s[b][i]) return 0;
		if (s[a][i]>s[b][i]) return 1;
	}
	return 0;
}
bool same(char *s,char *t){
	int ls= strlen(s+1);
	int lt= strlen(t+1);
	if (ls!=lt) return 0;
	for (int i= 1;i<=ls;i++)
		if (s[i]!=t[i]) return 0;
	return 1;
}
int main()
{
	t= "bmail.com";
	memcpy(T+1,t.c_str(),20);
	M= strlen(T+1);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		per[i]= i;
		scanf("%s",S[i]+1);
		L[i]= l[i]= strlen(S[i]+1);
		for (j= 1;j<=L[i];j++)
			s[i][j]= change(S[i][j]);
		if (is_bm(s[i])){
			t.clear();
			for (j= 1;j<=L[i];j++){
				if (s[i][j]=='.') continue;
				if (s[i][j]=='+') break;
				if (s[i][j]=='@') break;
				t.push_back(s[i][j]);
			}
			for (k= j;k<=L[i];k++)
				if (s[i][k]=='@') break;			
			for (j= k;j<=L[i];j++)
				t.push_back(s[i][j]);
			memcpy(s[i]+1,t.c_str(),101);
		}
	}
	sort(per+1,per+n+1,cmp);
	p= 1;int ans= 0;
	for (i= 2;i<=n;i++)
		if (!same(s[per[i-1]],s[per[i]]))
			ans++;
	ans++;
	printf("%d\n",ans);
	p= 1;
	for (i= 2;i<=n;i++){
		if (!same(s[per[i-1]],s[per[i]])){
			printf("%d ",i-p);
			for (j= p;j<i;j++)
				printf("%s%c",S[per[j]]+1,j<i-1?' ':'\n');
			p= i;
		}
	}
	printf("%d ",n-p+1);
	for (j= p;j<=n;j++)
		printf("%s%c",S[per[j]]+1,j<n?' ':'\n');
	return 0;
}
