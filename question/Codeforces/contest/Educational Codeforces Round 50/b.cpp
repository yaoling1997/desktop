#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
ll n,m,k,ans;
int q;
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d",&q);
	for (int qq=1;qq<=q;qq++){
		ans=0;
		cin>>n>>m>>k;
		if (n>m)
			swap(n,m);
		if (k<m)
			ans=-1;
		else {
			ans+=m;
			k-=m;
			if (n%2==m%2){
				if (k&1){
					k--;
					ans--;
				}
				ans+=k;
			}else {
				ans+=k-1;
			}
		}
		cout<<ans<<endl;
	}
}
