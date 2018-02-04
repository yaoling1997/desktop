#include<cstdio>
#include<cstdlib>
#include<complex>
#include<cmath>
#include<vector>
#include<cstring>
#define ld long double
using namespace std;
const ld PI= acos(0.0)*2.0;
const double eps= 1e-8;
typedef complex<double> CD;
vector<CD> a,b;
double x,y;
int n,m,i;
inline void FFT(vector<CD> &a,bool inv){
	int n= a.size(),i,j,k,step,Ek;
	for (i= 0,j= 0;i<n;i++){
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
	for (i= 0;i<n;i++)
		a[i]/= n;
}
inline vector<double> operator *(const vector<double> &v1,const vector<double> &v2){
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
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i= 0;i<n;i++){
		scanf("%lf %lf",&x, &y);
		a.push_back((CD){x,y});
	}
	FFT(a,0);
	for (i= 0;i<a.size();i++)
		printf("%.2lf %.2lf\n",a[i].real(),a[i].imag());
	return 0;
}
