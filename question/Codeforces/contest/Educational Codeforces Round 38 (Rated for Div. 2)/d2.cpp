#include<bits/stdc++.h>
using namespace std;
long long a,s,d[200002],f[200002],g,h,j,k,l,i,n,m;
vector<pair<long long,long long> > v[200002];
priority_queue<pair<long long,long long> > q;

main(){
#ifndef ONLINE_JUDGE	
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
#endif	
    cin>>n>>m;
    for(i=0;i<m;i++){
        scanf("%I64d%I64d%I64d",&a,&s,&h);
        v[a].push_back({s,h});
        v[s].push_back({a,h});
    }

    for(i=1;i<=n;i++){
        scanf("%I64d",&d[i]);
        q.push({-d[i],i});
    }

    while(q.size()){
        k=-q.top().first;
        l=q.top().second;
        q.pop();
        if(f[l]) continue;
        f[l]=k;
        for(auto it:v[l]){
            q.push({-k-2*it.second,it.first});
        }
    }

    for(i=1;i<=n;i++){
			printf("%I64d%c",f[i],i<n?' ':'\n');
    }
}
