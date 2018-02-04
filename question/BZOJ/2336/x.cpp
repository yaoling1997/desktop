#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn= 50,oo= 1e7;
struct node{
	int a,b;
};
node A[maxn],B[maxn],C[maxn],a[maxn],b[maxn];
int n,x,y,z,i,ans= oo,Ta,Tb,Tc;
bool cmpa(node a,node b){
	return a.b>b.b||(a.b==b.b&&a.a<b.a);
}
bool cmpb(node a,node b){
	return a.a>b.a||(a.a==b.a&&a.b<b.b);
}
int random(int o){
	return rand()%o;
}
void get(){
	sort(a+1,a+Ta+1,cmpa);
	sort(b+1,b+Tb+1,cmpb);
	int t1= 0,t2= 0,ta,tb,i,j,temp,minans= oo,x1,x2,y1,y2;
	for (i= 1;i<=Ta;i++)
		t1+= a[i].a;
	for (i= 1;i<=Tb;i++)
		t2+= b[i].b;
	for (i= 1;i<=2000;i++){
		ta= t1,tb= t2;
		if (Ta){
			x1= random(Ta)+1;x2= random(Ta)+1;
			swap(a[x1],a[x2]);
		}
		if (Tb){
			y1= random(Tb)+1;y2= random(Tb)+1;
			swap(b[y1],b[y2]);
		}
		temp= 0;
		for (j= 1;j<=Ta;j++)
			temp+= a[j].a,tb= max(tb,temp)+a[j].b;
		temp= 0;
		for (j= 1;j<=Tb;j++)
			temp+= b[j].b,ta= max(ta,temp)+b[j].a;
		temp= max(ta,tb);
		if (temp>minans){
			if (Ta){
				swap(a[x1],a[x2]);
			}
			if (Tb){
				swap(b[y1],b[y2]);
			}
		}
		minans= min(minans,temp);ans= min(ans,minans);
	}
}
void dfs(int o){
	if (o>Tc){
		memcpy(a,A,sizeof(a));
		memcpy(b,B,sizeof(b));
		get();
	}else {
		A[++Ta]= C[o];
		dfs(o+1);
		Ta--;
		B[++Tb]= C[o];
		dfs(o+1);
		Tb--;
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 1;i<=n;i++){
		scanf("%d %d %d",&x, &y, &z);
		if (x==1){
			A[++Ta]= (node){y,z};
		}else if (x==2){
			B[++Tb]= (node){y,z};
		}else {
			C[++Tc]= (node){y,z};
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
