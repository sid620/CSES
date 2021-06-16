#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll i,n;
	cin>>n;
	vector<ll>a(n,0);
	vector<ll>dp(n+1,1e9+1);
	for(i=0;i<n;i++)
	cin>>a[i];
	dp[0]=-1;
	for(i=0;i<n;i++){
		ll j=upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
		if(dp[j-1]<a[i] && a[i]<dp[j])
			dp[j]=a[i];
	}
	ll ans=0;
	for(i=0;i<=n;i++)
		if(dp[i]<1e9)
			ans=i;
	cout<<ans<<"\n";
	return 0;
	
}