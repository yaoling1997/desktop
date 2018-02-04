#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
struct node{
	int p,q;
	bool operator <(const node &a)const{
		return p<a.p;
	}
};
char st[10];
node B[maxn],S[maxn],sta[maxn];
int n,s,i,j,lb,ls,x,y,cnt,num;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &s);
	for (i= 1;i<=n;i++){
		scanf("%s",st+1);
		if (st[1]=='B'){
			scanf("%d%d",&x, &y);
			B[++lb]= (node){x,y};
		}else {
			scanf("%d%d",&x, &y);
			S[++ls]= (node){x,y};			
		}
	}
	sort(B+1,B+lb+1);
	sort(S+1,S+ls+1);
	S[++ls]= (node){-1,0};
	B[0]= (node){-1,0};
	cnt= 0;
	num= S[1].q;
	for (i= 2;i<=ls;i++)
		if (S[i].p==S[i-1].p) num+= S[i].q;
		else {
			sta[++cnt]= (node){S[i-1].p,num};
			num= S[i].q;
			if (cnt==s) break;
		}
	for (i= cnt;i>0;i--)
		printf("S %d %d\n",sta[i].p, sta[i].q);	
	cnt= 0;
	num= B[lb].q;
	for (i= lb-1;i>=0;i--)
		if (B[i].p==B[i+1].p) num+= B[i].q;
		else {
			printf("B %d %d\n",B[i+1].p, num);
			cnt++;
			num= B[i].q;
			if (cnt==s) break;
		}
	return 0;
}
