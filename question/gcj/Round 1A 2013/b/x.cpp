#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e4;
ll a[maxn],J[maxn];
ll v[maxn];
ll ans,E,R,n;
int i,la,T;
void init(){
	ans= 0;
	la= 0;
}
void update(){
	while (la>1&&a[la]>a[la-1]&&J[la]<E){
		if (J[la]+J[la-1]>E){
			ans+= (E-J[la])*(a[la]-a[la-1]);
			J[la]= E;			
			J[la-1]-= E-J[la];
		}else {
			ans+= J[la-1]*(a[la]-a[la-1]);
			J[la]+= J[la-1];
			la--;
			J[la]= J[la+1];
			a[la]= a[la+1];
		}
	}
}
void getAns(){
	int i;
	ll now= E;
	for (i= 1;i<=n;i++){
		a[++la]= v[i];
		J[la]= now;
		ans+= a[la]*now;		
		update();
		now= R;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		cin>>E>>R>>n;
		init();
		R= min(R,E);
		for (i= 1;i<=n;i++)
			cin>>v[i];
		getAns();
		printf("Case #%d: ",t);
		cout<<ans<<endl;
	}return 0;
}
