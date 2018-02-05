#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn= 5e5;
typedef pair<int,int> PA;
PA a[maxn],oriSeg[maxn];
map<int,int> newRight;
int left[maxn],right[maxn],c[maxn];
PA ans= mp(1,0);
int n,k,tot,tNode;
int lowbit(int o){
	return o&-o;
}
void add(int o){
	tNode++;
	while (o<=tot){
		c[o]++;
		o+= lowbit(o);
	}
}
int find(int o){
	int re= 0;
	while (o>0){
		re+= c[o];
		o-= lowbit(o);
	}
	return re;
}
void updateAns(int left,int l,int r){
	r++;
	int look= newRight[right[l]];
	if (tNode-find(newRight[right[l]]-1)<k)
		return;
	while (l+1<r){
		int m= (l+r)>>1;
		look= newRight[right[m]];
		if (tNode-find(newRight[right[m]]-1)<k)
			r= m;
		else l= m;
	}
	if (ans.second-ans.first+1<right[l]-left+1)
		ans= mp(left,right[l]);
}
void solve(){
	sort(left+1,left+n+1);
	sort(right+1,right+n+1);
	int x= right[1];
	tot= 1;
	newRight[x]= tot;
	for (int i= 2;i<=n;i++)
		if (right[i]!=x){
			x= right[i];
			tot++;
			newRight[x]= tot;
		}
	int ap= 1,rp= 1;
	for (int i= 1;i<=n;i++){
		while (ap<=n&&a[ap].first<=left[i]){
			add(newRight[a[ap].second]);
			ap++;
		}
		while (right[rp]<left[i])
			rp++;
		updateAns(left[i],rp,n);
	}
}
int main()
{
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%d%d",&n, &k);
	for (int i= 1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x, &y);
		a[i]= oriSeg[i]=  mp(x,y);
		left[i]= x;
		right[i]= y;
	}
	sort(a+1,a+n+1);
	solve();
	int len= ans.second-ans.first+1;
	printf("%d\n",len);
	if (len==0){
		for (int i= 1;i<=k;i++)
			printf("%d%c",i,i<k?' ':'\n');
	}else {
		int sum= 0;
		for (int i= 1;i<=n;i++){
			if (oriSeg[i].first<=ans.first
					&&ans.second<=oriSeg[i].second){
				sum++;
				printf("%d%c",i,sum<k?' ':'\n');
				if (sum==k)
					break;
			}
		}
	}
	return 0;
}
