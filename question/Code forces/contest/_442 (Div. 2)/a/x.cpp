#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<string>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
string S,a;
char s[maxn];
int cnt;
void solve(string a){
	int la= a.size();
	for (int i= 0;i+la<=S.size();i++){
		bool bl= true;
		for (int j= 0;j<la;j++)
			if (s[i+j]!=a[j]){
				bl= false;
				break;
			}
		if (bl)
			cnt++;
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s",s);
	int len= strlen(s);
	for (int i= 0;i<len;i++)
		S.push_back(s[i]);
	a= "Danil";
	solve(a);
	a= "Olya";
	solve(a);
	a= "Slava";
	solve(a);
	a= "Ann";
	solve(a);
	a= "Nikita";
	solve(a);
	printf("%s",cnt==1?"YES":"NO");
	return 0;
}
