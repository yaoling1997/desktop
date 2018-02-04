#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<complex>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const double PI= acos(-1),eps= 1e-8;
const int maxn= 1e6+10;
typedef complex<double> CD;
vector<double> a,b;
double ans,s;
int num[maxn],l[maxn];
int n,m,i,x,T,M;
void FFT(vector<CD> &a,bool inv){
	int n= a.size(),i,j,k,step,Ek;
	for (i= j= 0;i<n;i++){
		if (j>i) swap(a[i],a[j]);
		k= n;
		while (j & (k>>= 1)) j&= ~k;
		j|= k;
	}
	double pi= inv ? -PI:PI;
	for (step= 1;step<n;step<<= 1){
		double alpha= pi/step;
		for (k= 0;k<step;k++){
			CD om= exp(CD(0,alpha*k));
			for (Ek= k;Ek<n;Ek+= step<<1){
				int Ok= Ek+step;
				CD t= om*a[Ok];
				a[Ok]= a[Ek]-t;
				a[Ek]+= t;
			}
		}
	}
	if (inv)
		for (i= 0;i<n;i++)
			a[i]/= n;
}
vector<double> operator *(vector<double> v1,vector<double> v2){
	int len1= v1.size(),len2= v2.size(),len= 2,i;
	while (len<len1+len2) len<<= 1;
	vector<CD> a(len,0),b(len,0);
	for (i= 0;i<len1;i++) a[i]= v1[i];
	for (i= 0;i<len2;i++) b[i]= v2[i];
	FFT(a,0);
	FFT(b,0);
	for (i= 0;i<len;i++) a[i]*= b[i];
	FFT(a,1);
	vector<double> res(len1+len2-1);
	for (i= 0;i<len1+len2-1;i++) res[i]= a[i].real();
	return res;
}
void init(){
	a.clear();
	M= ans= 0;
}
void look(){
	memset(l,0,sizeof(l));
	int len= a.size(),i;
	for (i= 0;i<len;i++)
		l[i]= a[i]+0.5;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);		
		init();
		for (i= 1;i<=n;i++){
			scanf("%d",&num[i]);
			M= max(M,num[i]);
		}
		if (n<3){
			printf("0.0000000\n");
			continue;
		}
		sort(num+1,num+n+1);
		for (i= 0;i<=M;i++)
			a.push_back(0);
		for (i= 1;i<=n;i++)
			a[num[i]]++;
		a= a*a;
		for (i= 1;i<=n;i++)
			a[num[i]+num[i]]--;
		M= a.size()-1;
		for (i= 0;i<=M;i++)
			a[i]/= 2;
		for (i= 1;i<=M;i++)
			a[i]+= a[i-1];
		for (i= 1;i<=n;i++){
			s= a[M]-a[num[i]];
			s-= (double)(n-i)*i;
			s-= i-1;
			s-= (double)(n-i)*(n-i-1)/2;
			ans+= s;
		}
		ans= ans/((double)n*(n-1)*(n-2))*6;
		if (fabs(ans)<eps) ans= 0;
		printf("%.7lf\n",ans);
	}
	return 0;
}
