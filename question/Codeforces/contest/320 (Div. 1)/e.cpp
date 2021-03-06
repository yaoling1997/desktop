#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn= 2e5;
struct node{
	char c;
	int h;
};
vector<vector<node> > a[10];
vector<node> b[10];
vector<node> A,ans;
int f[maxn],vis[maxn];
char s[maxn];
int i,j,k,x,y,n,cnt,K,num,len,L1,L2;
void get(int o){
	A.push_back((node){s[o],o});
	vis[o]= 1;
	while (o!=f[o]){
		vis[f[o]]= 1;
		A.push_back((node){s[f[o]],f[o]});
		o= f[o];
	}
}
int getnum(){
	int len= A.size();
	if (A[0].c=='L'){
		if (A[len-1].c=='L') return 0;
		else return 2;
	}else {
		if (A[len-1].c=='R') return 1;
		else return 3;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n= strlen(s+1);
	for (i= 1;i<=n;i++){
		j= max(j,i);
		k= max(k,i);
		f[i]= i;
		if (s[i]=='R'){
			while (j<=n&&s[j]=='R') j++;
			if (j<=n){
				f[i]= j;
				j++;
				cnt++;
			}
		}else {
			while (k<=n&&s[k]=='L') k++;
			if (k<=n){
				f[i]= k;
				k++;
				cnt++;
			}			
		}
	}
	for (i= 1;i<=n;i++){
		if (vis[i]) continue;
		A.clear();
		get(i);
		num= getnum();
		a[num].push_back(A);
	}
	for (i= 2;i<=3;i++){
		num= a[i].size();
		for (j= 0;j<num;j++){
			len= a[i][j].size();
			for (k= 0;k<len;k++)
				b[i].push_back(a[i][j][k]);
			L1= b[2].size();//
		}
	}
	L1= b[2].size();//	
	int l2= b[2].size(),l3= b[3].size(),bl= 0;
	if (l2) bl= 1;
	if (l2&&l3){
		if (b[2][l2-1].h>b[3][l3-1].h){
			b[3].push_back(b[2][l2-1]);
			b[2].pop_back();
		}else {
			b[2].push_back(b[3][l3-1]);
			b[3].pop_back();
		}
	}
	if (bl){
		l3= b[3].size();
		for (i= 0;i<l3;i++)
			b[2].push_back(b[3][i]);
	}
	int l0= a[0].size(),l1= a[1].size();
	while (l0&&l1){		
		len= a[0][l0-1].size();
		for (i= 0;i<len;i++)
			b[2].push_back(a[0][l0-1][i]);
		len= a[1][l1-1].size();
		for (i= 0;i<len;i++)
			b[2].push_back(a[1][l1-1][i]);
		l0--;
		l1--;
	}
	if (l0){
		len= b[2].size();
		for (i= 0;i<len;i++)
			ans.push_back(b[2][i]);
		len= a[0][0].size();
		for (i= 0;i<len;i++)
			ans.push_back(a[0][0][i]);
		if (!bl){
			len= b[3].size();
			for (i= 0;i<len;i++)
				ans.push_back(b[3][i]);
		}
	}else if (l1){
		if (!bl){
			len= b[3].size();
			for (i= 0;i<len;i++)
				ans.push_back(b[3][i]);
		}
		len= a[1][0].size();
		for (i= 0;i<len;i++)
			ans.push_back(a[1][0][i]);
		len= b[2].size();
		for (i= 0;i<len;i++)
			ans.push_back(b[2][i]);
	}else if (!bl){
		l2= b[2].size();l3= b[3].size();
		if (l2&&l3){
			if (b[2][l2-1].h>b[3][l3-1].h){
				b[3].push_back(b[2][l2-1]);
				b[2].pop_back();
			}else {
				b[2].push_back(b[3][l3-1]);
				b[3].pop_back();
			}			
		}
		len= b[2].size();
		for (i= 0;i<len;i++)
			ans.push_back(b[2][i]);
		len= b[3].size();
		for (i= 0;i<len;i++)
			ans.push_back(b[3][i]);
	}else {
		len= b[2].size();
		for (i= 0;i<len;i++)
			ans.push_back(b[2][i]);
	}
	K= n-cnt-1;
	printf("%d\n",K);
	len= ans.size();
	for (i= 0;i<len;i++)
		printf("%d%c",ans[i].h,i<len-1?' ':'\n');
	return 0;
}
