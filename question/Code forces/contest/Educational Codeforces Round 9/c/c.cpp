#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int maxn= 6e4;
string s[maxn];
int n,i;
bool cmp(string a,string b){
	return a+b<b+a;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for (i= 1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+n+1,cmp);
	for (i= 1;i<=n;i++)
		cout<<s[i];
}
