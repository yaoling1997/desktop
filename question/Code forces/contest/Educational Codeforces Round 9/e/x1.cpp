#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<complex>
#include<cmath>
#include<vector>
using namespace std;
const double PI= acos(-1),eps= 1e-8;
const int maxn= 2000,maxm= 3e6;
typedef complex<double> CD;
CD _a[maxm],_b[maxm];
CD o;
int a[maxm],b[maxm];
double res[maxm];
int A[maxn];
int n,m,i,x,Max,k,cnt,len,la,lb;
void FFT(CD *a,int n,bool inv){
	int i,j,k,step,Ek;
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
void mul(int *v1,int &len1,int *v2,int &len2,int *v3,int &l3){
	while (len1&&v1[len1-1]==0) len1--;
	while (len2&&v2[len2-1]==0) len2--;
	int len= 2,i;
	while (len<len1+len2) len<<= 1;
	for (i= 0;i<len;i++) _a[i]= _b[i]= 0;
	for (i= 0;i<len1;i++) _a[i]= v1[i];
	for (i= 0;i<len2;i++) _b[i]= v2[i];
	FFT(_a,len,0);
	FFT(_b,len,0);
	for (i= 0;i<len;i++) _a[i]*= _b[i];
	FFT(_a,len,1);
	l3= len1+len2-1;
	for (i= 0;i<len1+len2-1;i++) v3[i]= min((int)(_a[i].real()+0.5),1);
}
void ksm(int k){
	while (k){
		if (k&1) mul(b,lb,a,la,b,lb);
		k>>= 1;
		if (k)
			mul(a,la,a,la,a,la);
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&n, &k);
	o= CD(0);
	for (i= 1;i<=n;i++){
		scanf("%d",&A[i]);
		Max= max(A[i],Max);
		a[A[i]]= 1;
	}
	la= Max+1;
	lb= 1;
	b[0]= 1;
	ksm(k);
	for (i= 1;i<lb;i++)
		if (b[i]>0){
			cnt++;
			if (cnt>1) printf(" ");
			printf("%d",i);
		}
	return 0;
}
