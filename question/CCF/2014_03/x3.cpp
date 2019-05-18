#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 1e3;
int b[maxn];
int vis[maxn];
string S[maxn];
char s[maxn];
int i,n;
void init(){
	for (int i= 'a';i<='z';i++){
		vis[i]= 0;
		S[i].clear();
	}
}
void solve(char *s){
	init();
	int i= 0;
	while (s[i]==' '&&s[i])
		i++;
	while (s[i]!=' '&&s[i])
		i++;
	while (s[i]){
		i++;
		if (s[i]!='-')
			break;
		i++;
		if (!b[s[i]])
			break;
		else if (b[s[i]]==1){
			vis[s[i]]= 1;
			i++;
			if (s[i]!=' ')
				break;
		}else {
			char c= s[i];
			i++;
			if (s[i]!=' ')
				break;
			i++;
			string x= "";
			while (s[i]&&s[i]!=' '){
				x.pb(s[i]);
				i++;
			}
			vis[c]= 1;
			S[c]= x;
		}
	}
	for (i= 'a';i<='z';i++)
		if (vis[i]){
			printf(" -%c",(char)i);
			if (b[i]==2){
				cout<<" "<<S[i];
			}
		}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	for (i= 1;s[i];i++)
		if (s[i+1]==':'){
			b[s[i]]= 2;
			i++;
		}else{
			b[s[i]]= 1;
		}
	scanf("%d\n",&n);
	for (i= 1;i<=n;i++){
		gets(s);
		printf("Case %d:",i);
		solve(s);
		printf("\n");
	}
	return 0;
}
