#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<complex>
#include<cmath>
#include<vector>
using namespace std;
const double PI= acos(-1),eps= 1e-8;
typedef complex<double> CD;
vector<double> a,b;
int n,m,i,x;
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
vector<double> operator *(vector<double> &v1,vector<double> &v2){
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
	scanf("%d %d",&n, &m);
	for (i= 0;i<n;i++){
		scanf("%d",&x);
		a.push_back(x);
	}
	for (i= 0;i<m;i++){
		scanf("%d",&x);
		b.push_back(x);
	}
	a= a*b;
	for (i= 0;i<a.size();i++)
		printf("%.0lf ",a[i]);
	return 0;
}
