#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll a,b;
	cin>>a>>b;
	vector<vector<ll>>dp(a+1,vector<ll>(b+1,1e9));
	dp[1][1]=0;
	
	for(ll i=1;i<=a;i++){
		for(ll j=1;j<=b;j++){
			
			if(i==j)
				dp[i][j]=0;
			else{
				for(ll k=1;k<=(i/2);k++){
					dp[i][j]=min(dp[i-k][j]+dp[k][j]+1,dp[i][j]);
				}
				for(ll k=1;k<=(j/2);k++){
					dp[i][j]=min(dp[i][j-k]+dp[i][k]+1,dp[i][j]);
				}
			}
		}
	}
	cout<<dp[a][b]<<"\n";
	return 0;
}