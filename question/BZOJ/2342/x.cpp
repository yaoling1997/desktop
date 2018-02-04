#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int maxn= 6e6;
struct stu{
	int l,b;
};
set<int> X;
set<int> :: iterator it;
stu a[maxn];
char os[maxn],s[maxn];
int r[maxn];
int i,j,n,ans,id,mx,len,L;
bool cmp(stu a,stu b){return a.l<b.l;}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",os+1);
	for (i= 1;i<=n;i++){
		s[++len]= '#';
		s[++len]= os[i];
	}s[++len]= '#';
	s[len+1]= '?';
	for (i= 1;i<=len;i++){
		if (mx>i)
			r[i]= min(mx-i,r[2*id-i]);
		else r[i]= 1;
		while (s[i+r[i]]==s[i-r[i]]) r[i]++;
		if (i+r[i]-1>mx){
			mx= i+r[i]-1;
			id= i;
		}
		a[i].l= i-r[i]+1;
		a[i].b= i;
	}sort(a+1,a+len+1,cmp);
	j= 1;
	for (i= 1;i<=len;i++)
		if (i&1){
			while (a[j].l<=i&&j<=len){
				if (s[a[j].b]=='#')
					X.insert(a[j].b);
				j++;
			}
			if (X.empty())
				continue;
			it= X.upper_bound((i+i+r[i]-1)/2);
			L= X.size();			
			if (it!=X.begin())
				it--;			
			L= X.size();
			if (*it>i&&*it<=(i+i+r[i]-1)/2)
				ans= max(ans,(*it-i)*2);
		}
	if (ans<4) ans= 0;
	printf("%d\n",ans);
	return 0;
}
