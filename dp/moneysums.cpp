#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll t,i,n;
	ll count=0;
	cin>>n;
	vector<ll>a(n,0);
	ll sum=0;
	for(i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
	sort(a.begin(),a.end());
	for(ll i=0;i<n;i++)
	 dp[i][0]=true;
	 dp[0][a[0]]=true;
	for(i=1;i<n;i++)
		for(ll j=1;j<=sum;j++){
			if(j>=a[i])
				dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i]];
			else
				dp[i][j]=dp[i-1][j];
			if(i==n-1 && dp[i][j])
			count++;
			
		}
	if(n==1){
		count=1;
	}
	cout<<count<<"\n";
	for(i=1;i<=sum;i++)
		if(dp[n-1][i]){
		cout<<i<<" ";
		}
	cout<<"\n";
	//cout<<count<<endl;
	return 0;
}